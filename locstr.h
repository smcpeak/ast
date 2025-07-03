// locstr.h            see license.txt for copyright and terms of use
// location & string table reference

#ifndef AST_LOCSTR_H
#define AST_LOCSTR_H

#include "smbase/gdvalue-fwd.h"        // gdv::GDValue
#include "smbase/gdvalue-parse.h"      // gdv::GDVTo
#include "smbase/sm-iostream.h"        // ostream
#include "smbase/srcloc.h"             // SourceLoc
#include "smbase/strtable.h"           // StringRef

#include <string.h>                    // strlen


class LocString {
public:    // data
  // A place in some input where `str` occurred.
  SourceLoc loc;

  // The string that appeared in the input.
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

  // Returns a tagged tuple with the location as an integer offset into
  // the virtually concatenated input, followed by the string.  The
  // integer is not easy to interpret, but could be used as part of a
  // round-trip within the same process at least.
  operator gdv::GDValue() const;

  // Parse a value previously converted from `LocString`.
  explicit LocString(gdv::GDValue const &v);
};

// yields simply the string, no location info
string toString(LocString const &s);

template <>
struct gdv::GDVTo<LocString> {
  static LocString f(GDValue const &v)
  {
    return LocString(v);
  }
};


// useful for constructing literal strings in source code
#define LITERAL_LOCSTRING(str)                                   \
  LocString(HERE_SOURCELOC, str)


#endif // AST_LOCSTR_H
