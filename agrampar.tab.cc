/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

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


#line 92 "agrampar.tab.c"

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

#include "agrampar.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TOK_NAME = 3,                   /* TOK_NAME  */
  YYSYMBOL_TOK_INTLIT = 4,                 /* TOK_INTLIT  */
  YYSYMBOL_TOK_EMBEDDED_CODE = 5,          /* TOK_EMBEDDED_CODE  */
  YYSYMBOL_TOK_LBRACE = 6,                 /* "{"  */
  YYSYMBOL_TOK_RBRACE = 7,                 /* "}"  */
  YYSYMBOL_TOK_SEMICOLON = 8,              /* ";"  */
  YYSYMBOL_TOK_ARROW = 9,                  /* "->"  */
  YYSYMBOL_TOK_LPAREN = 10,                /* "("  */
  YYSYMBOL_TOK_RPAREN = 11,                /* ")"  */
  YYSYMBOL_TOK_LANGLE = 12,                /* "<"  */
  YYSYMBOL_TOK_RANGLE = 13,                /* ">"  */
  YYSYMBOL_TOK_STAR = 14,                  /* "*"  */
  YYSYMBOL_TOK_AMPERSAND = 15,             /* "&"  */
  YYSYMBOL_TOK_COMMA = 16,                 /* ","  */
  YYSYMBOL_TOK_EQUALS = 17,                /* "="  */
  YYSYMBOL_TOK_COLON = 18,                 /* ":"  */
  YYSYMBOL_TOK_CLASS = 19,                 /* "class"  */
  YYSYMBOL_TOK_PUBLIC = 20,                /* "public"  */
  YYSYMBOL_TOK_PRIVATE = 21,               /* "private"  */
  YYSYMBOL_TOK_PROTECTED = 22,             /* "protected"  */
  YYSYMBOL_TOK_VERBATIM = 23,              /* "verbatim"  */
  YYSYMBOL_TOK_IMPL_VERBATIM = 24,         /* "impl_verbatim"  */
  YYSYMBOL_TOK_CTOR = 25,                  /* "ctor"  */
  YYSYMBOL_TOK_DTOR = 26,                  /* "dtor"  */
  YYSYMBOL_TOK_PURE_VIRTUAL = 27,          /* "pure_virtual"  */
  YYSYMBOL_TOK_CUSTOM = 28,                /* "custom"  */
  YYSYMBOL_TOK_DEFINE_CUSTOMIZABLE = 29,   /* "define_customizable"  */
  YYSYMBOL_TOK_OPTION = 30,                /* "option"  */
  YYSYMBOL_TOK_NEW = 31,                   /* "new"  */
  YYSYMBOL_TOK_ENUM = 32,                  /* "enum"  */
  YYSYMBOL_YYACCEPT = 33,                  /* $accept  */
  YYSYMBOL_StartSymbol = 34,               /* StartSymbol  */
  YYSYMBOL_Input = 35,                     /* Input  */
  YYSYMBOL_Class = 36,                     /* Class  */
  YYSYMBOL_NewOpt = 37,                    /* NewOpt  */
  YYSYMBOL_ClassBody = 38,                 /* ClassBody  */
  YYSYMBOL_ClassMembersOpt = 39,           /* ClassMembersOpt  */
  YYSYMBOL_CtorArgsOpt = 40,               /* CtorArgsOpt  */
  YYSYMBOL_CtorArgs = 41,                  /* CtorArgs  */
  YYSYMBOL_CtorArgList = 42,               /* CtorArgList  */
  YYSYMBOL_Arg = 43,                       /* Arg  */
  YYSYMBOL_ArgWord = 44,                   /* ArgWord  */
  YYSYMBOL_ArgList = 45,                   /* ArgList  */
  YYSYMBOL_CtorMembersOpt = 46,            /* CtorMembersOpt  */
  YYSYMBOL_Annotation = 47,                /* Annotation  */
  YYSYMBOL_CustomCode = 48,                /* CustomCode  */
  YYSYMBOL_Public = 49,                    /* Public  */
  YYSYMBOL_AccessMod = 50,                 /* AccessMod  */
  YYSYMBOL_StringList = 51,                /* StringList  */
  YYSYMBOL_Verbatim = 52,                  /* Verbatim  */
  YYSYMBOL_Option = 53,                    /* Option  */
  YYSYMBOL_OptionArgs = 54,                /* OptionArgs  */
  YYSYMBOL_Enum = 55,                      /* Enum  */
  YYSYMBOL_EnumeratorSeq = 56,             /* EnumeratorSeq  */
  YYSYMBOL_Enumerator = 57,                /* Enumerator  */
  YYSYMBOL_BaseClassesOpt = 58,            /* BaseClassesOpt  */
  YYSYMBOL_BaseClassSeq = 59,              /* BaseClassSeq  */
  YYSYMBOL_BaseAccess = 60,                /* BaseAccess  */
  YYSYMBOL_BaseClass = 61                  /* BaseClass  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYLAST   114

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  116

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   287


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   124,   124,   130,   131,   132,   133,   134,   135,   136,
     141,   145,   153,   154,   166,   168,   176,   177,   179,   181,
     189,   190,   196,   198,   203,   210,   215,   217,   223,   224,
     225,   226,   227,   228,   229,   233,   235,   242,   243,   249,
     251,   253,   259,   265,   266,   267,   268,   269,   270,   271,
     275,   277,   282,   284,   289,   291,   296,   302,   303,   308,
     310,   315,   317,   322,   328,   329,   334,   336,   342,   343,
     344,   348
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TOK_NAME",
  "TOK_INTLIT", "TOK_EMBEDDED_CODE", "\"{\"", "\"}\"", "\";\"", "\"->\"",
  "\"(\"", "\")\"", "\"<\"", "\">\"", "\"*\"", "\"&\"", "\",\"", "\"=\"",
  "\":\"", "\"class\"", "\"public\"", "\"private\"", "\"protected\"",
  "\"verbatim\"", "\"impl_verbatim\"", "\"ctor\"", "\"dtor\"",
  "\"pure_virtual\"", "\"custom\"", "\"define_customizable\"",
  "\"option\"", "\"new\"", "\"enum\"", "$accept", "StartSymbol", "Input",
  "Class", "NewOpt", "ClassBody", "ClassMembersOpt", "CtorArgsOpt",
  "CtorArgs", "CtorArgList", "Arg", "ArgWord", "ArgList", "CtorMembersOpt",
  "Annotation", "CustomCode", "Public", "AccessMod", "StringList",
  "Verbatim", "Option", "OptionArgs", "Enum", "EnumeratorSeq",
  "Enumerator", "BaseClassesOpt", "BaseClassSeq", "BaseAccess",
  "BaseClass", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-56)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-13)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -56,     9,    -2,   -56,   -56,     5,    17,    38,    39,   -56,
      46,   -56,    40,   -56,   -56,   -56,   -56,    66,    72,    80,
     -56,    82,    86,    83,    84,    87,     0,    90,    85,   -56,
     -56,    89,   -56,   -56,   -56,     3,   -56,     1,    76,    85,
     -56,   -56,    36,   -56,   -56,   -56,    61,   -56,   -56,   -56,
     -56,    44,    61,   -56,    62,    50,    76,   -56,   -56,    21,
      88,   -56,    61,   -56,   -56,   -56,   -56,    81,    95,   -56,
     -56,   -56,   -56,    50,    61,   -56,    61,    62,   -56,    25,
     -56,   -56,   -56,   -56,    96,   -56,   -56,   -56,   -56,   -56,
     -56,   -56,   -56,   -56,    92,    98,    85,    97,    64,    76,
     -56,   -56,    63,   -56,    99,    79,   -56,   102,   100,   -56,
     -56,   -56,   -56,    41,   -56,   -56
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     2,     1,     9,     0,     0,     0,     0,    13,
       0,     4,     0,     8,     5,     6,     7,     0,     0,     0,
      57,     0,     0,     0,     0,     0,     0,     0,    20,    54,
      55,     0,    58,    56,    63,     0,    61,     0,    64,    21,
      42,    59,     0,    28,    29,    22,     0,    31,    32,    33,
      34,     0,    24,    26,     0,     0,    64,    60,    62,    35,
       0,    23,     0,    27,    68,    69,    70,    65,     0,    66,
      16,    15,    10,     0,     0,    30,    25,     0,    71,     0,
      11,    36,    67,    14,     0,    43,    44,    45,    46,    47,
      48,    49,    19,    41,    50,     0,    20,     0,     0,    64,
      21,    52,     0,    39,     0,     0,    51,     0,     0,    37,
      17,    53,    40,     0,    18,    38
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -56,   -56,   -56,   -56,   -56,    33,   -56,    11,   -39,   -56,
     -35,   -45,    35,   -56,    -3,   109,   -56,   -56,   -56,   -56,
     -56,   -56,   -56,   -56,    70,   -55,   -56,   -56,    37
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,    11,    12,    72,    79,    38,    39,    51,
      59,    53,    60,   113,    92,    93,    94,    95,   102,    14,
      15,    26,    16,    35,    36,    55,    67,    68,    69
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      56,    73,    52,    32,    43,    44,     4,    63,    33,     3,
      41,    17,    45,    46,    63,    47,    48,   -12,    49,    42,
      50,     5,     6,    18,    43,    44,     7,    76,     8,     9,
      10,    63,    83,    46,    84,    47,    48,    74,    49,    34,
      50,    19,    20,    57,   105,    85,    86,    87,   114,    21,
      88,    89,    90,     7,    91,    61,    70,   100,    71,    22,
      62,    85,    86,    87,    43,    44,    88,    89,    90,     7,
      91,    23,   103,    46,   106,    47,    48,    24,    49,   107,
      50,   104,    64,    65,    66,   109,    25,   110,    27,    28,
      29,    30,    31,    34,    54,    37,    40,    77,    78,    96,
     101,    75,    97,    98,   108,   111,    80,    99,   112,    81,
     115,    13,    58,     0,    82
};

static const yytype_int8 yycheck[] =
{
      39,    56,    37,     3,     3,     4,     8,    52,     8,     0,
       7,     6,    11,    12,    59,    14,    15,    19,    17,    16,
      19,    23,    24,     6,     3,     4,    28,    62,    30,    31,
      32,    76,     7,    12,     9,    14,    15,    16,    17,     3,
      19,     3,     3,     7,    99,    20,    21,    22,     7,     3,
      25,    26,    27,    28,    29,    11,     6,    96,     8,    19,
      16,    20,    21,    22,     3,     4,    25,    26,    27,    28,
      29,     5,     8,    12,    11,    14,    15,     5,    17,    16,
      19,    17,    20,    21,    22,     6,     6,     8,     6,     3,
       7,     7,     5,     3,    18,    10,     7,    16,     3,     3,
       3,    13,    10,     5,     5,     3,    73,    96,     8,    74,
     113,     2,    42,    -1,    77
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    34,    35,     0,     8,    23,    24,    28,    30,    31,
      32,    36,    37,    48,    52,    53,    55,     6,     6,     3,
       3,     3,    19,     5,     5,     6,    54,     6,     3,     7,
       7,     5,     3,     8,     3,    56,    57,    10,    40,    41,
       7,     7,    16,     3,     4,    11,    12,    14,    15,    17,
      19,    42,    43,    44,    18,    58,    41,     7,    57,    43,
      45,    11,    16,    44,    20,    21,    22,    59,    60,    61,
       6,     8,    38,    58,    16,    13,    43,    16,     3,    39,
      38,    45,    61,     7,     9,    20,    21,    22,    25,    26,
      27,    29,    47,    48,    49,    50,     3,    10,     5,    40,
      41,     3,    51,     8,    17,    58,    11,    16,     5,     6,
       8,     3,     8,    46,     7,    47
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    33,    34,    35,    35,    35,    35,    35,    35,    35,
      36,    36,    37,    37,    38,    38,    39,    39,    39,    39,
      40,    40,    41,    41,    42,    42,    43,    43,    44,    44,
      44,    44,    44,    44,    44,    45,    45,    46,    46,    47,
      47,    47,    48,    49,    49,    49,    49,    49,    49,    49,
      50,    50,    51,    51,    52,    52,    53,    54,    54,    55,
      55,    56,    56,    57,    58,    58,    59,    59,    60,    60,
      60,    61
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     2,     2,     2,     2,     2,
       6,     7,     0,     1,     3,     1,     0,     6,     8,     2,
       0,     1,     2,     3,     1,     3,     1,     2,     1,     1,
       3,     1,     1,     1,     1,     1,     3,     0,     2,     3,
       5,     1,     5,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     3,     4,     4,     4,     0,     2,     5,
       6,     1,     3,     1,     0,     2,     1,     3,     1,     1,
       1,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, parseParam); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, ASTParseParams *parseParam)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (parseParam);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, ASTParseParams *parseParam)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, parseParam);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule, ASTParseParams *parseParam)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)], parseParam);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, ASTParseParams *parseParam)
{
  YY_USE (yyvaluep);
  YY_USE (parseParam);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (ASTParseParams *parseParam)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval);
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* StartSymbol: Input  */
#line 125 "agrampar.y"
               { (yyval.file) = parseParam->treeTop = new ASTSpecFile((yyvsp[0].formList)); }
#line 1228 "agrampar.tab.c"
    break;

  case 3: /* Input: %empty  */
#line 130 "agrampar.y"
                             { (yyval.formList) = new ASTList<ToplevelForm>; }
#line 1234 "agrampar.tab.c"
    break;

  case 4: /* Input: Input Class  */
#line 131 "agrampar.y"
                             { ((yyval.formList)=(yyvsp[-1].formList))->append((yyvsp[0].tfClass)); }
#line 1240 "agrampar.tab.c"
    break;

  case 5: /* Input: Input Verbatim  */
#line 132 "agrampar.y"
                             { ((yyval.formList)=(yyvsp[-1].formList))->append((yyvsp[0].verbatim)); }
#line 1246 "agrampar.tab.c"
    break;

  case 6: /* Input: Input Option  */
#line 133 "agrampar.y"
                             { ((yyval.formList)=(yyvsp[-1].formList))->append((yyvsp[0].tfOption)); }
#line 1252 "agrampar.tab.c"
    break;

  case 7: /* Input: Input Enum  */
#line 134 "agrampar.y"
                             { ((yyval.formList)=(yyvsp[-1].formList))->append((yyvsp[0].tfEnum)); }
#line 1258 "agrampar.tab.c"
    break;

  case 8: /* Input: Input CustomCode  */
#line 135 "agrampar.y"
                             { ((yyval.formList)=(yyvsp[-1].formList))->append(new TF_custom((yyvsp[0].customCode))); }
#line 1264 "agrampar.tab.c"
    break;

  case 9: /* Input: Input ";"  */
#line 136 "agrampar.y"
                             { (yyval.formList)=(yyvsp[-1].formList); }
#line 1270 "agrampar.tab.c"
    break;

  case 10: /* Class: NewOpt "class" TOK_NAME CtorArgsOpt BaseClassesOpt ClassBody  */
#line 142 "agrampar.y"
         { ((yyval.tfClass)=(yyvsp[0].tfClass))->super->name = unbox((yyvsp[-3].str));
           (yyval.tfClass)->super->args.steal((yyvsp[-2].ctorArgList));
           (yyval.tfClass)->super->bases.steal((yyvsp[-1].baseClassList)); }
#line 1278 "agrampar.tab.c"
    break;

  case 11: /* Class: NewOpt "class" TOK_NAME CtorArgs CtorArgs BaseClassesOpt ClassBody  */
#line 146 "agrampar.y"
         { ((yyval.tfClass)=(yyvsp[0].tfClass))->super->name = unbox((yyvsp[-4].str));
           (yyval.tfClass)->super->args.steal((yyvsp[-3].ctorArgList));
           (yyval.tfClass)->super->lastArgs.steal((yyvsp[-2].ctorArgList));
           (yyval.tfClass)->super->bases.steal((yyvsp[-1].baseClassList)); }
#line 1287 "agrampar.tab.c"
    break;

  case 12: /* NewOpt: %empty  */
#line 153 "agrampar.y"
                             {}
#line 1293 "agrampar.tab.c"
    break;

  case 13: /* NewOpt: "new"  */
#line 154 "agrampar.y"
                             {}
#line 1299 "agrampar.tab.c"
    break;

  case 14: /* ClassBody: "{" ClassMembersOpt "}"  */
#line 167 "agrampar.y"
             { (yyval.tfClass)=(yyvsp[-1].tfClass); }
#line 1305 "agrampar.tab.c"
    break;

  case 15: /* ClassBody: ";"  */
#line 169 "agrampar.y"
             { (yyval.tfClass) = new TF_class(new ASTClass("(placeholder)", NULL, NULL, NULL, NULL), NULL); }
#line 1311 "agrampar.tab.c"
    break;

  case 16: /* ClassMembersOpt: %empty  */
#line 176 "agrampar.y"
      { (yyval.tfClass) = new TF_class(new ASTClass("(placeholder)", NULL, NULL, NULL, NULL), NULL); }
#line 1317 "agrampar.tab.c"
    break;

  case 17: /* ClassMembersOpt: ClassMembersOpt "->" TOK_NAME CtorArgsOpt BaseClassesOpt ";"  */
#line 178 "agrampar.y"
      { ((yyval.tfClass)=(yyvsp[-5].tfClass))->ctors.append(new ASTClass(unbox((yyvsp[-3].str)), (yyvsp[-2].ctorArgList), NULL, (yyvsp[-1].baseClassList), NULL)); }
#line 1323 "agrampar.tab.c"
    break;

  case 18: /* ClassMembersOpt: ClassMembersOpt "->" TOK_NAME CtorArgsOpt BaseClassesOpt "{" CtorMembersOpt "}"  */
#line 180 "agrampar.y"
      { ((yyval.tfClass)=(yyvsp[-7].tfClass))->ctors.append(new ASTClass(unbox((yyvsp[-5].str)), (yyvsp[-4].ctorArgList), NULL, (yyvsp[-3].baseClassList), (yyvsp[-1].userDeclList))); }
#line 1329 "agrampar.tab.c"
    break;

  case 19: /* ClassMembersOpt: ClassMembersOpt Annotation  */
#line 182 "agrampar.y"
      { ((yyval.tfClass)=(yyvsp[-1].tfClass))->super->decls.append((yyvsp[0].annotation)); }
#line 1335 "agrampar.tab.c"
    break;

  case 20: /* CtorArgsOpt: %empty  */
#line 189 "agrampar.y"
      { (yyval.ctorArgList) = new ASTList<CtorArg>; }
#line 1341 "agrampar.tab.c"
    break;

  case 21: /* CtorArgsOpt: CtorArgs  */
#line 191 "agrampar.y"
      { (yyval.ctorArgList) = (yyvsp[0].ctorArgList); }
#line 1347 "agrampar.tab.c"
    break;

  case 22: /* CtorArgs: "(" ")"  */
#line 197 "agrampar.y"
      { (yyval.ctorArgList) = new ASTList<CtorArg>; }
#line 1353 "agrampar.tab.c"
    break;

  case 23: /* CtorArgs: "(" CtorArgList ")"  */
#line 199 "agrampar.y"
      { (yyval.ctorArgList) = (yyvsp[-1].ctorArgList); }
#line 1359 "agrampar.tab.c"
    break;

  case 24: /* CtorArgList: Arg  */
#line 204 "agrampar.y"
               { (yyval.ctorArgList) = new ASTList<CtorArg>;
                 {
                   string tmp = unbox((yyvsp[0].str));
                   (yyval.ctorArgList)->append(parseCtorArg(tmp));
                 }
               }
#line 1370 "agrampar.tab.c"
    break;

  case 25: /* CtorArgList: CtorArgList "," Arg  */
#line 211 "agrampar.y"
               { ((yyval.ctorArgList)=(yyvsp[-2].ctorArgList))->append(parseCtorArg(unbox((yyvsp[0].str)))); }
#line 1376 "agrampar.tab.c"
    break;

  case 26: /* Arg: ArgWord  */
#line 216 "agrampar.y"
       { (yyval.str) = (yyvsp[0].str); }
#line 1382 "agrampar.tab.c"
    break;

  case 27: /* Arg: Arg ArgWord  */
#line 218 "agrampar.y"
       { (yyval.str) = appendStr((yyvsp[-1].str), (yyvsp[0].str)); }
#line 1388 "agrampar.tab.c"
    break;

  case 28: /* ArgWord: TOK_NAME  */
#line 223 "agrampar.y"
                     { (yyval.str) = appendStr((yyvsp[0].str), box(" ")); }
#line 1394 "agrampar.tab.c"
    break;

  case 29: /* ArgWord: TOK_INTLIT  */
#line 224 "agrampar.y"
                     { (yyval.str) = appendStr((yyvsp[0].str), box(" ")); }
#line 1400 "agrampar.tab.c"
    break;

  case 30: /* ArgWord: "<" ArgList ">"  */
#line 225 "agrampar.y"
                     { (yyval.str) = appendStr(box("<"), appendStr((yyvsp[-1].str), box(">"))); }
#line 1406 "agrampar.tab.c"
    break;

  case 31: /* ArgWord: "*"  */
#line 226 "agrampar.y"
                     { (yyval.str) = box("*"); }
#line 1412 "agrampar.tab.c"
    break;

  case 32: /* ArgWord: "&"  */
#line 227 "agrampar.y"
                     { (yyval.str) = box("&"); }
#line 1418 "agrampar.tab.c"
    break;

  case 33: /* ArgWord: "="  */
#line 228 "agrampar.y"
                     { (yyval.str) = box("="); }
#line 1424 "agrampar.tab.c"
    break;

  case 34: /* ArgWord: "class"  */
#line 229 "agrampar.y"
                     { (yyval.str) = box("class "); }
#line 1430 "agrampar.tab.c"
    break;

  case 35: /* ArgList: Arg  */
#line 234 "agrampar.y"
           { (yyval.str) = (yyvsp[0].str); }
#line 1436 "agrampar.tab.c"
    break;

  case 36: /* ArgList: Arg "," ArgList  */
#line 236 "agrampar.y"
           { (yyval.str) = appendStr((yyvsp[-2].str), appendStr(box(","), (yyvsp[0].str))); }
#line 1442 "agrampar.tab.c"
    break;

  case 37: /* CtorMembersOpt: %empty  */
#line 242 "agrampar.y"
      { (yyval.userDeclList) = new ASTList<Annotation>; }
#line 1448 "agrampar.tab.c"
    break;

  case 38: /* CtorMembersOpt: CtorMembersOpt Annotation  */
#line 244 "agrampar.y"
      { ((yyval.userDeclList)=(yyvsp[-1].userDeclList))->append((yyvsp[0].annotation)); }
#line 1454 "agrampar.tab.c"
    break;

  case 39: /* Annotation: AccessMod TOK_EMBEDDED_CODE ";"  */
#line 250 "agrampar.y"
      { (yyval.annotation) = new UserDecl((yyvsp[-2].accessMod), unbox((yyvsp[-1].str)), ""); }
#line 1460 "agrampar.tab.c"
    break;

  case 40: /* Annotation: AccessMod TOK_EMBEDDED_CODE "=" TOK_EMBEDDED_CODE ";"  */
#line 252 "agrampar.y"
      { (yyval.annotation) = new UserDecl((yyvsp[-4].accessMod), unbox((yyvsp[-3].str)), unbox((yyvsp[-1].str))); }
#line 1466 "agrampar.tab.c"
    break;

  case 41: /* Annotation: CustomCode  */
#line 254 "agrampar.y"
      { (yyval.annotation) = (yyvsp[0].customCode); }
#line 1472 "agrampar.tab.c"
    break;

  case 42: /* CustomCode: "custom" TOK_NAME "{" TOK_EMBEDDED_CODE "}"  */
#line 260 "agrampar.y"
      { (yyval.customCode) = new CustomCode(unbox((yyvsp[-3].str)), unbox((yyvsp[-1].str))); }
#line 1478 "agrampar.tab.c"
    break;

  case 43: /* Public: "public"  */
#line 265 "agrampar.y"
                             { (yyval.accessCtl) = AC_PUBLIC; }
#line 1484 "agrampar.tab.c"
    break;

  case 44: /* Public: "private"  */
#line 266 "agrampar.y"
                             { (yyval.accessCtl) = AC_PRIVATE; }
#line 1490 "agrampar.tab.c"
    break;

  case 45: /* Public: "protected"  */
#line 267 "agrampar.y"
                             { (yyval.accessCtl) = AC_PROTECTED; }
#line 1496 "agrampar.tab.c"
    break;

  case 46: /* Public: "ctor"  */
#line 268 "agrampar.y"
                             { (yyval.accessCtl) = AC_CTOR; }
#line 1502 "agrampar.tab.c"
    break;

  case 47: /* Public: "dtor"  */
#line 269 "agrampar.y"
                             { (yyval.accessCtl) = AC_DTOR; }
#line 1508 "agrampar.tab.c"
    break;

  case 48: /* Public: "pure_virtual"  */
#line 270 "agrampar.y"
                             { (yyval.accessCtl) = AC_PUREVIRT; }
#line 1514 "agrampar.tab.c"
    break;

  case 49: /* Public: "define_customizable"  */
#line 271 "agrampar.y"
                             { (yyval.accessCtl) = AC_DEFINE_CUSTOMIZABLE; }
#line 1520 "agrampar.tab.c"
    break;

  case 50: /* AccessMod: Public  */
#line 276 "agrampar.y"
             { (yyval.accessMod) = new AccessMod((yyvsp[0].accessCtl), NULL); }
#line 1526 "agrampar.tab.c"
    break;

  case 51: /* AccessMod: Public "(" StringList ")"  */
#line 278 "agrampar.y"
             { (yyval.accessMod) = new AccessMod((yyvsp[-3].accessCtl), (yyvsp[-1].stringList)); }
#line 1532 "agrampar.tab.c"
    break;

  case 52: /* StringList: TOK_NAME  */
#line 283 "agrampar.y"
              { (yyval.stringList) = new ASTList<string>((yyvsp[0].str)); }
#line 1538 "agrampar.tab.c"
    break;

  case 53: /* StringList: StringList "," TOK_NAME  */
#line 285 "agrampar.y"
              { ((yyval.stringList)=(yyvsp[-2].stringList))->append((yyvsp[0].str)); }
#line 1544 "agrampar.tab.c"
    break;

  case 54: /* Verbatim: "verbatim" "{" TOK_EMBEDDED_CODE "}"  */
#line 290 "agrampar.y"
            { (yyval.verbatim) = new TF_verbatim(unbox((yyvsp[-1].str))); }
#line 1550 "agrampar.tab.c"
    break;

  case 55: /* Verbatim: "impl_verbatim" "{" TOK_EMBEDDED_CODE "}"  */
#line 292 "agrampar.y"
            { (yyval.verbatim) = new TF_impl_verbatim(unbox((yyvsp[-1].str))); }
#line 1556 "agrampar.tab.c"
    break;

  case 56: /* Option: "option" TOK_NAME OptionArgs ";"  */
#line 297 "agrampar.y"
          { (yyval.tfOption) = new TF_option(unbox((yyvsp[-2].str)), (yyvsp[-1].stringList)); }
#line 1562 "agrampar.tab.c"
    break;

  case 57: /* OptionArgs: %empty  */
#line 302 "agrampar.y"
              { (yyval.stringList) = new ASTList<string>; }
#line 1568 "agrampar.tab.c"
    break;

  case 58: /* OptionArgs: OptionArgs TOK_NAME  */
#line 304 "agrampar.y"
              { ((yyval.stringList)=(yyvsp[-1].stringList))->append((yyvsp[0].str)); }
#line 1574 "agrampar.tab.c"
    break;

  case 59: /* Enum: "enum" TOK_NAME "{" EnumeratorSeq "}"  */
#line 309 "agrampar.y"
        { (yyval.tfEnum) = new TF_enum(unbox((yyvsp[-3].str)), (yyvsp[-1].enumeratorList)); }
#line 1580 "agrampar.tab.c"
    break;

  case 60: /* Enum: "enum" TOK_NAME "{" EnumeratorSeq "," "}"  */
#line 311 "agrampar.y"
        { (yyval.tfEnum) = new TF_enum(unbox((yyvsp[-4].str)), (yyvsp[-2].enumeratorList)); }
#line 1586 "agrampar.tab.c"
    break;

  case 61: /* EnumeratorSeq: Enumerator  */
#line 316 "agrampar.y"
                 { (yyval.enumeratorList) = new ASTList<string>((yyvsp[0].enumerator)); }
#line 1592 "agrampar.tab.c"
    break;

  case 62: /* EnumeratorSeq: EnumeratorSeq "," Enumerator  */
#line 318 "agrampar.y"
                 { ((yyval.enumeratorList)=(yyvsp[-2].enumeratorList))->append((yyvsp[0].enumerator)); }
#line 1598 "agrampar.tab.c"
    break;

  case 63: /* Enumerator: TOK_NAME  */
#line 323 "agrampar.y"
              { (yyval.enumerator) = (yyvsp[0].str); }
#line 1604 "agrampar.tab.c"
    break;

  case 64: /* BaseClassesOpt: %empty  */
#line 328 "agrampar.y"
                  { (yyval.baseClassList) = new ASTList<BaseClass>; }
#line 1610 "agrampar.tab.c"
    break;

  case 65: /* BaseClassesOpt: ":" BaseClassSeq  */
#line 330 "agrampar.y"
                  { (yyval.baseClassList) = (yyvsp[0].baseClassList); }
#line 1616 "agrampar.tab.c"
    break;

  case 66: /* BaseClassSeq: BaseClass  */
#line 335 "agrampar.y"
                { (yyval.baseClassList) = new ASTList<BaseClass>((yyvsp[0].baseClass)); }
#line 1622 "agrampar.tab.c"
    break;

  case 67: /* BaseClassSeq: BaseClassSeq "," BaseClass  */
#line 337 "agrampar.y"
                { ((yyval.baseClassList)=(yyvsp[-2].baseClassList))->append((yyvsp[0].baseClass)); }
#line 1628 "agrampar.tab.c"
    break;

  case 68: /* BaseAccess: "public"  */
#line 342 "agrampar.y"
                    { (yyval.accessCtl) = AC_PUBLIC; }
#line 1634 "agrampar.tab.c"
    break;

  case 69: /* BaseAccess: "private"  */
#line 343 "agrampar.y"
                    { (yyval.accessCtl) = AC_PRIVATE; }
#line 1640 "agrampar.tab.c"
    break;

  case 70: /* BaseAccess: "protected"  */
#line 344 "agrampar.y"
                    { (yyval.accessCtl) = AC_PROTECTED; }
#line 1646 "agrampar.tab.c"
    break;

  case 71: /* BaseClass: BaseAccess TOK_NAME  */
#line 349 "agrampar.y"
             { (yyval.baseClass) = new BaseClass((yyvsp[-1].accessCtl), unbox((yyvsp[0].str))); }
#line 1652 "agrampar.tab.c"
    break;


#line 1656 "agrampar.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (parseParam, YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, parseParam);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (parseParam, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, parseParam);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 352 "agrampar.y"


/* ----------------- extra C code ------------------- */

