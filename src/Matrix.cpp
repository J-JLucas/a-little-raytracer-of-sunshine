#include "Matrix.h"
#include "Tuple.h"
#include <iostream>

float &Matrix::operator()(int row, int col) { return data[row * n + col]; }

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
      isEqual = data[i * n + j] == other.data[i * n + j];
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

void Matrix::print() const
{
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << data[i * n + j] << " ";
    }
    std::cout << std::endl;
  }
}
