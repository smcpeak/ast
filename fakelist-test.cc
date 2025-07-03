// fakelist-test.cc
// Exercise FakeList.

#include "ast/fakelist.h"              // module under test
#include "ast/fakelist-gdvalue.h"      // module extension under test

#include "smbase/sm-macros.h"          // {OPEN,CLOSE}_ANONYMOUS_NAMESPACE
#include "smbase/sm-test.h"            // EXPECT_EQ

#include <iostream>                    // std::cout

using namespace gdv;
using namespace std;


OPEN_ANONYMOUS_NAMESPACE


class Node {
public:      // class data
  static int s_nodeCount;

public:      // instance data
  int m_x;
  Node *next;

public:      // methods
  explicit Node(int x)
    : m_x(x),
      next(NULL)
  {
    s_nodeCount++;
  }

  ~Node()
  {
    s_nodeCount--;
  }

  operator GDValue() const
  {
    return GDVTaggedMap(GDVSymbol("Node"), {
      GDV_SKV("x", m_x),

      // The `next` link is *not* serialized here because the intention
      // is it is the link of a `FakeList`, and the code that serializes
      // FakeLists will traverse that.
    });
  }

  explicit Node(GDValue const &v)
    : m_x(gdvTo<int>(mapGetSym_parse(v, "x"))),
      next(nullptr)
  {
    checkTaggedMapTag(v, "Node");
  }
};

int Node::s_nodeCount = 0;


CLOSE_ANONYMOUS_NAMESPACE


template <>
struct gdv::GDVToNew<Node> {
  static Node *f(GDValue const &v)
  {
    return new Node(v);
  }
};


OPEN_ANONYMOUS_NAMESPACE


void printList(FakeList<Node> *list)
{
  cout << "list:";

  FAKELIST_FOREACH(Node, list, iter) {
    cout << " " << iter->m_x;
  }

  cout << endl;
}


// Convert `orig` to GDV and back, verifying the result is the same.
// Also check that the serialized form is `expectGDVN`.
void testGDVCycle(FakeList<Node> const *orig, char const *expectGDVN)
{
  VPVAL(expectGDVN);

  GDValue v(toGDValue(orig));
  EXPECT_EQ(v.asString(), expectGDVN);

  FakeList<Node> *after = gdvTo<FakeList<Node>*>(v);

  EXPECT_EQ(fl_count(after), fl_count(orig));

  for (int i=0; i < fl_count(orig); ++i) {
    Node const *origNode = fl_nthC(orig, i);
    Node const *afterNode = fl_nthC(after, i);

    EXPECT_EQ(afterNode->m_x, origNode->m_x);
  }
}


CLOSE_ANONYMOUS_NAMESPACE


int main()
{
  // These tests are pretty light.  example-test.cc has a bit more.

  FakeList<Node> *list = FakeList<Node>::emptyList();
  printList(list);
  xassert(fl_isEmpty(list));

  testGDVCycle(list, "[]");

  Node *n1 = new Node(1);
  list = fl_prepend(list, n1);
  printList(list);
  xassert(fl_isNotEmpty(list));

  testGDVCycle(list, "[Node{x:1}]");

  list = fl_prepend(list, new Node(2));
  EXPECT_EQ(fl_count(list), 2);

  testGDVCycle(list, "[Node{x:2} Node{x:1}]");

  fl_deallocNodes(list);

  xassert(Node::s_nodeCount == 0);

  cout << "fakelist-test passed\n";
  return 0;
}


// EOF
