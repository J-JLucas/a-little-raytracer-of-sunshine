#include "Matrix.h"
#include "Tuple.h"
#include <cmath>
#include <iostream>

bool Matrix::floatEqual(float a, float b)
{
  return std::abs((a - b)) < EPSILON;
}

float &Matrix::operator()(int row, int col) const
{
  return data[row * n + col];
}

// https://stackoverflow.com/questions/123758/how-do-i-remove-code-duplication-between-similar-const-and-non-const-member-func
float &Matrix::operator()(int row, int col)
{
  return const_cast<float &>(static_cast<const Matrix &>(*this)(row, col));
}

bool Matrix::operator==(const Matrix &other) const
{
  if (n != other.n) {
    return false;
  }
  int i = 0;
  int j = 0;

  bool isEqual = true;
  while (isEqual && i < n) {
    while (isEqual && j < n) {
      isEqual = floatEqual(data[i * n + j], other.data[i * n + j]);
      j++;
    }
    i++;
  }
  return isEqual;
}

// Matrix Multiplication
Matrix Matrix::operator*(const Matrix &other) const
{
  Matrix result(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        result(i, j) += data[i * n + k] * other.data[k * n + j];
      }
    }
  }
  return result;
}

// Matrix * Tuple
Tuple Matrix::operator*(const Tuple &t) const
{
  Tuple result = Tuple::Vector(0, 0, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      result.data[i] += data[i * n + j] * t.data[j];
    }
  }
  return result;
}

Matrix &Matrix::transpose()
{
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      float temp = data[i * n + j];
      data[i * n + j] = data[j * n + i];
      data[j * n + i] = temp;
    }
  }
  return *this;
}

float Matrix::determinate() const
{
  if (n == 2) {
    return data[0] * data[3] - data[1] * data[2];
  }
  float det = 0;
  for (int i = 0; i < n; i++) {
    det += data[i] * cofactor(*this, 0, i);
  }
  return det;
}

Matrix Matrix::inverse() const
{
  Matrix result(n);
  float det = determinate();
  if (floatEqual(det, 0)) {
    throw std::runtime_error("Matrix is not invertible");
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      float c = cofactor(*this, i, j);
      result(j, i) = c / det;
    }
  }
  return result;
}

void Matrix::print() const
{
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << data[i * n + j] << " ";
    }
    std::cout << std::endl;
  }
}

Matrix Matrix::submatrix(const Matrix &m, int row, int col)
{
  Matrix result(m.n - 1);

  for (int i = 0; i < m.n; i++) {
    for (int j = 0; j < m.n; j++) {
      if (i != row && j != col) {
        int r = i < row ? i : i - 1;
        int c = j < col ? j : j - 1;
        result(r, c) = m(i, j);
      }
    }
  }
  return result;
}

float Matrix::minor(const Matrix &m, int row, int col)
{
  return submatrix(m, row, col).determinate();
}

float Matrix::cofactor(const Matrix &m, int row, int col)
{
  return (row + col) % 2 == 0 ? minor(m, row, col) : -minor(m, row, col);
}

Matrix Matrix::translation(float x, float y, float z)
{

  Matrix M(4);
  M(0, 0) = 1;
  M(1, 1) = 1;
  M(2, 2) = 1;
  M(3, 3) = 1;
  M(0, 3) = x;
  M(1, 3) = y;
  M(2, 3) = z;
  return M;
}

Matrix Matrix::scaling(float x, float y, float z)
{
  Matrix M(4);
  M(0, 0) = x;
  M(1, 1) = y;
  M(2, 2) = z;
  M(3, 3) = 1;
  return M;
}

Matrix Matrix::rotation_x(float r)
{
  Matrix M(4);
  M(0, 0) = 1;
  M(1, 1) = cos(r);
  M(1, 2) = -sin(r);
  M(2, 1) = sin(r);
  M(2, 2) = cos(r);
  M(3, 3) = 1;
  return M;
}

Matrix Matrix::rotation_y(float r)
{
  Matrix M(4);
  M(0, 0) = cos(r);
  M(0, 2) = sin(r);
  M(1, 1) = 1;
  M(2, 1) = -sin(r);
  M(2, 2) = cos(r);
  M(3, 3) = 1;
  return M;
}

Matrix Matrix::rotation_z(float r)
{
  Matrix M(4);
  M(0, 0) = cos(r);
  M(0, 1) = -sin(r);
  M(1, 0) = sin(r);
  M(1, 1) = cos(r);
  M(2, 2) = 1;
  M(3, 3) = 1;
  return M;
}

Matrix Matrix::shearing(float xy, float xz, float yx, float yz, float zx,
                        float zy)
{
  Matrix M(4);
  M(0, 0) = 1;
  M(0, 1) = xy;
  M(0, 2) = xz;
  M(1, 0) = yx;
  M(1, 1) = 1;
  M(1, 2) = yz;
  M(2, 0) = zx;
  M(2, 1) = zy;
  M(2, 2) = 1;
  M(3, 3) = 1;
  return M;
}
