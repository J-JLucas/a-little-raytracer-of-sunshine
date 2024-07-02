#include "Matrix.h"
#include <iostream>

float &Matrix::operator()(int row, int col) { return data[row * n + col]; }

bool Matrix::operator==(const Matrix &other) const
{
  if (n != other.getSize()) {
    return false;
  }
  int i = 0;
  int j = 0;

  bool isEqual = true;
  while (isEqual && i < n) {
    while (isEqual && j < n) {
      isEqual = data[i * n + j] == other.data[i * n + j];
      ++j;
    }
    ++i;
  }
  return isEqual;
}

void Matrix::print() const
{
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cout << data[i * n + j] << " ";
    }
    std::cout << std::endl;
  }
}
