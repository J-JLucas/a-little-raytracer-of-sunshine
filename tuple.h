/* tuples represent a vector or point in 3D space
 * vector -> w = 0
 * point  -> w = 1
 */

#pragma once

class Tuple {

private:
  static constexpr float EPSILON = 0.00001f;

public:
  float x{};
  float y{};
  float z{};
  bool w{};

private:
  Tuple(float x, float y, float z, bool w = false) : x(x), y(y), z(z), w(w) {}
  bool floatEqual(float a, float b) const;

public:
  static Tuple vector(float x, float y, float z) { return Tuple(x, y, z); }
  static Tuple point(float x, float y, float z) { return Tuple(x, y, z, true); }

  // operations are const because don't want to modify operands
  bool operator==(const Tuple &rhs) const;
  bool operator!=(const Tuple &rhs) const { return !(*this == rhs); }
  Tuple operator+(const Tuple &rhs) const;
};
