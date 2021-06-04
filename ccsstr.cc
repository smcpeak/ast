// ccsstr.cc            see license.txt for copyright and terms of use
// code for ccsstr.h

#include "ccsstr.h"      // this module
#include "xassert.h"     // xassert
#include "exc.h"         // xformat
#include "strutil.h"     // string, replace
#include "reporterr.h"   // silentReportError

#include "sm-iostream.h" // cout
#include <ctype.h>       // isspace


CCSubstrate::CCSubstrate(ReportError *err)
  : EmbeddedLang(err)
{
  reset();
}

void CCSubstrate::reset(int initNest)
{
  state = ST_NORMAL;
  nesting = initNest;
  backslash = false;
  star = false;
  text.setlength(0);
}


CCSubstrate::~CCSubstrate()
{}


void CCSubstrate::handle(char const *str, int len, char finalDelim)
{
  text.append(str, len);

  for (; len>0; len--,str++) {
    switch (state) {
      case ST_NORMAL:
        switch (*str) {
          case '{':
          case '(':
          case '[':
            nesting++;
            break;

          case '}':
          case ')':
          case ']':
            if (nesting == 0) {
              err->reportError(stringc
                << "unexpected closing delimiter `" << *str
                << "' -- probably due to missing `" << finalDelim << "'");
            }
            else {
              nesting--;
            }
            break;

          case '\"':
            state = ST_STRING;
            break;

          case '\'':
            state = ST_CHAR;
            break;

          case '/':
            state = ST_SLASH;
            break;
        }
        break;

      case ST_STRING:
      case ST_CHAR:
        if (!backslash) {
          if ((state == ST_STRING && *str == '\"') ||
              (state == ST_CHAR && *str == '\'')) {
            state = ST_NORMAL;
          }
          else if (*str == '\\') {
            backslash = true;
          }
          else if (*str == '\n') {
            err->reportError("unterminated string or char literal");
          }
        }
        else {
          backslash = false;
        }
        break;

      case ST_SLASH:
        if (*str == '*') {
          state = ST_C_COMMENT;
        }
        else if (*str == '/') {
          state = ST_CC_COMMENT;
        }
        else {
          state = ST_NORMAL;
        }
        break;

      case ST_C_COMMENT:
        if (!star) {
          if (*str == '*') {
            star = true;
          }
        }
        else {
          star = false;
          if (*str == '/') {
            state = ST_NORMAL;
          }
        }
        break;

      case ST_CC_COMMENT:
        // I don't like the possibility of escaped newlines
        // in C++ comments, so I don't support it (so there!)
        if (*str == '\n') {
          state = ST_NORMAL;
        }
        break;

      default:
        xfailure("unknown state");
    }
  }
}


bool CCSubstrate::zeroNesting() const
{
  return (state == ST_NORMAL || state == ST_SLASH) &&
         nesting == 0;
}


string CCSubstrate::getFuncBody() const
{
  if (isDeclaration) {
    // I used to be appending ';' here, but now I need the flexibility to
    // add additional test before it, so I will rely on the caller to add
    // semicolons where necessary
    return text;
  }
  else if (exprOnly) {
    return stringc << "return " << text << ";";
  }
  else {
    return text;
  }
}


string CCSubstrate::getDeclName() const
{
  // go with the rather inelegant heuristic that the word
  // just before the first '(' is the function's name
  char const *start = text.c_str();
  char const *p = start;

  // find first '('
  while (*p && *p!='(') { p++; }
  if (!*p) {
    xformat("missing '('");
  }
  if (p == start) {
    xformat("missing name");
  }

  // skip backward past any whitespace before the '('
  p--;
  while (p>=start && isspace(*p)) { p--; }
  if (p<start) {
    xformat("missing name");
  }
  char const *nameEnd = p+1;    // char just past last

  // move backward through the name
  while (p>=start &&
         (isalnum(*p) || *p=='_'))
    { p--; }
  p++;    // move back to most recent legal char

  // done
  return substring(p, nameEnd-p);
}


// EOF
