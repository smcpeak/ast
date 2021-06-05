#!/usr/bin/env python3
"""
Replace old FakeList API with new.

This modifies code that was invoking methods on FakeList pointers to
instead use the fl_XXX functions.  Once all relevant code has been
changed I'll probably delete this.
"""

import argparse              # argparse
import os                    # os.getenv
import re                    # re.compile
import signal                # signal.signal
import sys                   # sys.argv, sys.stderr
import time                  # time.sleep
import traceback             # traceback.print_exc


# -------------- BEGIN: boilerplate -------------
# These are things I add at the start of every Python program to
# allow better error reporting.

# Positive if debug is enabled, with higher values enabling more printing.
debugLevel = 0
if (os.getenv("DEBUG")):
  debugLevel = int(os.getenv("DEBUG"))

def debugPrint(str):
  """Debug printout when DEBUG >= 2."""
  if debugLevel >= 2:
    print(str)

# Ctrl-C: interrupt the interpreter instead of raising an exception.
signal.signal(signal.SIGINT, signal.SIG_DFL)

class Error(Exception):
  """A condition to be treated as an error."""
  pass

def die(message):
  """Throw a fatal Error with message."""
  raise Error(message)

def exceptionMessage(e):
  """Turn exception 'e' into a human-readable message."""
  t = type(e).__name__
  s = str(e)
  if s:
    return f"{t}: {s}"
  else:
    return f"{t}"

def call_main():
  """Call main() and catch exceptions."""
  try:
    main()

  except SystemExit as e:
    raise      # Let this one go, otherwise sys.exit gets "caught".

  except BaseException as e:
    print(f"{exceptionMessage(e)}", file=sys.stderr)
    if (debugLevel >= 1):
      traceback.print_exc(file=sys.stderr)
    sys.exit(2)
# --------------- END: boilerplate --------------


# Method call that looks like a FakeList call.
methodCallRE = re.compile(
  # 1. Receiver object.  Aside from non-space, non-exclam, non-paren
  # characters, tolerate a single pair of balanced parens with no parens
  # inside.
  r"((?:[^! ()]|\([^ ()]*\))+)->" +

  # 2. Method name.
  r"(isEmpty|isNotEmpty|first|firstC|butFirst|butFirstC|count|" +
   r"deallocNodes|reverse|prepend|nthC|nth)" +

  # 3. Arguments in parentheses.
  r"\(([^)]*)\)"
)

# Replacement for 'methodCallRE'.
def methodCallRepl(m):
  receiver = m.group(1)
  method = m.group(2)
  args = m.group(3)

  if args == "":
    return f"fl_{method}({receiver})"
  else:
    return f"fl_{method}({receiver}, {args})"


# Perform all required substitutions on 'line'.
def fixLine(line):
  line = methodCallRE.sub(methodCallRepl, line)
  return line


# Run a single test vector.
def testOne(input, expect):
  actual = fixLine(input)
  if actual != expect:
    print(f"Failed testOne:")
    print(f"  input : {input}")
    print(f"  expect: {expect}")
    print(f"  actual: {actual}")
    sys.exit(2)


# Run all test vectors.
def unitTests():
  testOne("list->isEmpty() || list2->firstC() == 7",
          "fl_isEmpty(list) || fl_firstC(list2) == 7")

  testOne("l->nth(3)->isMethod(); foo(list->first())",
          "fl_nth(l, 3)->isMethod(); foo(fl_first(list))")

  testOne("Variable *srcVar = srcTDecl->asTD_decl()->d->decllist->first()->var;",
          "Variable *srcVar = fl_first(srcTDecl->asTD_decl()->d->decllist)->var;")

  testOne("  bool argsProvided = !srcArgs->isEmpty();",
          "  bool argsProvided = !fl_isEmpty(srcArgs);")


def main():
  unitTests()

  for line in sys.stdin:
    line = line.rstrip("\n")
    line = fixLine(line)
    print(line)

call_main()


# EOF
