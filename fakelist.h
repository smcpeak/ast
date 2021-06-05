// fakelist.h            see license.txt for copyright and terms of use
// headerless list of nodes where each node has a 'next' field

#ifndef FAKELIST_H
#define FAKELIST_H

#include "xassert.h"                   // xassert

#include <stddef.h>                    // NULL


// Purpose of this module: Define a templatized class such that a
// pointer to this class appears to present access to a list of the
// underlying T objects.  But in fact, the pointer is actually a T
// pointer, and T contains a field called 'next' which inductively
// defines the list contents.  Then such a pointer is used to provide
// documentation of the presence of the list (and not just one node),
// and a somewhat uniform (with other list interfaces) syntactic
// interface, while hiding an efficient representation.

// It is important that FakeLists be manipulated as pointers, as opposed
// to making the FakeList class be a wrapper around a pointer, because
// of a limitation of Elkhound semantic values.  In particular, those
// values are internally represented as intptr_t, and all semantic value
// types have to be compatible with that representation.

// why not just insist that all objects be derived from some
// base class, e.g. FakeListNode, that defines 'next'?  because
// what is the type of 'next'?  it has to be FakeListNode*, but
// then either it must be physically first, or else 'next' is
// a pointer to the interior and I have to worry about whether
// the casts to/from the outer type will be correctly offset; and
// then getting to the next node requires a cast (the usual
// problem with subtyping polymorphism)
//
// 2021-06-05: I think the above problem could be solved by inheriting
// a templatized base class, but I'll leave that idea on the table for
// now.

// The list is non-owning (unless you call 'deallocNodes').

// Constness is transitive in the sense that if you have a const
// FakeList, then all elements in it are accessible only as const.

class Some_undefined_class;

template <class T>
class FakeList {
private:
  // you can't create or delete one of these
  FakeList();
  ~FakeList();

  // silence a silly egcs-1.1.2 warning (this class isn't defined)
  friend class Some_undefined_class;

  // this class has *no* data--an object of this type is
  // never actually created!  instead we play with pointers
  // to this "type", and cast to T* as necessary

public:
  // Construct a list with one node.
  static FakeList<T> *makeList(T *node)
  {
    return reinterpret_cast<FakeList<T>*>(node);
  }

  // Construct an empty list.  It is also valid to just use NULL.
  static FakeList<T> *emptyList()
  {
    return NULL;
  }

  // NOTE: Since a NULL FakeList pointer is used to represent an empty
  // list, there are no methods, since invoking a method with a NULL
  // receiver is undefined.
  //
  // Instead everything is done with global functions that have the
  // "fl_" prefix (FakeList) for easy recognition.
};


// I'm deliberately contradicting the convention elsewhere, where
// "FOREACH" comes first; I think it should have come second to begin
// with, and since this class isn't derived from any of the others
// with the opposite convention, this is as good a place as any to
// reverse it

#define FAKELIST_FOREACH(NodeType, list, nodePtrVar)      \
  for (NodeType const *nodePtrVar = fl_firstC(list);      \
       nodePtrVar != NULL;                                \
       nodePtrVar = nodePtrVar->next)

#define FAKELIST_FOREACH_NC(NodeType, list, nodePtrVar)   \
  for (NodeType *nodePtrVar = fl_first(list);             \
       nodePtrVar != NULL;                                \
       nodePtrVar = nodePtrVar->next)


// True if the list is empty.
template <class T>
bool fl_isEmpty(FakeList<T> const *list)
{
  return list == NULL;
}

template <class T>
bool fl_isNotEmpty(FakeList<T> const *list)
{
  return !fl_isEmpty(list);
}


// First element of the list, or NULL if the list is empty.
template <class T>
T *fl_first(FakeList<T> *list)
{
  return reinterpret_cast<T*>(list);
}

template <class T>
T const *fl_firstC(FakeList<T> const *list)
{
  return reinterpret_cast<T const*>(list);
}


// List containing the second-and-later elements.
template <class T>
FakeList<T> *fl_butFirst(FakeList<T> *list)
{
  return FakeList<T>::makeList(fl_first(list)->next);
}

template <class T>
FakeList<T> const *fl_butFirstC(FakeList<T> const *list)
{
  return FakeList<T>::makeList(fl_firstC(list)->next);
}


// Make a list the starts with 'newHead', which is followed by 'list'.
template <class T>
FakeList<T> *fl_prepend(FakeList<T> *list, T *newHead)
{
  // I'm going to be surprised if this is ever not true.. it's
  // a potential problem in cc.gr, since I'm assuming there that
  // 'newHead' is not already on any other lists...
  //
  // update: This does occasionally get triggered, because a node
  // might get yielded to two contexts.  Failing this assertion is a
  // symptom that the sharing needs to be more carefully managed.
  // It's often the case that newHead->next in fact equals first()
  // already, but if the client code wants to let that slide it's
  // going to have to check itself; I don't want to silently allow
  // accidental happens-to-not-change-anything overwriting down in
  // this code.
  xassert(newHead->next == NULL);

  newHead->next = fl_first(list);
  return FakeList<T>::makeList(newHead);
}


template <class T>
int fl_count(FakeList<T> *list)
{
  int ct = 0;
  FAKELIST_FOREACH(T, list, p) {
    ct++;
  }
  return ct;
}


template <class T>
T const *fl_nthC(FakeList<T> const *list, int n)
{
  while (n > 0) {
    xassert(list != NULL);
    list = fl_butFirstC(list);
    n--;
  }
  return fl_firstC(list);
}


template <class T>
T *fl_nth(FakeList<T> *list, int n)
{
  return const_cast<T*>(fl_nthC(list, n));
}


// This will deallocate all the nodes in the list, leaving it empty.
template <class T>
void fl_deallocNodes(FakeList<T> *&list)
{
  T *p = fl_first(list);
  while (p) {
    T *next = p->next;

    // just in case T's destructor thinks it owns 'next',
    // nullify it since I'm going to dealloc it myself
    p->next = NULL;
    delete p;

    p = next;
  }

  list = NULL;
}


template <class T>
FakeList<T> *fl_reverse(FakeList<T> *src)
{
  FakeList<T> *dest = FakeList<T>::emptyList();

  while (fl_isNotEmpty(src)) {
    // remove first element of 'src'
    T *first = fl_first(src);
    src = fl_butFirst(src);
    first->next = NULL;

    // put it at the head of 'dest'
    dest = fl_prepend(dest, first);
  }

  return dest;
}


#endif // FAKELIST_H
