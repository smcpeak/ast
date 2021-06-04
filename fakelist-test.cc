// fakelist-test.cc
// Exercise FakeList.

#include "fakelist.h"                  // module under test

#include <iostream>                    // std::cout

#include <assert.h>                    // assert

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
  FakeList<Node> *list = FakeList<Node>::emptyList();
  printList(list);
  assert(list->isEmpty());

  Node *n1 = new Node(1);
  list = list->prepend(n1);
  printList(list);
  assert(list->isNotEmpty());

  list->deallocNodes();

  assert(Node::s_nodeCount == 0);

  cout << "fakelist-test passed\n";
  return 0;
}


// EOF
