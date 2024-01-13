#include "tuple.h"
#include <cassert>
#include <cmath>
#include <cstdlib>

using namespace std;

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
  return Tuple(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
}

Tuple Tuple::operator-(const Tuple &rhs) const
// vector - point undefined
{
  return Tuple(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
}

Tuple Tuple::operator-() const { return Tuple(-x, -y, -z, -w); }

Tuple Tuple::operator*(float scalar) const
{
  return Tuple(x * scalar, y * scalar, z * scalar, w * scalar);
}

Tuple Tuple::operator/(float scalar) const
{
  assert(scalar != 0.0f);
  return Tuple(x / scalar, y / scalar, z / scalar, w / scalar);
}

float Tuple::magnitude(Tuple v)
{
  return sqrt(pow(v.x, 2.0f) + pow(v.y, 2.0f) + pow(v.z, 2.0f));
}

Tuple Tuple::normalize(Tuple v) { return v / magnitude(v); }
