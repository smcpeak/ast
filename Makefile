# ast/Makefile
# see license.txt for copyright and terms of use

# main targets
all: ccsstr.exe astgen.exe libast.a example.o ext1.o


# ------------------------- Configuration --------------------------
# directories of other software
SMBASE    = ../smbase
LIBSMBASE = $(SMBASE)/libsmbase.a

SMFLEXDIR = ../smflex
SMFLEX    = $(SMFLEXDIR)/smflex

# C++ compiler.
CXX = g++

# Flags to control generation of debug info.
DEBUG_FLAGS = -g

# Flags to enable dependency generation of .d files.
GENDEPS_FLAGS = -MMD

# Flags to control optimization.
OPTIMIZATION_FLAGS = -O2

# Flags to control compiler warnings.
WARNING_FLAGS =

# Flags for C++ standard to use.
CXX_STD_FLAGS = -std=c++11

# Preprocessing flags.
CPPFLAGS = -I$(SMBASE)

# Flags for the C++ compiler and preprocessor.
#
# Note: $(GENDEPS_FLAGS) are not included because these flags are used
# for linking too, and if that used $(GENDEPS_FLAGS) then the .d files
# for .o files would be overwritten with info for .exe files.
CXXFLAGS = $(DEBUG_FLAGS) $(OPTIMIZATION_FLAGS) $(WARNING_FLAGS) $(CXX_STD_FLAGS) $(CPPFLAGS)

# Libraries to link with when creating test executables.
LIBS = $(LIBSMBASE)

# Flags to add to a link command *in addition* to either $(CFLAGS) or
# $(CXXFLAGS), depending on whether C++ modules are included.
LDFLAGS =

# external tools
PERL   = perl
AR     = ar
RANLIB = ranlib


# ---- Automatic Configuration ----
# Pull in settings from ./configure.  They override the defaults above,
# and are in turn overridden by personal.mk, below.
ifeq ($(wildcard config.mk),)
  $(error The file 'config.mk' does not exist.  Run './configure' before 'make'.)
endif
include config.mk


# ---- Customization ----
# Allow customization of the above variables in a separate file.  Just
# create personal.mk with desired settings.
#
# Common things to set during development:
#
#   WERROR = -Werror
#   WARNING_FLAGS = -Wall $(WERROR)
#   OPTIMIZATION_FLAGS =
#
-include personal.mk


# ----------------------------- Rules ------------------------------
# Get rid of (some...) built-in rules.
.SUFFIXES:

# Compile .cc to .o, also generating dependency files.
%.o: %.cc
	$(CXX) -c -o $@ $(GENDEPS_FLAGS) $(CXXFLAGS) $<


# ---------------------- intermediate files -------------------
# Run bison.  I am currently using bison-3.0.4.
#
# This uses a pattern rule instead of a normal rule because pattern
# rules with multiple targets mean that a single rule creates multiple
# files, whereas a normal rule with multiple targets is shorthand for
# multiple independent rules, which breaks with parallel make.
#
# There is also the "&:" separator, but that was only added in GNU
# Make 4.3 (2020-01-19), which is too recent for me to depend on.
%.tab.cc %.tab.h %.codes.h: %.y
	bison -d -v $*.y
	@#
	@# I will be compiling the output as C++.
	@#
	mv -f $*.tab.c $*.tab.cc
	@#
	@# This extracts the declaration of "enum yytokentype" and
	@# puts it into agrampar.codes.h.  That way I can use the
	@# token codes in the lexer without also having to declare
	@# everything that is in the YYSTYPE union.
	@#
	sed -n -e '/enum yytokentype/,/};/p' < $*.tab.h > $*.codes.h

# Run smflex.
#
# TODO: I want to make $(SMFLEX) a dependency here, but when I do that,
# the rule stops working.  The problem is related to the .exe extension
# on Windows.  One thing I do not understand is why the exact same thing
# works in smflex/test.
%.yy.cc %.yy.h: %.lex
	$(SMFLEX) -o$*.yy.cc $*.lex


# ------------------------- ccsstr ---------------------
CCSSTR_OBJS := \
  reporterr.o \
  embedded.o
# No need to include .d files here because ASTGEN_OBJS contains CCSSTR_OBJS.

ccsstr.exe: ccsstr.cc ccsstr.h $(CCSSTR_OBJS) $(LIBS)
	$(CXX) -o $@ $(CXXFLAGS) -DTEST_CCSSTR $(LDFLAGS) ccsstr.cc $(CCSSTR_OBJS) $(LIBS)


# ------------------------- astgen ---------------------
ASTGEN_OBJS := \
  gramlex.o \
  agrampar.tab.o \
  ccsstr.o \
  agramlex.yy.o \
  reporterr.o \
  embedded.o \
  ast.hand.o \
  asthelp.o \
  xmlhelp.o \
  agrampar.o  \
  astgen.o
-include $(ASTGEN_OBJS:.o=.d)

# ast.ast.cc is a dependency here but not explicitly in the command
# line because ast.hand.cc #includes it
astgen.exe: $(ASTGEN_OBJS) ast.ast.cc $(LIBS)
	$(CXX) -o $@ $(CXXFLAGS) $(LDFLAGS) $(ASTGEN_OBJS) $(LIBS)

# Dependencies on generated headers.
agrampar.tab.o: ast.hand.h ast.ast.h agrampar.h
gramlex.o: agramlex.yy.h


# ---------------------- run astgen ----------------------
# simple ast spec file
example.cc: astgen.exe example.ast
	./astgen.exe example.ast

exampletest.exe: exampletest.o example.o asthelp.o locstr.o $(LIBS)
	$(CXX) -o $@ $(CXXFLAGS) $(LDFLAGS) $^

# simple extension
ext1.cc: astgen.exe example.ast ext1.ast
	./astgen.exe -oext1 example.ast ext1.ast

# If you want to regenerate astgen's own ast file, you do
#   ./astgen.exe -oast.ast ast.ast
#
# This rule is *not* in the Makefile because if you do it
# without thinking you can break the self-bootstrapping
# (and be forced to restore your ast.ast.{cc,h} from the
# distribution tarball or from CVS).


# ------------------------ libast.a -------------------
# this library is the set of support modules required for
# using astgen-generated code, or are simply useful generally
# but don't belong in smbase
LIB_OBJS := \
  gramlex.o \
  ccsstr.o \
  reporterr.o \
  embedded.o \
  asthelp.o \
  xmlhelp.o \
  locstr.o
-include $(ASTGEN_OBJS:.o=.d)

libast.a: $(LIB_OBJS)
	$(AR) -r $@ $(LIB_OBJS)
	-$(RANLIB) $@


# ------------------ documentation ------------------
gendoc:
	mkdir gendoc

gendoc/configure.txt: configure
	./configure --help >$@

gendoc/demo.h gendoc/demo.cc: demo.ast astgen.exe
	./astgen.exe -ogendoc/demo demo.ast

.PHONY: doc
doc: gendoc gendoc/configure.txt gendoc/demo.h
	@echo "built documentation"


# ------------------------ misc ---------------------
check: ccsstr.exe
	./ccsstr.exe

# delete outputs of compiler, linker
clean:
	rm -f *.o *.a *.exe *.d tmp gmon.out
	rm -f agrampar.output
	rm -f example.{h,cc} ext1.{h,cc}
	rm -f agramlex.yy.{h,cc}

# return to pristine checked-out state
distclean: clean
	rm -f config.mk
	rm -rf gendoc

# 'clean', plus remove distributed outputs of bison
toolclean: clean
	rm -f agrampar.tab.h
	rm -f agrampar.tab.cc
	rm -f agrampar.codes.h

# test for owner
#
# TODO: This target is broken.  What happened to owner.h?
towner.exe: owner.h towner.o
	$(CXX) -o $@ $(CXXFLAGS) towner.o $(LDFLAGS)

# EOF
