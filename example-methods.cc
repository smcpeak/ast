// example-methods.cc
// Methods declared in example.ast that need to be defined.

#include "example.ast.gen.h"           // method declarations


// --------------------- Super ------------------------
int Super::foo()
{
  return 1;
}

int Super::everywhere()
{
  return 2;
}


// --------------------- Sub1 ------------------------
int Sub1::foo()
{
  return 11;
}

int Sub1::onlyInSubclasses()
{
  return 12;
}

int Sub1::everywhere()
{
  return 13;
}


// --------------------- Sub2 ------------------------
int Sub2::foo()
{
  return 11;
}

int Sub2::onlyInSubclasses()
{
  return 12;
}

int Sub2::everywhere()
{
  return 13;
}


// --------------------- SubWithDefault ------------------------
int SubWithDefault::foo()
{
  return 11;
}

int SubWithDefault::onlyInSubclasses()
{
  return 12;
}

int SubWithDefault::everywhere()
{
  return 13;
}


// --------------------- Sub3 ------------------------
int Sub3::foo()
{
  return 11;
}

int Sub3::onlyInSubclasses()
{
  return 12;
}

int Sub3::everywhere()
{
  return 13;
}


// EOF
