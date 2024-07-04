#include "Tuple.h"
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

bool Tuple::floatEqual(float a, float b) { return std::abs((a - b)) < EPSILON; }

bool Tuple::operator==(const Tuple &rhs) const
{
  for (int i = 0; i < 4; i++) {
    if (!floatEqual(data[i], rhs.data[i])) {
      return false;
    }
  }
  return true;
}

Tuple Tuple::operator+(const Tuple &rhs) const
// point + point undefined
{
  return Tuple(data[0] + rhs.data[0], data[1] + rhs.data[1],
               data[2] + rhs.data[2], data[3] + rhs.data[3]);
}

Tuple Tuple::operator-(const Tuple &rhs) const
// vector - point undefined
{
  return Tuple(data[0] - rhs.data[0], data[1] - rhs.data[1],
               data[2] - rhs.data[2], data[3] - rhs.data[3]);
}

Tuple Tuple::operator-() const
{
  return Tuple(-data[0], -data[1], -data[2], -data[3]);
}

Tuple Tuple::operator*(float scalar) const
{
  return Tuple(data[0] * scalar, data[1] * scalar, data[2] * scalar,
               data[3] * scalar);
}

Tuple Tuple::operator/(float scalar) const
{
  assert(scalar != 0.0f);
  return Tuple(data[0] / scalar, data[1] / scalar, data[2] / scalar,
               data[3] / scalar);
}

float Tuple::magnitude(Tuple v)
{
  return sqrt(pow(v.data[0], 2.0f) + pow(v.data[1], 2.0f) +
              pow(v.data[2], 2.0f));
}

Tuple Tuple::normalize(Tuple v) { return v / magnitude(v); }

float Tuple::dot(Tuple v, Tuple w)
{
  assert((v.data[3] == 0 && w.data[3] == 0) &&
         "Dot Product requires two vector operands");
  return (v.data[0] * w.data[0]) + (v.data[1] * w.data[1]) +
         (v.data[2] * w.data[2]);
}

Tuple Tuple::cross(Tuple v, Tuple w)
{
  assert((v.data[3] == 0 && w.data[3] == 0) &&
         "Cross Product requires two vector operands");
  return Vector((v.data[1] * w.data[2]) - (v.data[2] * w.data[1]),
                (v.data[2] * w.data[0]) - (v.data[0] * w.data[2]),
                (v.data[0] * w.data[1]) - (v.data[1] * w.data[0]));
}

Tuple Tuple::colourProduct(Tuple v, Tuple w)
{
  // Hadamard product of two colour tuples
  return Colour(v.data[0] * w.data[0], v.data[1] * w.data[1],
                v.data[2] * w.data[2]);
}

void Tuple::printTuple()
{
  std::cout << "(" << data[0] << ", " << data[1] << ", " << data[2] << ", "
            << data[3] << ")" << std::endl;
}
