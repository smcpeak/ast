/* agrammar.lex            see license.txt for copyright and terms of use
 * lexical analyzer for my AST input format
 */

%smflex 100

/* ----------------- C definitions -------------------- */
%{

// pull in my declaration of the lexer class -- this defines
// the additional lexer state, some of which is used in the
// action rules below
#include "gramlex.h"

// pull in the bison-generated token codes
#include "agrampar.codes.h"

#include <string.h>         // strchr, strrchr

// for maintaining column count
#define TOKEN_START  tokenStartLoc = fileState.loc /* user ; */
#define UPD_COL      advCol(YY_LENG) /* user ; */
#define TOK_UPD_COL  TOKEN_START; UPD_COL  /* user ; */

%}


/* -------------------- flex options ------------------ */
/* don't use the default-echo rules */
%option nodefault

/* generate a c++ lexer */
%option c++

/* and I will define the class */
%option yyclass="GrammarLexer"

/* This intentionally shares a prefix with ../elkhound/gramlex.lex. */


/* ------------------- definitions -------------------- */
/* any character, including newline */
ANY       (.|"\n")

/* any character except newline */
ANYBUTNL  .

/* starting character in a name */
LETTER    [a-zA-Z_]

/* starting character in a numeric literal */
DIGIT     [0-9]

/* double-quote */
DQUOTE    "\""

/* character that can appear in a quoted string */
/* (I currently don't have any backslash codes, but I want to
 * leave open that possibility, for now backslashes are illegal) */
STRCHR    [^\n\\\"]

/* whitespace that doesn't cross line a boundary */
SLWHITE   [ \t]


/* --------------- start conditions ------------------- */
%x C_COMMENT
%x EMBED
%x INITVAL


/* ---------------------- rules ----------------------- */
%%

  /* -------- whitespace ------ */
"\n" {
  newLine();
}

[ \t\f\v]+ {
  UPD_COL;
}

  /* -------- comments -------- */
"/""*" {
  /* C-style comments */
  TOKEN_START;
  UPD_COL;
  YY_SET_START_CONDITION(C_COMMENT);
}

<C_COMMENT>{
  "*/" {
    /* end of comment */
    UPD_COL;
    YY_SET_START_CONDITION(INITIAL);
  }

  . {
    /* anything but slash-star or newline -- eat it */
    UPD_COL;
  }

  "\n" {
    newLine();
  }

  <<EOF>> {
    UPD_COL;      // <<EOF>> YY_LENG is 1!
    errorUnterminatedComment();
    return TOK_EOF;
  }
}


"//".*"\n" {
  /* C++-style comment -- eat it */
  TOKEN_START;
  advCol(YY_LENG-1);  // don't count the newline
  newLine();          // get it here
}


  /* -------- punctuators, operators, keywords --------- */
"}"                TOK_UPD_COL;  return TOK_RBRACE;
";"                TOK_UPD_COL;  return TOK_SEMICOLON;
"->"               TOK_UPD_COL;  return TOK_ARROW;
"("                TOK_UPD_COL;  return TOK_LPAREN;
","                TOK_UPD_COL;  return TOK_COMMA;

"<"                TOK_UPD_COL;  return TOK_LANGLE;
">"                TOK_UPD_COL;  return TOK_RANGLE;
"*"                TOK_UPD_COL;  return TOK_STAR;
"&"                TOK_UPD_COL;  return TOK_AMPERSAND;
"="                TOK_UPD_COL;  return TOK_EQUALS;
":"                TOK_UPD_COL;  return TOK_COLON;

"class"            TOK_UPD_COL;  return TOK_CLASS;
"option"           TOK_UPD_COL;  return TOK_OPTION;
"new"              TOK_UPD_COL;  return TOK_NEW;
"enum"             TOK_UPD_COL;  return TOK_ENUM;

  /* --------- embedded text --------- */
("public"|"protected"|"private"|"ctor"|"dtor"|"pure_virtual"|"define_customizable")("(")? {
  TOK_UPD_COL;

  if (prevToken==TOK_COLON || prevToken==TOK_COMMA) {
    // FREAKING UGLY HACK: Normally, access control keywords introduce
    // a verbatim section.  But I want to also use them in the syntax
    // for base classes, to be similar to C++.  But that means that I
    // have to somehow distinguish those contexts.  As it happens, the
    // previous token can be used to make the distinction.  So, here
    // we are in that context, so don't do verbatim stuff.
    //
    // Of course, this is an awfully fragile approach.  I'd like to
    // redesign the verbatim-field syntax at some point to eliminate
    // this problem, but since I don't know what a good syntax might
    // be, I'll leave things alone for now.

    // better not have used a paren..
    if (YY_TEXT[YY_LENG-1] == '(') {
      // I'm tempted to make a smart-ass error message... resisting...... *phew*!
      err("don't put a paren after a base class access control keyword");

      // now I'm tempted to change the error reporting so that all
      // error messages are prefixed with "(SNL donatella versaci
      // voice) you crazy bitch!"  hmm.. maybe too much sugar today?
    }
  }
  else {
    // the keyword introduces a verbatim section

    // is a paren included?
    if (YY_TEXT[YY_LENG-1] == '(') {
      // don't drop into embedded just yet; wait for the ')'
      embedStart = ')';
      YY_LESS_TEXT(YY_LENG-1);
      advCol(-1);
    }
    else {
      YY_SET_START_CONDITION(EMBED);
    }

    embedded->reset();
    embedFinish = ';';
    allowInit = YY_TEXT[0]=='p';
    embedMode = TOK_EMBEDDED_CODE;
  }

  // Recognize which keyword was used by looking for a unique character
  // at certain positions.  (This is a bit weird and ad-hoc, but
  // whatever.)
  return YY_TEXT[0]=='c'?   TOK_CTOR :
         YY_TEXT[1]== 'e'?  TOK_DEFINE_CUSTOMIZABLE :
         YY_TEXT[0]=='d'?   TOK_DTOR :
         YY_TEXT[2] == 'b'? TOK_PUBLIC :
         YY_TEXT[2] == 'o'? TOK_PROTECTED :
         YY_TEXT[2] == 'i'? TOK_PRIVATE :
              /*[2] == 'r'*/TOK_PURE_VIRTUAL ;
}

("verbatim"|"impl_verbatim") {
  TOK_UPD_COL;

  // need to see one more token before we begin embedded processing
  embedStart = '{';
  embedFinish = '}';
  allowInit = false;

  embedded->reset();
  embedMode = TOK_EMBEDDED_CODE;
  switch (YY_TEXT[0]) {
  default: xfailure("can't happen");
  case 'v': return TOK_VERBATIM;
  case 'i': return TOK_IMPL_VERBATIM;
  }
}

"custom" {
  TOK_UPD_COL;

  embedStart = '{';
  embedFinish = '}';
  allowInit = false;
  embedded->reset();
  embedMode = TOK_EMBEDDED_CODE;

  return TOK_CUSTOM;
}

  /* punctuation that can start embedded code */
("{"|")") {
  TOK_UPD_COL;
  if (YY_TEXT[0] == embedStart) {
    YY_SET_START_CONDITION(EMBED);
  }
  return YY_TEXT[0]=='{'? TOK_LBRACE : TOK_RPAREN;
}


  /* no TOKEN_START here; we'll use the tokenStartLoc that
   * was computed in the opening punctuation */
<EMBED>{
  /* no special significance to lexer */
  [^;}=\n]+ {
    UPD_COL;
    embedded->handle(YY_TEXT, YY_LENG, embedFinish);
  }

  "\n" {
    newLine();
    embedded->handle(YY_TEXT, YY_LENG, embedFinish);
  }

  /* possibly closing delimiter */
  ("}"|";"|"=") {
    UPD_COL;

    // we're done if we're at a zero nesting level and the
    // delimiter matches ...
    if (embedded->zeroNesting() && embedFinishMatches(YY_TEXT[0])) {
      // done
      YY_SET_START_CONDITION(INITIAL);

      if (YY_TEXT[0] == '=') {
        // switch to a special mode that will handle the '=' and
        // jump right back into embedded mode
        YY_SET_START_CONDITION(INITVAL);
      }
      else {
        // turn off embedded detection
        embedStart = 0;
      }

      // put back delimeter so parser will see it
      YY_LESS_TEXT(YY_LENG-1);
      advCol(-1);

      // in the abstract grammar we don't have embedded expressions
      embedded->exprOnly = false;

      // and similarly for the other flag
      embedded->isDeclaration = (embedFinish == ';');

      // caller can get text from embedded->text
      return embedMode;
    }
    else {
      // embedded delimeter, mostly ignore it
      embedded->handle(YY_TEXT, YY_LENG, embedFinish);
    }
  }
}


<INITVAL>{
  "=" {
    // yield the '=', switch back into embedded
    TOK_UPD_COL;
    YY_SET_START_CONDITION(EMBED);
    embedded->reset();
    allowInit = false;
    return TOK_EQUALS;
  }

  {ANY} {
    xfailure("somehow got a char other than '=' in INITVAL state");
  }
}


  /* -------- name literal --------- */
{LETTER}({LETTER}|{DIGIT})* {
  // get text from YY_TEXT and YY_LENG
  TOK_UPD_COL;
  return TOK_NAME;
}

  /* --------- integer literal --------- */
{DIGIT}+ {
  TOK_UPD_COL;
  return TOK_INTLIT;
}

  /* --------- illegal ------------- */
{ANY} {
  TOK_UPD_COL;
  errorIllegalCharacter(YY_TEXT[0]);
}


%%
/* -------------------- additional C code -------------------- */

bool isAGramlexEmbed(int code)
{
  return code == TOK_EMBEDDED_CODE;
}
