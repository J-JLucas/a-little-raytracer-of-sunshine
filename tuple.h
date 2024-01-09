/* tuples represent a vector or point in 3D space
 * vector -> w = 0
 * point  -> w = 1
 */

#pragma once

class Tuple {
public:
  float x{};
  float y{};
  float z{};
  bool w{};

private:
  Tuple(float x, float y, float z, bool w = false) : x(x), y(y), z(z), w(w) {}

public:
  static Tuple vector(float x, float y, float z) { return Tuple(x, y, z); }
  static Tuple point(float x, float y, float z) { return Tuple(x, y, z, true); }
};
