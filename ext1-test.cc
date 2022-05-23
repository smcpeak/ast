// ext1-test.cc
// Exercise the API generated from example.ast+ext1.ast.

#include "ext1.ast.gen.h"              // module under test

#include <iostream>                    // cout

using namespace std;


static void testPreprint()
{
  cout << "---- testPreprint ----\n";
  TypeSpecifier ts;
  int x = 2;
  ts.preprint(x);
  xassert(x == 3);
}


int main()
{
  testPreprint();

  cout << "ext1-test passed\n";
  return 0;
}


// EOF
