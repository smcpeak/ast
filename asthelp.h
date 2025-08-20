// asthelp.h            see license.txt for copyright and terms of use
// included by generated ast code

#ifndef AST_ASTHELP_H
#define AST_ASTHELP_H

#include "ast/fakelist.h"              // FakeList
#include "ast/locstr.h"                // LocString

#include "smbase/astlist.h"            // ASTList
#include "smbase/ast-switch.h"         // ASTSWITCH, etc., for client code
#include "smbase/str.h"                // string
#include "smbase/sm-iostream.h"        // ostream

#include <vector>                      // std::vector


// 2025-08-20: This file previously defined ASTSWITCH, etc.  Now those
// macros are in `smbase/ast-switch.h` to allow them to be used without
// the rest of the astgen baggage.  This file continues to include it
// for client compatibility.


// ------------------- debug print helpers -----------------
ostream &ind(ostream &os, int indent);

// I occasionally want to see addresses, so I just throw this
// switch and recompile..
#if 1
  // headers w/o addresses
  #define PRINT_HEADER(subtreeName, clsname)                 \
    ind(os, indent) << subtreeName << " = " #clsname ":\n";  \
    indent += 2   /* user ; */
#else
  // headers w/ addresses
  #define PRINT_HEADER(subtreeName, clsname)                                           \
    ind(os, indent) << subtreeName << " = " #clsname " (" << ((void*)this) << "):\n";  \
    indent += 2   /* user ; */
#endif


#define PRINT_STRING(var) \
  debugPrintStr((var), #var, os, indent)    /* user ; */

void debugPrintStr(string const &s, char const *name,
                   ostream &os, int indent);
void debugPrintStr(char const *s, char const *name,
                   ostream &os, int indent);


#define PRINT_CSTRING(var) \
  debugPrintCStr(var, #var, os, indent)    /* user ; */

void debugPrintCStr(char const *s, char const *name,
                    ostream &os, int indent);


#define PRINT_LIST(T, list) \
  debugPrintList(list, #list, os, indent)     /* user ; */

template <class T>
void debugPrintList(ASTList<T> const &list, char const *name,
                    ostream &os, int indent)
{
  ind(os, indent) << name << ":\n";
  int ct=0;
  {
    FOREACH_ASTLIST(T, list, iter) {
      iter.data()->debugPrint(os, indent+2,
        stringbc(name << "[" << ct++ << "]"));
    }
  }
}

// provide explicit specialization for strings
void debugPrintList(ASTList<string> const &list, char const *name,
                    ostream &os, int indent);
void debugPrintList(ASTList<LocString> const &list, char const *name,
                    ostream &os, int indent);


#define PRINT_FAKE_LIST(T, list) \
  debugPrintFakeList(list, #list, os, indent)     /* user ; */

template <class T>
void debugPrintFakeList(FakeList<T> const *list, char const *name,
                        ostream &os, int indent)
{
  ind(os, indent) << name << ":\n";
  int ct=0;
  {
    FAKELIST_FOREACH(T, list, iter) {
      iter->debugPrint(os, indent+2,
        stringbc(name << "[" << ct++ << "]"));
    }
  }
}

// note that we never make FakeLists of strings, since of course
// strings do not have a 'next' pointer


#define PRINT_POINTER_VECTOR(vec) \
  debugPrintPointerVector(vec, #vec, os, indent)     /* user ; */

template <class T>
void debugPrintPointerVector(std::vector<T*> const &vec, char const *name,
                             ostream &os, int indent)
{
  ind(os, indent) << name << ":\n";
  int ct=0;
  {
    for (T const *t : vec) {
      string label = stringb(name << "[" << ct++ << "]");
      if (t) {
        t->debugPrint(os, indent+2, label.c_str());
      }
      else {
        ind(os, indent) << label << " is null\n";
      }
    }
  }
}


#define PRINT_SUBTREE(tree)                     \
  if (tree) {                                   \
    (tree)->debugPrint(os, indent, #tree);      \
  }                                             \
  else {                                        \
    ind(os, indent) << #tree << " is null\n";   \
  } /* user ; (optional) */


#define PRINT_GENERIC(var) \
  ind(os, indent) << #var << " = " << ::toString(var) << "\n"   /* user ; */


#define PRINT_BOOL(var) \
  ind(os, indent) << #var << " = " << (var? "true" : "false") << "\n"   /* user ; */


// ---------------------- deep-copy ------------------
// returns a new'd list because the AST node ctors want
// to accept an owner ptr to a list
template <class T>
ASTList<T> * /*owner*/ cloneASTList(ASTList<T> const &src)
{
  ASTList<T> *ret = new ASTList<T>;

  FOREACH_ASTLIST(T, src, iter) {
    ret->append(iter.data()->clone());
  }

  return ret;
}


// returns owner pointer to list of serfs.. using this isn't ideal
// because ASTList normally is owning, and probably deletes its
// elements in its destructor..
template <class T>
ASTList<T> * /*owner*/ shallowCloneASTList(ASTList<T> const &src)
{
  ASTList<T> *ret = new ASTList<T>;

  FOREACH_ASTLIST(T, src, iter) {
    // list backbone is const, but nodes' constness leaks away..
    ret->append(const_cast<T*>(iter.data()));
  }

  return ret;
}


// deep copy of a FakeList
template <class T>
FakeList<T> * /*owner*/ cloneFakeList(FakeList<T> const *src)
{
  if (!src) {
    return FakeList<T>::emptyList();     // base case of recursion
  }

  // clone first element
  T *head = fl_firstC(src)->clone();
  xassert(head->next == NULL);     // it had better not copy the list tail itself!

  // attach to result of cloning the tail
  FakeList<T> *tail = cloneFakeList(fl_butFirstC(src));
  return fl_prepend(tail, head);
}


#endif // AST_ASTHELP_H
