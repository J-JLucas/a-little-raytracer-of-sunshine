#include "tuple.h"

bool Tuple::Equal(Tuple a, Tuple b)
{
  if (a.w != b.w) // points and vectors are not equal
    return false;
  if (!floatEqual(a.x, b.x)) {
    return false;
  }
  if (!floatEqual(a.y, b.y)) {
    return false;
  }
  if (!floatEqual(a.z, b.z)) {
    return false;
  }
  return true;
}

Tuple Tuple::operator+(const Tuple &rhs) const
{
  return Tuple(x + rhs.x, y + rhs.y, z + rhs.z, w);
}
