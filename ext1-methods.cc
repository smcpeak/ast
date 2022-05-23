// ext1-methods.cc
// Methods declared in ext1.ast.

#include "ext1.ast.gen.h"              // method declarations


// ------------------------------ Super --------------------------------
int Sub4::foo()
{
  return 41;
}

int Sub4::onlyInSubclasses()
{
  return 4;
}

int Sub4::everywhere()
{
  return 441;
}


// -------------------------- TypeSpecifier ----------------------------
void TypeSpecifier::preprint_attrSpecList(int &env) const
{
  env = 3;
}


// EOF
