#include "Matrix.h"
#include "Tuple.h"
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

int Matrix::determinate() const
{
  if (n == 2) {
    return data[0] * data[3] - data[1] * data[2];
  }
  int det = 0;
  for (int i = 0; i < n; i++) {
    det += data[i] * cofactor(*this, 0, i);
  }
  return det;
}

Matrix Matrix::inverse() const
{
  Matrix result(n);
  int det = determinate();
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

int Matrix::minor(const Matrix &m, int row, int col)
{
  return submatrix(m, row, col).determinate();
}

int Matrix::cofactor(const Matrix &m, int row, int col)
{
  return (row + col) % 2 == 0 ? minor(m, row, col) : -minor(m, row, col);
}
