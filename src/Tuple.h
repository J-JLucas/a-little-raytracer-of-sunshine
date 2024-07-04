/* tuples represent a vector or point in 3D space
 * vector -> w = 0
 * point  -> w = 1
 */

#pragma once

#include <string>

class Tuple {

private:
  static constexpr float EPSILON = 0.00001f;

public:
  float data[4]{};

private:
  Tuple(float x, float y, float z, float w) : data{x, y, z, w} {}

public:
  static Tuple Point(float x, float y, float z) { return Tuple(x, y, z, 1.0f); }
  static Tuple Vector(float x, float y, float z)
  {
    return Tuple(x, y, z, 0.0f);
  }
  static Tuple Colour(float r, float g, float b)
  {
    return Tuple(r, g, b, 0.0f);
  }

  // operations are const because don't want to modify operands
  static bool floatEqual(float a, float b);
  bool operator==(const Tuple &rhs) const;
  bool operator!=(const Tuple &rhs) const { return !(*this == rhs); }
  Tuple operator+(const Tuple &rhs) const;
  Tuple operator-(const Tuple &rhs) const;
  Tuple operator-() const;
  Tuple operator*(float scalar) const;
  Tuple operator/(float scalar) const;
  static float magnitude(Tuple v);
  static Tuple normalize(Tuple v);
  static float dot(Tuple v, Tuple w);
  static Tuple cross(Tuple v, Tuple w);
  static Tuple colourProduct(Tuple v, Tuple w);
  float getX() { return data[0]; }
  float getY() { return data[1]; }
  float getZ() { return data[2]; }
  float getRed() { return data[0]; }
  float getBlue() { return data[1]; }
  float getGreen() { return data[2]; }

  void printTuple();
};
