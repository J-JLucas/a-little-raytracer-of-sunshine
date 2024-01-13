#include "tuple.h"
#include <cstdlib>

bool Tuple::floatEqual(float a, float b) const
{
  return std::abs((a - b)) < EPSILON;
}

bool Tuple::operator==(const Tuple &rhs) const
{
  if (w != rhs.w) // points and vectors are not equal
    return false;
  if (!floatEqual(x, rhs.x)) {
    return false;
  }
  if (!floatEqual(y, rhs.y)) {
    return false;
  }
  if (!floatEqual(z, rhs.z)) {
    return false;
  }
  return true;
}

Tuple Tuple::operator+(const Tuple &rhs) const
// point + point undefined
{
  // vector + point
  if (w || rhs.w) {
    return Tuple(x + rhs.x, y + rhs.y, z + rhs.z, true);
  }
  // vector + vector
  else {
    return Tuple(x + rhs.x, y + rhs.y, z + rhs.z, false);
  }
}
