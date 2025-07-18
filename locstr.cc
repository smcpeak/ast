// locstr.cc            see license.txt for copyright and terms of use
// code for locstr.h

#include "locstr.h"                    // this module

#include "smbase/gdvalue.h"            // gdv::GDValue
#include "smbase/gdvalue-parser.h"     // gdv::GDValueParser
#include "smbase/xassert.h"            // xassert, smbase::xassertPtr

using namespace gdv;
using namespace smbase;


LocString::LocString()
  : loc(SL_UNKNOWN),
    str(NULL)           // problem with "" is we don't have the string table here..
{}

LocString::LocString(LocString const &obj)
  : loc(obj.loc),
    str(obj.str)
{}

LocString::LocString(SourceLoc L, StringRef s)
  : loc(L),
    str(s)
{}


LocString::LocString(Flatten&)
  : loc(SL_UNKNOWN), str(NULL)
{}

void LocString::xfer(Flatten &flat)
{
  // doh.. flattening locs is hard.  I wasn't even doing
  // it before.  issues:
  //   - don't want to store the file name lots of times
  //   - what if the file goes away, or we're in a different directory?
  //   - what if the file is changed, what loc to use then?
  // so for now I'm punting and not saving the loc at all...

  xassert(flattenStrTable);
  flattenStrTable->xfer(flat, str);
}


void LocString::copyAndDel(LocString *obj)
{
  loc = obj->loc;
  str = obj->str;
  delete obj;
}

LocString *LocString::clone() const
{
  return new LocString(*this);
}


bool LocString::equals(char const *other) const
{
  if (!str) {
    return !other;                            // equal if both null
  }
  else {
    return other && streq(str, other); // or same contents
  }
}

string toString(LocString const &s)
{
  return string(s.str);
}


LocString::operator GDValue() const
{
  return GDVTaggedTuple(GDVSymbol("LocString"), {
    toGDValue(static_cast<int>(loc)),
    toGDValue(str),
  });
}


LocString::LocString(GDValueParser const &p)
  : loc(static_cast<SourceLoc>(gdvpTo<int>(
      p.tupleGetValueAt(0)))),
    str(xassertPtr(flattenStrTable)->add(gdvpTo<std::string>(
      p.tupleGetValueAt(1))))
{
  p.checkContainerTag("LocString");
}


// EOF
