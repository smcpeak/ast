// fakelist-test.cc
// Exercise FakeList.

#include "ast/fakelist.h"              // module under test
#include "ast/fakelist-gdvalue.h"      // module extension under test

#include "smbase/sm-test.h"            // EXPECT_EQ

#include <iostream>                    // std::cout

using namespace gdv;
using namespace std;


class Node {
public:      // class data
  static int s_nodeCount;

public:      // instance data
  int m_x;
  Node *next;

public:      // methods
  Node(int x)
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
};

int Node::s_nodeCount = 0;


void printList(FakeList<Node> *list)
{
  cout << "list:";

  FAKELIST_FOREACH(Node, list, iter) {
    cout << " " << iter->m_x;
  }

  cout << endl;
}


int main()
{
  // These tests are pretty light.  example-test.cc has a bit more.

  FakeList<Node> *list = FakeList<Node>::emptyList();
  printList(list);
  xassert(fl_isEmpty(list));

  EXPECT_EQ(toGDValue(list).asString(), "[]");

  Node *n1 = new Node(1);
  list = fl_prepend(list, n1);
  printList(list);
  xassert(fl_isNotEmpty(list));

  EXPECT_EQ(toGDValue(list).asString(),
    "[Node{x:1}]");

  fl_deallocNodes(list);

  xassert(Node::s_nodeCount == 0);

  cout << "fakelist-test passed\n";
  return 0;
}


// EOF
