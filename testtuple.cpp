#include "tuple.h"
#include <cassert>
#include <cmath>
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

  // negation
  assert((-v == Tuple::vector(-1.0f, -2.0f, -3.0f)) &&
         "-v should be equal to (-1, -2, -3)");

  // scalar multiplication
  assert((v * 3.5f == Tuple::vector(3.5f, 7.0f, 10.5f)) &&
         "v * 3.5 should be equal to (3.5, 7, 10.5)");
  assert((v * 0.5f == Tuple::vector(0.5f, 1.0f, 1.5f)) &&
         "v * 0.5 should be equal to (0.5, 1, 1.5)");

  // scalar division
  assert((v / 2.0f == Tuple::vector(0.5f, 1.0f, 1.5f)) &&
         "v / 2 should be equal to (0.5, 1, 1.5)");

  // magnitude
  assert((Tuple::magnitude(Tuple::vector(1.0f, 0.0f, 0.0f)) == 1.0f) &&
         "magnitude of (1, 0, 0) should be 1");
  assert((Tuple::magnitude(Tuple::vector(0.0f, 1.0f, 0.0f)) == 1.0f) &&
         "magnitude of (0, 1, 0) should be 1");
  assert((Tuple::magnitude(Tuple::vector(0.0f, 0.0f, 1.0f)) == 1.0f) &&
         "magnitude of (0, 0, 1) should be 1");
  assert((Tuple::magnitude(v) == std::sqrt(14.0f)) &&
         "magnitude of (1, 2, 3) should be sqrt(14)");
  assert((Tuple::magnitude(-v) == std::sqrt(14.0f)) &&
         "magnitude of (-1, -2, -3) should be sqrt(14)");

  // normalization
  assert((Tuple::normalize(Tuple::vector(4.0f, 0.0f, 0.0f)) ==
          Tuple::vector(1.0f, 0.0f, 0.0f)) &&
         "normalize(4, 0, 0) should be (1, 0, 0)");
  assert((Tuple::normalize(v) == Tuple::vector(0.26726f, 0.53452f, 0.80178f)) &&
         "normalize(1, 2, 3) should be (0.26726, 0.53452, 0.80178)");

  float test = Tuple::magnitude(Tuple::normalize(v));
  std::cout << "normalize(1, 2, 3) magnitude is " << test << '\n';
  // print type of test
  std::cout << "type of test is " << typeid(test).name() << '\n';
  std::cout << "type of test is " << typeid(1.0f).name() << '\n';
  std::cout << (test == 1.0f) << '\n';
  std::cout << (1.0f == 1.0f) << '\n';
  std::cout << (1.00 == 1.0f) << '\n';
  assert((test == 1.0f) && "magnitude of normalize(1, 2, 3) should be 1.0f");
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
