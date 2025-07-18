// fakelist-gdvalue.h
// Functions involving `FakeList` and `GDValue`.
// See license.txt for copyright and terms of use.

#ifndef AST_FAKELIST_GDVALUE_H
#define AST_FAKELIST_GDVALUE_H

#include "ast/fakelist.h"              // FakeList

#include "smbase/gdvalue.h"            // gdv::GDValue
#include "smbase/gdvalue-parser.h"     // gdv::GDValueParser


// Convert `lst` to a GDV sequence.
template <typename T>
gdv::GDValue toGDValue(FakeList<T> const *lst)
{
  using namespace gdv;

  gdv::GDValue s(GDVK_SEQUENCE);

  FAKELIST_FOREACH(T, lst, element) {
    s.sequenceAppend(toGDValue(*element));
  }

  return s;
}


template <typename T>
struct gdv::GDVPTo<FakeList<T> *> {
  static FakeList<T> *f(gdv::GDValueParser const &p)
  {
    p.checkIsSequence();

    FakeList<T> *ret = FakeList<T>::emptyList();

    // Iterate with an index so we can keep track of the path.
    for (gdv::GDVIndex i=0; i < p.containerSize(); ++i) {
      ret = fl_prepend(ret, gdv::gdvpToNew<T>(p.sequenceGetValueAt(i)));
    }

    // As usual for FakeList, we build it in reverse order initially.
    ret = fl_reverse(ret);

    return ret;
  }
};


#endif // AST_FAKELIST_GDVALUE_H
