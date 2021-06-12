// example-test.cc
// Exercise the API generated from example.ast.

// This is currently a pretty minimal test.  Expanding it is a TODO.

#include "example.ast.gen.h"           // module under test

#include <iostream>                    // cout

using namespace std;


static void testNode()
{
  cout << "---- testNode ----\n";

  Node *n1 = new Node(1,2);
  xassert(n1->x == 1);
  xassert(n1->y == 2);
  xassert(n1->w == 3);
  n1->debugPrint(cout, 0);
  delete n1;
}


static void testNodeList()
{
  cout << "---- testNodeList ----\n";

  FakeList<Node> *list = FakeList<Node>::emptyList();
  list = fl_prepend(list, new Node(7,8));
  list = fl_prepend(list, new Node(4,5));
  list = fl_prepend(list, new Node(1,2));

  NodeList *nlist = new NodeList(list);
  nlist->debugPrint(cout, 0);
  fl_deallocNodes(nlist->list);
  delete nlist;
}


class TestMVisitor : public ExampleMVisitor {
public:
  void postvisitSuper(Super *&obj) override;
  bool visitNode(Node *&node) override;
};

void TestMVisitor::postvisitSuper(Super *&obj)
{
  cout << "visiting Super: x=" << obj->x << '\n';

  ASTSWITCH(Super, obj) {
    ASTCASE(Sub3, s3) {
      // Replace the 's1' field.
      delete s3->s1;
      s3->s1 = new Sub2(5 /*x*/, 3 /*z*/);
    }

    ASTNEXT(Sub2, s2) {
      if (s2->z == 9) {
        // Replace this object.
        delete obj;
        obj = new Sub2(6 /*x*/, 4 /*z*/);
      }
    }

    ASTENDCASED
  }
}


bool TestMVisitor::visitNode(Node *&node)
{
  cout << "visiting Node: x=" << node->x << " y=" << node->y << '\n';

  Node *newNode = new Node(node->x + 1, node->y + 1);
  newNode->next = node->next;

  delete node;
  node = newNode;

  return true;
}


static void testMVisitor()
{
  cout << "---- testMVisitor ----\n";
  TestMVisitor mvisitor;

  {
    Super *tree = new Sub3(1 /*x*/,
      new Sub1(7 /*x*/, 2 /*y*/),
      new Sub2(8 /*x*/, 9 /*z*/));
    tree->debugPrint(cout, 0, "before");

    mvisitor.mtraverse(tree);
    tree->debugPrint(cout, 0, "after");

    delete tree;
  }

  {
    FakeList<Node> *list = FakeList<Node>::emptyList();
    list = fl_prepend(list, new Node(3,4));
    list = fl_prepend(list, new Node(1,2));
    NodeList *nodeList = new NodeList(list);
    nodeList->debugPrint(cout, 0, "before");

    mvisitor.mtraverse(nodeList);
    nodeList->debugPrint(cout, 0, "after");

    delete nodeList;
  }
}


int main()
{
  testNode();
  testNodeList();
  testMVisitor();

  cout << "example-test passed\n";
  return 0;
}


// EOF
