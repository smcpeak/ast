/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_AGRAMPAR_TAB_H_INCLUDED
# define YY_YY_AGRAMPAR_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TOK_NAME = 258,                /* TOK_NAME  */
    TOK_INTLIT = 259,              /* TOK_INTLIT  */
    TOK_EMBEDDED_CODE = 260,       /* TOK_EMBEDDED_CODE  */
    TOK_LBRACE = 261,              /* "{"  */
    TOK_RBRACE = 262,              /* "}"  */
    TOK_SEMICOLON = 263,           /* ";"  */
    TOK_ARROW = 264,               /* "->"  */
    TOK_LPAREN = 265,              /* "("  */
    TOK_RPAREN = 266,              /* ")"  */
    TOK_LANGLE = 267,              /* "<"  */
    TOK_RANGLE = 268,              /* ">"  */
    TOK_STAR = 269,                /* "*"  */
    TOK_AMPERSAND = 270,           /* "&"  */
    TOK_COMMA = 271,               /* ","  */
    TOK_EQUALS = 272,              /* "="  */
    TOK_COLON = 273,               /* ":"  */
    TOK_CLASS = 274,               /* "class"  */
    TOK_PUBLIC = 275,              /* "public"  */
    TOK_PRIVATE = 276,             /* "private"  */
    TOK_PROTECTED = 277,           /* "protected"  */
    TOK_VERBATIM = 278,            /* "verbatim"  */
    TOK_IMPL_VERBATIM = 279,       /* "impl_verbatim"  */
    TOK_CTOR = 280,                /* "ctor"  */
    TOK_DTOR = 281,                /* "dtor"  */
    TOK_PURE_VIRTUAL = 282,        /* "pure_virtual"  */
    TOK_CUSTOM = 283,              /* "custom"  */
    TOK_DEFINE_CUSTOMIZABLE = 284, /* "define_customizable"  */
    TOK_OPTION = 285,              /* "option"  */
    TOK_NEW = 286,                 /* "new"  */
    TOK_ENUM = 287                 /* "enum"  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 77 "agrampar.y"

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

#line 117 "agrampar.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif




int yyparse (ASTParseParams *parseParam);


#endif /* !YY_YY_AGRAMPAR_TAB_H_INCLUDED  */
