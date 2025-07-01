// locstr-test.cc
// Tests for `locstr`.
// See license.txt for copyright and terms of use.

#include "ast/locstr.h"                // module under test

#include "smbase/gdvalue.h"            // gdv::toGDValue
#include "smbase/sm-test.h"            // EXPECT_EQ

using namespace gdv;


int main()
{
  // Just some arbitrary location.
  SourceLoc loc = (SourceLoc)3;

  StringTable table;
  StringRef str = table.add("xyz");

  LocString locstr(loc, str);

  EXPECT_EQ(toGDValue(locstr).asString(),
    "LocString(3 \"xyz\")");

  return 0;
}


// EOF
