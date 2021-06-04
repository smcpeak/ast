/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 6 "agrampar.y"


#include "agrampar.h"       // agrampar_yylex, etc.

#include <stdlib.h>         // malloc, free
#include "sm-iostream.h"    // cout

// enable debugging the parser
#ifndef NDEBUG
  #define YYDEBUG 1
#endif

// permit having other parser's codes in the same program
#define yyparse agrampar_yyparse

// Arrange for the generated parser to invoke the right lexer.
#define yylex(lvalp) agrampar_yylex(lvalp, parseParam)
#define yyerror(param, msg) agrampar_yyerror(msg, param)


#line 91 "agrampar.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_AGRAMPAR_TAB_H_INCLUDED
# define YY_YY_AGRAMPAR_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOK_NAME = 258,
    TOK_INTLIT = 259,
    TOK_EMBEDDED_CODE = 260,
    TOK_LBRACE = 261,
    TOK_RBRACE = 262,
    TOK_SEMICOLON = 263,
    TOK_ARROW = 264,
    TOK_LPAREN = 265,
    TOK_RPAREN = 266,
    TOK_LANGLE = 267,
    TOK_RANGLE = 268,
    TOK_STAR = 269,
    TOK_AMPERSAND = 270,
    TOK_COMMA = 271,
    TOK_EQUALS = 272,
    TOK_COLON = 273,
    TOK_CLASS = 274,
    TOK_PUBLIC = 275,
    TOK_PRIVATE = 276,
    TOK_PROTECTED = 277,
    TOK_VERBATIM = 278,
    TOK_IMPL_VERBATIM = 279,
    TOK_CTOR = 280,
    TOK_DTOR = 281,
    TOK_PURE_VIRTUAL = 282,
    TOK_CUSTOM = 283,
    TOK_OPTION = 284,
    TOK_NEW = 285,
    TOK_ENUM = 286
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 76 "agrampar.y"

  ASTSpecFile *file;
  ASTList<ToplevelForm> *formList;
  TF_class *tfClass;
  ASTList<CtorArg> *ctorArgList;
  ASTList<Annotation> *userDeclList;
  string *str;
  enum AccessCtl accessCtl;
  AccessMod *accessMod;
  ToplevelForm *verbatim;
  Annotation *annotation;
  TF_option *tfOption;
  ASTList<string> *stringList;
  TF_enum *tfEnum;
  ASTList<string> *enumeratorList;
  string *enumerator;
  ASTList<BaseClass> *baseClassList;
  BaseClass *baseClass;
  CustomCode *customCode;

#line 196 "agrampar.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (ASTParseParams *parseParam);

#endif /* !YY_YY_AGRAMPAR_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   111

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  114

#define YYUNDEFTOK  2
#define YYMAXUTOK   286


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   123,   123,   129,   130,   131,   132,   133,   134,   135,
     140,   144,   152,   153,   165,   167,   175,   176,   178,   180,
     188,   189,   195,   197,   202,   209,   214,   216,   222,   223,
     224,   225,   226,   227,   228,   232,   234,   241,   242,   248,
     250,   252,   258,   264,   266,   272,   273,   274,   275,   276,
     277,   281,   283,   288,   290,   295,   297,   302,   308,   309,
     314,   316,   321,   323,   328,   334,   335,   340,   342,   348,
     349,   350,   354
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_NAME", "TOK_INTLIT",
  "TOK_EMBEDDED_CODE", "\"{\"", "\"}\"", "\";\"", "\"->\"", "\"(\"",
  "\")\"", "\"<\"", "\">\"", "\"*\"", "\"&\"", "\",\"", "\"=\"", "\":\"",
  "\"class\"", "\"public\"", "\"private\"", "\"protected\"",
  "\"verbatim\"", "\"impl_verbatim\"", "\"ctor\"", "\"dtor\"",
  "\"pure_virtual\"", "\"custom\"", "\"option\"", "\"new\"", "\"enum\"",
  "$accept", "StartSymbol", "Input", "Class", "NewOpt", "ClassBody",
  "ClassMembersOpt", "CtorArgsOpt", "CtorArgs", "CtorArgList", "Arg",
  "ArgWord", "ArgList", "CtorMembersOpt", "Annotation", "CustomCode",
  "Embedded", "Public", "AccessMod", "StringList", "Verbatim", "Option",
  "OptionArgs", "Enum", "EnumeratorSeq", "Enumerator", "BaseClassesOpt",
  "BaseClassSeq", "BaseAccess", "BaseClass", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286
};
# endif

#define YYPACT_NINF (-54)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-13)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -54,    12,     1,   -54,   -54,    13,    13,    23,    40,   -54,
      41,   -54,    66,   -54,   -54,   -54,   -54,    81,    85,   -54,
     -54,    13,   -54,    65,    88,   -54,    86,   -54,     3,    89,
      84,   -54,   -54,   -54,   -54,    -2,   -54,    46,    77,    84,
     -54,    52,   -54,   -54,   -54,    69,   -54,   -54,   -54,   -54,
      -3,    69,   -54,    48,    56,    77,   -54,   -54,    63,    83,
     -54,    69,   -54,   -54,   -54,   -54,    82,    94,   -54,   -54,
     -54,   -54,    56,    69,   -54,    69,    48,   -54,    14,   -54,
     -54,   -54,   -54,    96,   -54,   -54,   -54,   -54,   -54,   -54,
     -54,   -54,    90,    32,    84,    98,    -1,   -54,    77,   -54,
     -54,     6,    97,    68,   -54,   100,    99,   -54,   -54,   -54,
     -54,    26,   -54,   -54
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     2,     1,     9,     0,     0,     0,     0,    13,
       0,     4,     0,     8,     5,     6,     7,     0,     0,    55,
      56,     0,    58,     0,     0,    43,     0,    42,     0,     0,
      20,    44,    59,    57,    64,     0,    62,     0,    65,    21,
      60,     0,    28,    29,    22,     0,    31,    32,    33,    34,
       0,    24,    26,     0,     0,    65,    61,    63,    35,     0,
      23,     0,    27,    69,    70,    71,    66,     0,    67,    16,
      15,    10,     0,     0,    30,    25,     0,    72,     0,    11,
      36,    68,    14,     0,    45,    46,    47,    48,    49,    50,
      19,    41,    51,     0,    20,     0,     0,    39,    65,    21,
      53,     0,     0,     0,    52,     0,     0,    37,    17,    54,
      40,     0,    18,    38
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -54,   -54,   -54,   -54,   -54,    33,   -54,    10,   -38,   -54,
     -33,   -48,    35,   -54,    -5,   107,    -6,   -54,   -54,   -54,
     -54,   -54,   -54,   -54,   -54,    70,   -53,   -54,   -54,    34
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    11,    12,    71,    78,    38,    39,    50,
      58,    52,    59,   111,    90,    91,    19,    92,    93,   101,
      14,    15,    28,    16,    35,    36,    54,    66,    67,    68
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      20,    55,    72,    62,    51,    40,    32,    25,    60,     4,
      62,    33,     3,    61,    41,    27,   102,   104,    17,    18,
     -12,    82,   105,    83,     5,     6,    21,    62,    75,     7,
       8,     9,    10,   112,    84,    85,    86,    96,    18,    87,
      88,    89,     7,    22,    23,   103,    84,    85,    86,    42,
      43,    87,    88,    89,     7,    34,    99,    44,    45,    56,
      46,    47,    69,    48,    70,    49,    42,    43,    63,    64,
      65,    29,    42,    43,   107,    45,   108,    46,    47,    73,
      48,    45,    49,    46,    47,    24,    48,    97,    49,    25,
      26,    30,    34,    31,    37,    53,    74,    77,    76,    94,
      95,   100,   106,   109,    98,    79,   113,   110,    80,    13,
      81,    57
};

static const yytype_int8 yycheck[] =
{
       6,    39,    55,    51,    37,     7,     3,     8,    11,     8,
      58,     8,     0,    16,    16,    21,    17,    11,     5,     6,
      19,     7,    16,     9,    23,    24,     3,    75,    61,    28,
      29,    30,    31,     7,    20,    21,    22,     5,     6,    25,
      26,    27,    28,     3,     3,    98,    20,    21,    22,     3,
       4,    25,    26,    27,    28,     3,    94,    11,    12,     7,
      14,    15,     6,    17,     8,    19,     3,     4,    20,    21,
      22,     6,     3,     4,     6,    12,     8,    14,    15,    16,
      17,    12,    19,    14,    15,    19,    17,    93,    19,     8,
       5,     3,     3,     7,    10,    18,    13,     3,    16,     3,
      10,     3,     5,     3,    94,    72,   111,     8,    73,     2,
      76,    41
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    33,    34,     0,     8,    23,    24,    28,    29,    30,
      31,    35,    36,    47,    52,    53,    55,     5,     6,    48,
      48,     3,     3,     3,    19,     8,     5,    48,    54,     6,
       3,     7,     3,     8,     3,    56,    57,    10,    39,    40,
       7,    16,     3,     4,    11,    12,    14,    15,    17,    19,
      41,    42,    43,    18,    58,    40,     7,    57,    42,    44,
      11,    16,    43,    20,    21,    22,    59,    60,    61,     6,
       8,    37,    58,    16,    13,    42,    16,     3,    38,    37,
      44,    61,     7,     9,    20,    21,    22,    25,    26,    27,
      46,    47,    49,    50,     3,    10,     5,    48,    39,    40,
       3,    51,    17,    58,    11,    16,     5,     6,     8,     3,
       8,    45,     7,    46
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    34,    34,    34,    34,    34,    34,    34,
      35,    35,    36,    36,    37,    37,    38,    38,    38,    38,
      39,    39,    40,    40,    41,    41,    42,    42,    43,    43,
      43,    43,    43,    43,    43,    44,    44,    45,    45,    46,
      46,    46,    47,    48,    48,    49,    49,    49,    49,    49,
      49,    50,    50,    51,    51,    52,    52,    53,    54,    54,
      55,    55,    56,    56,    57,    58,    58,    59,    59,    60,
      60,    60,    61
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     2,     2,     2,     2,     2,
       6,     7,     0,     1,     3,     1,     0,     6,     8,     2,
       0,     1,     2,     3,     1,     3,     1,     2,     1,     1,
       3,     1,     1,     1,     1,     1,     3,     0,     2,     2,
       5,     1,     3,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     3,     2,     2,     4,     0,     2,
       5,     6,     1,     3,     1,     0,     2,     1,     3,     1,
       1,     1,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (parseParam, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, parseParam); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, ASTParseParams *parseParam)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (parseParam);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, ASTParseParams *parseParam)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep, parseParam);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule, ASTParseParams *parseParam)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              , parseParam);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, parseParam); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, ASTParseParams *parseParam)
{
  YYUSE (yyvaluep);
  YYUSE (parseParam);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (ASTParseParams *parseParam)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs;

    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex (&yylval);
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 124 "agrampar.y"
               { (yyval.file) = parseParam->treeTop = new ASTSpecFile((yyvsp[0].formList)); }
#line 1459 "agrampar.tab.c"
    break;

  case 3:
#line 129 "agrampar.y"
                             { (yyval.formList) = new ASTList<ToplevelForm>; }
#line 1465 "agrampar.tab.c"
    break;

  case 4:
#line 130 "agrampar.y"
                             { ((yyval.formList)=(yyvsp[-1].formList))->append((yyvsp[0].tfClass)); }
#line 1471 "agrampar.tab.c"
    break;

  case 5:
#line 131 "agrampar.y"
                             { ((yyval.formList)=(yyvsp[-1].formList))->append((yyvsp[0].verbatim)); }
#line 1477 "agrampar.tab.c"
    break;

  case 6:
#line 132 "agrampar.y"
                             { ((yyval.formList)=(yyvsp[-1].formList))->append((yyvsp[0].tfOption)); }
#line 1483 "agrampar.tab.c"
    break;

  case 7:
#line 133 "agrampar.y"
                             { ((yyval.formList)=(yyvsp[-1].formList))->append((yyvsp[0].tfEnum)); }
#line 1489 "agrampar.tab.c"
    break;

  case 8:
#line 134 "agrampar.y"
                             { ((yyval.formList)=(yyvsp[-1].formList))->append(new TF_custom((yyvsp[0].customCode))); }
#line 1495 "agrampar.tab.c"
    break;

  case 9:
#line 135 "agrampar.y"
                             { (yyval.formList)=(yyvsp[-1].formList); }
#line 1501 "agrampar.tab.c"
    break;

  case 10:
#line 141 "agrampar.y"
         { ((yyval.tfClass)=(yyvsp[0].tfClass))->super->name = unbox((yyvsp[-3].str));
           (yyval.tfClass)->super->args.steal((yyvsp[-2].ctorArgList));
           (yyval.tfClass)->super->bases.steal((yyvsp[-1].baseClassList)); }
#line 1509 "agrampar.tab.c"
    break;

  case 11:
#line 145 "agrampar.y"
         { ((yyval.tfClass)=(yyvsp[0].tfClass))->super->name = unbox((yyvsp[-4].str));
           (yyval.tfClass)->super->args.steal((yyvsp[-3].ctorArgList));
           (yyval.tfClass)->super->lastArgs.steal((yyvsp[-2].ctorArgList));
           (yyval.tfClass)->super->bases.steal((yyvsp[-1].baseClassList)); }
#line 1518 "agrampar.tab.c"
    break;

  case 12:
#line 152 "agrampar.y"
                             {}
#line 1524 "agrampar.tab.c"
    break;

  case 13:
#line 153 "agrampar.y"
                             {}
#line 1530 "agrampar.tab.c"
    break;

  case 14:
#line 166 "agrampar.y"
             { (yyval.tfClass)=(yyvsp[-1].tfClass); }
#line 1536 "agrampar.tab.c"
    break;

  case 15:
#line 168 "agrampar.y"
             { (yyval.tfClass) = new TF_class(new ASTClass("(placeholder)", NULL, NULL, NULL, NULL), NULL); }
#line 1542 "agrampar.tab.c"
    break;

  case 16:
#line 175 "agrampar.y"
      { (yyval.tfClass) = new TF_class(new ASTClass("(placeholder)", NULL, NULL, NULL, NULL), NULL); }
#line 1548 "agrampar.tab.c"
    break;

  case 17:
#line 177 "agrampar.y"
      { ((yyval.tfClass)=(yyvsp[-5].tfClass))->ctors.append(new ASTClass(unbox((yyvsp[-3].str)), (yyvsp[-2].ctorArgList), NULL, (yyvsp[-1].baseClassList), NULL)); }
#line 1554 "agrampar.tab.c"
    break;

  case 18:
#line 179 "agrampar.y"
      { ((yyval.tfClass)=(yyvsp[-7].tfClass))->ctors.append(new ASTClass(unbox((yyvsp[-5].str)), (yyvsp[-4].ctorArgList), NULL, (yyvsp[-3].baseClassList), (yyvsp[-1].userDeclList))); }
#line 1560 "agrampar.tab.c"
    break;

  case 19:
#line 181 "agrampar.y"
      { ((yyval.tfClass)=(yyvsp[-1].tfClass))->super->decls.append((yyvsp[0].annotation)); }
#line 1566 "agrampar.tab.c"
    break;

  case 20:
#line 188 "agrampar.y"
      { (yyval.ctorArgList) = new ASTList<CtorArg>; }
#line 1572 "agrampar.tab.c"
    break;

  case 21:
#line 190 "agrampar.y"
      { (yyval.ctorArgList) = (yyvsp[0].ctorArgList); }
#line 1578 "agrampar.tab.c"
    break;

  case 22:
#line 196 "agrampar.y"
      { (yyval.ctorArgList) = new ASTList<CtorArg>; }
#line 1584 "agrampar.tab.c"
    break;

  case 23:
#line 198 "agrampar.y"
      { (yyval.ctorArgList) = (yyvsp[-1].ctorArgList); }
#line 1590 "agrampar.tab.c"
    break;

  case 24:
#line 203 "agrampar.y"
               { (yyval.ctorArgList) = new ASTList<CtorArg>;
                 {
                   string tmp = unbox((yyvsp[0].str));
                   (yyval.ctorArgList)->append(parseCtorArg(tmp));
                 }
               }
#line 1601 "agrampar.tab.c"
    break;

  case 25:
#line 210 "agrampar.y"
               { ((yyval.ctorArgList)=(yyvsp[-2].ctorArgList))->append(parseCtorArg(unbox((yyvsp[0].str)))); }
#line 1607 "agrampar.tab.c"
    break;

  case 26:
#line 215 "agrampar.y"
       { (yyval.str) = (yyvsp[0].str); }
#line 1613 "agrampar.tab.c"
    break;

  case 27:
#line 217 "agrampar.y"
       { (yyval.str) = appendStr((yyvsp[-1].str), (yyvsp[0].str)); }
#line 1619 "agrampar.tab.c"
    break;

  case 28:
#line 222 "agrampar.y"
                     { (yyval.str) = appendStr((yyvsp[0].str), box(" ")); }
#line 1625 "agrampar.tab.c"
    break;

  case 29:
#line 223 "agrampar.y"
                     { (yyval.str) = appendStr((yyvsp[0].str), box(" ")); }
#line 1631 "agrampar.tab.c"
    break;

  case 30:
#line 224 "agrampar.y"
                     { (yyval.str) = appendStr(box("<"), appendStr((yyvsp[-1].str), box(">"))); }
#line 1637 "agrampar.tab.c"
    break;

  case 31:
#line 225 "agrampar.y"
                     { (yyval.str) = box("*"); }
#line 1643 "agrampar.tab.c"
    break;

  case 32:
#line 226 "agrampar.y"
                     { (yyval.str) = box("&"); }
#line 1649 "agrampar.tab.c"
    break;

  case 33:
#line 227 "agrampar.y"
                     { (yyval.str) = box("="); }
#line 1655 "agrampar.tab.c"
    break;

  case 34:
#line 228 "agrampar.y"
                     { (yyval.str) = box("class "); }
#line 1661 "agrampar.tab.c"
    break;

  case 35:
#line 233 "agrampar.y"
           { (yyval.str) = (yyvsp[0].str); }
#line 1667 "agrampar.tab.c"
    break;

  case 36:
#line 235 "agrampar.y"
           { (yyval.str) = appendStr((yyvsp[-2].str), appendStr(box(","), (yyvsp[0].str))); }
#line 1673 "agrampar.tab.c"
    break;

  case 37:
#line 241 "agrampar.y"
      { (yyval.userDeclList) = new ASTList<Annotation>; }
#line 1679 "agrampar.tab.c"
    break;

  case 38:
#line 243 "agrampar.y"
      { ((yyval.userDeclList)=(yyvsp[-1].userDeclList))->append((yyvsp[0].annotation)); }
#line 1685 "agrampar.tab.c"
    break;

  case 39:
#line 249 "agrampar.y"
      { (yyval.annotation) = new UserDecl((yyvsp[-1].accessMod), unbox((yyvsp[0].str)), ""); }
#line 1691 "agrampar.tab.c"
    break;

  case 40:
#line 251 "agrampar.y"
      { (yyval.annotation) = new UserDecl((yyvsp[-4].accessMod), unbox((yyvsp[-3].str)), unbox((yyvsp[-1].str))); }
#line 1697 "agrampar.tab.c"
    break;

  case 41:
#line 253 "agrampar.y"
      { (yyval.annotation) = (yyvsp[0].customCode); }
#line 1703 "agrampar.tab.c"
    break;

  case 42:
#line 259 "agrampar.y"
      { (yyval.customCode) = new CustomCode(unbox((yyvsp[-1].str)), unbox((yyvsp[0].str))); }
#line 1709 "agrampar.tab.c"
    break;

  case 43:
#line 265 "agrampar.y"
      { (yyval.str) = (yyvsp[-1].str); }
#line 1715 "agrampar.tab.c"
    break;

  case 44:
#line 267 "agrampar.y"
      { (yyval.str) = (yyvsp[-1].str); }
#line 1721 "agrampar.tab.c"
    break;

  case 45:
#line 272 "agrampar.y"
                    { (yyval.accessCtl) = AC_PUBLIC; }
#line 1727 "agrampar.tab.c"
    break;

  case 46:
#line 273 "agrampar.y"
                    { (yyval.accessCtl) = AC_PRIVATE; }
#line 1733 "agrampar.tab.c"
    break;

  case 47:
#line 274 "agrampar.y"
                    { (yyval.accessCtl) = AC_PROTECTED; }
#line 1739 "agrampar.tab.c"
    break;

  case 48:
#line 275 "agrampar.y"
                    { (yyval.accessCtl) = AC_CTOR; }
#line 1745 "agrampar.tab.c"
    break;

  case 49:
#line 276 "agrampar.y"
                    { (yyval.accessCtl) = AC_DTOR; }
#line 1751 "agrampar.tab.c"
    break;

  case 50:
#line 277 "agrampar.y"
                    { (yyval.accessCtl) = AC_PUREVIRT; }
#line 1757 "agrampar.tab.c"
    break;

  case 51:
#line 282 "agrampar.y"
             { (yyval.accessMod) = new AccessMod((yyvsp[0].accessCtl), NULL); }
#line 1763 "agrampar.tab.c"
    break;

  case 52:
#line 284 "agrampar.y"
             { (yyval.accessMod) = new AccessMod((yyvsp[-3].accessCtl), (yyvsp[-1].stringList)); }
#line 1769 "agrampar.tab.c"
    break;

  case 53:
#line 289 "agrampar.y"
              { (yyval.stringList) = new ASTList<string>((yyvsp[0].str)); }
#line 1775 "agrampar.tab.c"
    break;

  case 54:
#line 291 "agrampar.y"
              { ((yyval.stringList)=(yyvsp[-2].stringList))->append((yyvsp[0].str)); }
#line 1781 "agrampar.tab.c"
    break;

  case 55:
#line 296 "agrampar.y"
            { (yyval.verbatim) = new TF_verbatim(unbox((yyvsp[0].str))); }
#line 1787 "agrampar.tab.c"
    break;

  case 56:
#line 298 "agrampar.y"
            { (yyval.verbatim) = new TF_impl_verbatim(unbox((yyvsp[0].str))); }
#line 1793 "agrampar.tab.c"
    break;

  case 57:
#line 303 "agrampar.y"
          { (yyval.tfOption) = new TF_option(unbox((yyvsp[-2].str)), (yyvsp[-1].stringList)); }
#line 1799 "agrampar.tab.c"
    break;

  case 58:
#line 308 "agrampar.y"
              { (yyval.stringList) = new ASTList<string>; }
#line 1805 "agrampar.tab.c"
    break;

  case 59:
#line 310 "agrampar.y"
              { ((yyval.stringList)=(yyvsp[-1].stringList))->append((yyvsp[0].str)); }
#line 1811 "agrampar.tab.c"
    break;

  case 60:
#line 315 "agrampar.y"
        { (yyval.tfEnum) = new TF_enum(unbox((yyvsp[-3].str)), (yyvsp[-1].enumeratorList)); }
#line 1817 "agrampar.tab.c"
    break;

  case 61:
#line 317 "agrampar.y"
        { (yyval.tfEnum) = new TF_enum(unbox((yyvsp[-4].str)), (yyvsp[-2].enumeratorList)); }
#line 1823 "agrampar.tab.c"
    break;

  case 62:
#line 322 "agrampar.y"
                 { (yyval.enumeratorList) = new ASTList<string>((yyvsp[0].enumerator)); }
#line 1829 "agrampar.tab.c"
    break;

  case 63:
#line 324 "agrampar.y"
                 { ((yyval.enumeratorList)=(yyvsp[-2].enumeratorList))->append((yyvsp[0].enumerator)); }
#line 1835 "agrampar.tab.c"
    break;

  case 64:
#line 329 "agrampar.y"
              { (yyval.enumerator) = (yyvsp[0].str); }
#line 1841 "agrampar.tab.c"
    break;

  case 65:
#line 334 "agrampar.y"
                  { (yyval.baseClassList) = new ASTList<BaseClass>; }
#line 1847 "agrampar.tab.c"
    break;

  case 66:
#line 336 "agrampar.y"
                  { (yyval.baseClassList) = (yyvsp[0].baseClassList); }
#line 1853 "agrampar.tab.c"
    break;

  case 67:
#line 341 "agrampar.y"
                { (yyval.baseClassList) = new ASTList<BaseClass>((yyvsp[0].baseClass)); }
#line 1859 "agrampar.tab.c"
    break;

  case 68:
#line 343 "agrampar.y"
                { ((yyval.baseClassList)=(yyvsp[-2].baseClassList))->append((yyvsp[0].baseClass)); }
#line 1865 "agrampar.tab.c"
    break;

  case 69:
#line 348 "agrampar.y"
                    { (yyval.accessCtl) = AC_PUBLIC; }
#line 1871 "agrampar.tab.c"
    break;

  case 70:
#line 349 "agrampar.y"
                    { (yyval.accessCtl) = AC_PRIVATE; }
#line 1877 "agrampar.tab.c"
    break;

  case 71:
#line 350 "agrampar.y"
                    { (yyval.accessCtl) = AC_PROTECTED; }
#line 1883 "agrampar.tab.c"
    break;

  case 72:
#line 355 "agrampar.y"
             { (yyval.baseClass) = new BaseClass((yyvsp[-1].accessCtl), unbox((yyvsp[0].str))); }
#line 1889 "agrampar.tab.c"
    break;


#line 1893 "agrampar.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (parseParam, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (parseParam, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, parseParam);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, parseParam);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (parseParam, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, parseParam);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, parseParam);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 358 "agrampar.y"


/* ----------------- extra C code ------------------- */

