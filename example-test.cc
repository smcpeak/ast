// example-test.cc
// Exercise the API generated from example.ast.

// This is currently a pretty minimal test.  Expanding it is a TODO.

#include "example.ast.gen.h"           // module under test

#include <iostream>                    // cout

using namespace std;


void testNode()
{
  Node *n1 = new Node(1,2);
  xassert(n1->x == 1);
  xassert(n1->y == 2);
  xassert(n1->w == 3);
  n1->debugPrint(cout, 0);
  delete n1;
}


void testNodeList()
{
  FakeList<Node> *list = FakeList<Node>::emptyList();
  list = fl_prepend(list, new Node(7,8));
  list = fl_prepend(list, new Node(4,5));
  list = fl_prepend(list, new Node(1,2));

  NodeList *nlist = new NodeList(list);
  nlist->debugPrint(cout, 0);
  fl_deallocNodes(nlist->list);
  delete nlist;
}


int main()
{
  testNode();
  testNodeList();

  cout << "example-test passed\n";
  return 0;
}


// EOF
