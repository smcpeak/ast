// ccsstr-test.cc
// Tests for ccsstr.cc.

#include "ccsstr.h"                    // module under test

#include "strutil.h"                   // replace
#include "xassert.h"                   // xassert


#define CC CCSubstrate
#define Test CCSubstrateTest

// test code is put into a class just so that CCSubstrate
// can grant it access to private fields
class Test {
public:
  void feed(CC &cc, rostring src);
  void test(rostring src, CC::State state, int nesting, bool flag);
  void normal(rostring src, int nesting);
  void str(rostring src, int nesting, bool bs);
  void yes(rostring src);
  void no(rostring src);
  void name(rostring body, rostring n);
  void badname(rostring body);
  int main();
};


#define min(a,b) ((a)<(b)?(a):(b))

void Test::feed(CC &cc, rostring origSrc)
{
  char const *src = toCStr(origSrc);

  //cout << "trying: " << src << endl;
  while (*src) {
    // feed it in 10 char increments, to test split processing too
    int len = min(strlen(src), 10);
    cc.handle(src, len, '}');
    src += len;
  }
}


void Test::test(rostring src, CC::State state, int nesting, bool flag)
{
  CC cc(&silentReportError);
  feed(cc, src);

  if (!( cc.state == state &&
         cc.nesting == nesting &&
         (state==CC::ST_C_COMMENT? cc.star==flag :
                                   cc.backslash==flag) )) {
    xfailure(stringc << "failed on src: " << src);
  }
}


void Test::normal(rostring src, int nesting)
{
  test(src, CC::ST_NORMAL, nesting, false);
}

void Test::str(rostring src, int nesting, bool bs)
{
  test(src, CC::ST_STRING, nesting, bs);

  // repeat the test with single-tick
  string another = replace(src, "\"", "\'");
  test(another, CC::ST_CHAR, nesting, bs);
}


void Test::yes(rostring src)
{
  CC cc(&silentReportError);
  feed(cc, src);

  xassert(cc.zeroNesting());
}

void Test::no(rostring src)
{
  CC cc(&silentReportError);
  feed(cc, src);

  xassert(!cc.zeroNesting());
}

void Test::name(rostring body, rostring n)
{
  CC cc(&silentReportError);
  feed(cc, body);
  xassert(cc.getDeclName().equals(n));
}

void Test::badname(rostring body)
{
  CC cc(&silentReportError);
  feed(cc, body);
  try {
    cc.getDeclName();
    xfailure("got a name when it shoudn't have!");
  }
  catch (...)
    {}
}


int Test::main()
{
  normal("int main()", 0);
  normal("int main() { hi", 1);
  normal("int main() { hi {", 2);
  normal("int main() { hi { foo[5", 3);
  normal("int main() { hi { foo[5] and ", 2);
  normal("int main() { hi { foo[5] and } bar ", 1);
  normal("int main() { hi { foo[5] and } bar } baz ", 0);

  normal("main() { printf(\"hello \\ world\"); ret", 1);

  normal("()[]{}([{}])", 0);
  normal("{ ()[]{}([{}]) } ", 0);
  normal("( ()[]{}([{}]) )", 0);
  normal("[ ()[]{}([{}]) ]", 0);
  normal("\"foo\" ()[]{}([{}])", 0);

  str("main() { printf(\"hello", 2, false);
  str("main() { printf(\"hello \\", 2, true);
  str("main() { printf(\"hello \\ world", 2, false);
  str("main() { printf(\"hello \\ world\", \"hi", 2, false);

  test("\"a\" 'b' (", CC::ST_NORMAL, 1, false);

  yes("main() {}");
  yes("main() { printf(\"foo\", 3, 4 /*yep{*/); }");
  yes("some // junk {\n more");
  yes("'\\''");
  yes("\"\\\"\"");
  yes("[][][][][]");
  yes("\"[[[\"");
  yes("*");
  yes("/* [ /* [ */");

  no("\"");
  no("(");
  no(" ( /* ) */ ");

  name("int main()", "main");
  name("int eval(Environment &env)", "eval");
  name("man()", "man");
  badname("(");
  badname("  (");
  badname("  ");
  badname("");
  badname(")");
  badname("main");

  cout << "\nccsstr: all tests PASSED\n";

  return 0;
}

int main()
{
  Test t;
  return t.main();
}


// EOF
