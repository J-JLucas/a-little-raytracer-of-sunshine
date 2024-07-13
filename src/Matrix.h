/*
 * Represents a square matrix of floats
 * Dimensions restricted to 2x2, 3x3, 4x4
 */
#pragma once

#include "Tuple.h"
#include <cassert>
#include <initializer_list>

constexpr float pi = 3.14159265358979323846;

class Matrix {
private:
  int n{}; // dimensions n x n
  float *data;
  static constexpr float EPSILON = 0.00001f;

  static bool floatEqual(float a, float b);

public:
  Matrix(int dimension, std::initializer_list<float> initializer_list = {})
      : n(dimension)
  {
    assert(n >= 2 && n <= 4 && "Matrix dimensions must be between 2 and 4");
    data = new float[n * n]{0};
    auto it = initializer_list.begin();
    for (int i = 0; i < n * n && it != initializer_list.end(); ++i, ++it) {
      data[i] = *it;
    }
  }

  ~Matrix() { delete[] data; }

  float &operator()(int row, int col) const;
  float &operator()(int row, int col);
  bool operator==(const Matrix &other) const;
  bool operator!=(const Matrix &other) const { return !(*this == other); }
  Matrix operator*(const Matrix &other) const;
  class Tuple operator*(const class Tuple &t) const;

  Matrix &transpose();
  float determinate() const;
  bool invertible() const { return determinate() != 0; }
  Matrix inverse() const;

  void print() const;

  static Matrix submatrix(const Matrix &m, int row, int col);
  static float minor(const Matrix &m, int row, int col);
  static float cofactor(const Matrix &m, int row, int col);
  static Matrix translation(float x, float y, float z);
  static Matrix scaling(float x, float y, float z);
  static Matrix rotation_x(float r);
  static Matrix rotation_y(float r);
  static Matrix rotation_z(float r);
};
