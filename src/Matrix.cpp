#include "Matrix.h"
#include <iostream>

float &Matrix::operator()(int row, int col) { return data[row * n + col]; }

void Matrix::print() const
{
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cout << data[i * n + j] << " ";
    }
    std::cout << std::endl;
  }
}
