// fakelist-gdvalue.h
// Functions involving `FakeList` and `GDValue`.
// See license.txt for copyright and terms of use.

#ifndef AST_FAKELIST_GDVALUE_H
#define AST_FAKELIST_GDVALUE_H

#include "ast/fakelist.h"              // FakeList

#include "smbase/gdvalue.h"            // gdv::GDValue
#include "smbase/gdvalue-parse.h"      // gdv::gdvTo


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


template <typename T>
struct gdv::GDVTo<FakeList<T> *> {
  static FakeList<T> *f(GDValue const &s)
  {
    checkIsSequence(s);

    FakeList<T> *ret = FakeList<T>::emptyList();

    for (auto const &element : s.sequenceGet()) {
      ret = fl_prepend(ret, gdv::gdvToNew<T>(element));
    }

    // As usual for FakeList, we build it in reverse order initially.
    ret = fl_reverse(ret);

    return ret;
  }
};


#endif // AST_FAKELIST_GDVALUE_H
