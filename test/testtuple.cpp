#include "../src/tuple.h"
#include <cassert>
#include <cmath>
#include <iostream>

void testTuples()
{
  Tuple v = Tuple::Vector(1.0f, 2.0f, 3.0f);
  Tuple w = Tuple::Vector(1.0000001f, 2.0f, 3.0f);
  Tuple g = Tuple::Vector(6.0f, 5.0f, 4.0f);

  Tuple p = Tuple::Point(1.0f, 2.0f, 3.0f);
  Tuple q = Tuple::Point(1.0000001f, 2.0f, 3.0f);
  Tuple r = Tuple::Point(6.0f, 5.0f, 4.0f);

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
  assert((v + g == Tuple::Vector(7.0f, 7.0f, 7.0f)) &&
         "v + g should be equal to (7, 7, 7)");
  assert((v + p == Tuple::Point(2.0f, 4.0f, 6.0f)) &&
         "v + p should be equal to (2, 4, 6)");

  // subtraction
  assert((v - g == Tuple::Vector(-5.0f, -3.0f, -1.0f)) &&
         "v - g should be equal to (-5, -3, -1)");
  assert((p - g == Tuple::Point(-5.0f, -3.0f, -1.0f)) &&
         "p - g should be equal to (-5, -3, -1)");
  assert((r - p == Tuple::Vector(5.0f, 3.0f, 1.0f)) &&
         "r - p should be equal to (5, 3, 1)");

  // negation
  assert((-v == Tuple::Vector(-1.0f, -2.0f, -3.0f)) &&
         "-v should be equal to (-1, -2, -3)");

  // scalar multiplication
  assert((v * 3.5f == Tuple::Vector(3.5f, 7.0f, 10.5f)) &&
         "v * 3.5 should be equal to (3.5, 7, 10.5)");
  assert((v * 0.5f == Tuple::Vector(0.5f, 1.0f, 1.5f)) &&
         "v * 0.5 should be equal to (0.5, 1, 1.5)");

  // scalar division
  assert((v / 2.0f == Tuple::Vector(0.5f, 1.0f, 1.5f)) &&
         "v / 2 should be equal to (0.5, 1, 1.5)");

  // magnitude
  assert((Tuple::magnitude(Tuple::Vector(1.0f, 0.0f, 0.0f)) == 1.0f) &&
         "magnitude of (1, 0, 0) should be 1");
  assert((Tuple::magnitude(Tuple::Vector(0.0f, 1.0f, 0.0f)) == 1.0f) &&
         "magnitude of (0, 1, 0) should be 1");
  assert((Tuple::magnitude(Tuple::Vector(0.0f, 0.0f, 1.0f)) == 1.0f) &&
         "magnitude of (0, 0, 1) should be 1");
  assert((Tuple::magnitude(v) == std::sqrt(14.0f)) &&
         "magnitude of (1, 2, 3) should be sqrt(14)");
  assert((Tuple::magnitude(-v) == std::sqrt(14.0f)) &&
         "magnitude of (-1, -2, -3) should be sqrt(14)");

  // normalization
  assert((Tuple::normalize(Tuple::Vector(4.0f, 0.0f, 0.0f)) ==
          Tuple::Vector(1.0f, 0.0f, 0.0f)) &&
         "normalize(4, 0, 0) should be (1, 0, 0)");
  assert((Tuple::normalize(v) == Tuple::Vector(0.26726f, 0.53452f, 0.80178f)) &&
         "normalize(1, 2, 3) should be (0.26726, 0.53452, 0.80178)");
  assert(Tuple::floatEqual(Tuple::magnitude(Tuple::normalize(v)), 1.0f) &&
         "magnitude of normalize(1, 2, 3) should be 1.0f");

  // dot product
  assert((Tuple::dot(v, g) == 28.0f) && "dot(v, g) should be 28");

  // cross product
  assert((Tuple::cross(v, g) == Tuple::Vector(-7.0f, 14.0f, -7.0f)) &&
         "cross(v, g) should be (-7.0f, 14.0f, -7.0f)");
  assert((Tuple::cross(g, v) == Tuple::Vector(7.0f, -14.0f, 7.0f)) &&
         "cross(g, v) should be (7.0f, -14.0f, 7.0f)");
}

int main(int argc, char *argv[])
{
  try {
    testTuples();
    std::cout << "All tests passed!\n";
  }
  catch (const char *msg) {
    std::cerr << "Assertion failed: " << msg << '\n';
  }
  return 0;
}
