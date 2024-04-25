/*
 * Represents a square matrix of floats
 * Dimensions restricted to 2x2, 3x3, 4x4
 */
#pragma once

#include <cassert>

class Matrix {
private:
  int n{}; // dimensions n x n
  float *data;

public:
  Matrix(int dimension) : n(dimension)
  {
    assert(n >= 2 && n <= 4 && "Matrix dimensions must be between 2 and 4");
    data = new float[n * n];
  }
  ~Matrix() { delete[] data; }

  float &operator()(int row, int col);
};
