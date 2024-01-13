#include "tuple.h"
#include <cassert>
#include <iostream>

void testTuple()
{
  Tuple v = Tuple::vector(1.0f, 2.0f, 3.0f);
  Tuple w = Tuple::vector(1.0000001f, 2.0f, 3.0f);
  Tuple g = Tuple::vector(6.0f, 5.0f, 4.0f);

  Tuple p = Tuple::point(1.0f, 2.0f, 3.0f);
  Tuple q = Tuple::point(1.0000001f, 2.0f, 3.0f);
  Tuple r = Tuple::point(6.0f, 5.0f, 4.0f);

  assert(v.w == 0 && "v should be a vector");
  assert(p.w == 1 && "p should be a point");

  // equality
  assert((v == v) && "v should be equal to v");
  assert((v != p) && "v should not be equal to p");
  assert((v == w) && "v should be equal to w");
  assert((v != g) && "v should not be equal to p");

  assert((p == p) && "p should be equal to p");
  assert((p == q) && "p should be equal to q");
  assert((p != r) && "p should not be equal to r");

  // addition
  assert((v + g == Tuple::vector(7.0f, 7.0f, 7.0f)) &&
         "v + g should be equal to (7, 7, 7)");
  assert((v + p == Tuple::point(2.0f, 4.0f, 6.0f)) &&
         "v + p should be equal to (2, 4, 6)");

  // subtraction
  assert((v - g == Tuple::vector(-5.0f, -3.0f, -1.0f)) &&
         "v - g should be equal to (-5, -3, -1)");
  assert((p - g == Tuple::point(-5.0f, -3.0f, -1.0f)) &&
         "p - g should be equal to (-5, -3, -1)");
  assert((r - p == Tuple::vector(5.0f, 3.0f, 1.0f)) &&
         "r - p should be equal to (5, 3, 1)");
}

int main(int argc, char *argv[])
{
  try {
    testTuple();
    std::cout << "All tests passed!\n";
  }
  catch (const char *msg) {
    std::cerr << "Assertion failed: " << msg << '\n';
  }
  return 0;
}
