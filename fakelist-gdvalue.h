// fakelist-gdvalue.h
// Functions involving `FakeList` and `GDValue`.
// See license.txt for copyright and terms of use.

#ifndef AST_FAKELIST_GDVALUE_H
#define AST_FAKELIST_GDVALUE_H

#include "ast/fakelist.h"              // FakeList

#include "smbase/gdvalue.h"            // gdv::GDValue


// Convert `lst` to a GDV sequence.
template <typename T>
gdv::GDValue toGDValue(FakeList<T> const *lst)
{
  using namespace gdv;

  GDValue s(GDVK_SEQUENCE);

  FAKELIST_FOREACH(T, lst, element) {
    s.sequenceAppend(toGDValue(*element));
  }

  return s;
}


#endif // AST_FAKELIST_GDVALUE_H
