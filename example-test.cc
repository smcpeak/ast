// example-test.cc
// Exercise the API generated from example.ast.

// This is currently a pretty minimal test.  Expanding it is a TODO.

#include "example.ast.gen.h"           // module under test

#include "smbase/gdvalue-parser.h"     // gdv::GDValueParser
#include "smbase/gdvalue.h"            // gdv::toGDValue
#include "smbase/save-restore.h"       // SET_RESTORE
#include "smbase/sm-test.h"            // EXPECT_EQ
#include "smbase/strtable.h"           // flattenStrTable

#include <iostream>                    // std::cout
#include <memory>                      // std::unique_ptr

using namespace gdv;
using namespace std;


static void testNode()
{
  cout << "---- testNode ----\n";

  std::unique_ptr<Node> n1(new Node(1,2));
  xassert(n1->x == 1);
  xassert(n1->y == 2);
  xassert(n1->w == 3);
  n1->debugPrint(cout, 0);

  GDValue v(toGDValue(*n1));
  EXPECT_EQ(v.asString(), "Node{w:3 x:1 y:2}");

  std::unique_ptr<Node> n2(gdvpToNew<Node>(GDValueParser(v)));
  EXPECT_EQ(n2->x, n1->x);
  EXPECT_EQ(n2->y, n1->y);
  EXPECT_EQ(n2->w, n1->w);
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

  GDValue v(toGDValue(*nlist));
  EXPECT_EQ(v.asString(),
    "NodeList{list:["
      "Node{w:3 x:1 y:2} "
      "Node{w:3 x:4 y:5} "
      "Node{w:3 x:7 y:8}"
    "]}");

  NodeList *nlist2 = gdvpToNew<NodeList>(GDValueParser(v));
  GDValue v2(toGDValue(*nlist2));
  EXPECT_EQ(v, v2);

  fl_deallocNodes(nlist->list);
  delete nlist;

  fl_deallocNodes(nlist2->list);
  delete nlist2;
}


static void testAnotherList()
{
  ASTList<Node> *list2 = new ASTList<Node>();
  list2->append(new Node(1,2));

  StringTable table;
  StringRef s = table.add("bar");

  std::unique_ptr<AnotherList> list(new AnotherList(
    list2,
    new LocString((SourceLoc)5, s)));

  GDValue v(*list);
  EXPECT_EQ(v.asString(),
    "AnotherList{list2:[Node{w:3 x:1 y:2}] "
                "str:LocString(5 \"bar\")}");

  // Deserialize using `table`.
  SET_RESTORE(flattenStrTable, &table);

  std::unique_ptr<AnotherList> list3(
    gdvpToNew<AnotherList>(GDValueParser(v)));
  EXPECT_EQ(toGDValue(*list3), v);
}


static void testOneSuperCycle(Super const *orig, char const *expectGDVN)
{
  GDValue v(*orig);
  EXPECT_EQ(v.asString(), expectGDVN);

  std::unique_ptr<Super> after(gdv::gdvpToNew<Super>(GDValueParser(v)));
  EXPECT_EQ(toGDValue(*after), v);
}


static void testSuper()
{
  // Note: The `p` field of `Super` does not get emitted because it is
  // not marked with the "field" attribute.

  std::unique_ptr<Sub1> sub1(new Sub1(7, 4));
  testOneSuperCycle(sub1.get(),
    "Sub1{x:7 y:4}");

  std::unique_ptr<SubWithDefault> subWD(new SubWithDefault(9));
  testOneSuperCycle(subWD.get(),
    "SubWithDefault{q:5 x:9}");

  std::unique_ptr<Sub3> sub3(new Sub3(
    11,
    new Sub1(13, 17),
    new Sub2(19, 23)));
  testOneSuperCycle(sub3.get(),
    "Sub3{s1:Sub1{x:13 y:17} s2:Sub2{x:19 z:23} x:11}");
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


static void testHasStdString()
{
  HasStdString hss(std::string("hi"));
  hss.gdb();
  EXPECT_EQ(hss.m_str, std::string("hi"));
  EXPECT_EQ(toGDValue(hss).asString(),
    "HasStdString{m_str:\"hi\"}");
}


int main()
{
  testNode();
  testNodeList();
  testAnotherList();
  testSuper();
  testMVisitor();
  testHasStdString();

  cout << "example-test passed\n";
  return 0;
}


// EOF
