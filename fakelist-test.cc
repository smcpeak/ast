// fakelist-test.cc
// Exercise FakeList.

#include "fakelist.h"                  // module under test

#include <iostream>                    // std::cout

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

  Node *n1 = new Node(1);
  list = fl_prepend(list, n1);
  printList(list);
  xassert(fl_isNotEmpty(list));

  fl_deallocNodes(list);

  xassert(Node::s_nodeCount == 0);

  cout << "fakelist-test passed\n";
  return 0;
}


// EOF
