// locstr.h            see license.txt for copyright and terms of use
// location & string table reference

#ifndef AST_LOCSTR_H
#define AST_LOCSTR_H

#include "smbase/sm-iostream.h"        // ostream
#include "smbase/srcloc.h"             // SourceLoc
#include "smbase/strtable.h"           // StringRef

#include <string.h>                    // strlen


class LocString {
public:    // data
  SourceLoc loc;
  StringRef str;

public:    // funcs
  LocString();
  LocString(LocString const &obj);
  LocString(SourceLoc loc, StringRef str);

  LocString(Flatten&);
  void xfer(Flatten &flat);

  // deallocates its argument; intended for convenient use in bison grammar files
  EXPLICIT LocString(LocString *obj) { copyAndDel(obj); }
  void copyAndDel(LocString *obj);

  // sometimes useful for generating arguments to the above ctor
  LocString *clone() const;

  LocString& operator= (LocString const &obj)
    { loc = obj.loc; str = obj.str; return *this; }

  // string with location info
  string locString() const { return toString(loc); }

  // (read-only) string-like behavior
  friend ostream& operator<< (ostream &os, LocString const &loc)
    { return os << loc.str; }
  friend stringBuilder& operator<< (stringBuilder &sb, LocString const &loc)
    { return sb << loc.str; }
  StringRef strref() const { return str; }
  operator StringRef () const { return str; }
  char operator [] (int index) const { return str[index]; }
  bool equals(char const *other) const;    // string comparison
  int length() const { return strlen(str); }

  // experimenting with allowing 'str' to be null, which is convenient
  // when the string table isn't available
  bool isNull() const { return str == NULL; }
  bool isNonNull() const { return !isNull(); }

  bool validLoc() const { return loc != SL_UNKNOWN; }
};

// yields simply the string, no location info
string toString(LocString const &s);


// useful for constructing literal strings in source code
#define LITERAL_LOCSTRING(str)                                   \
  LocString(HERE_SOURCELOC, str)


#endif // AST_LOCSTR_H
