#include "Matrix.h"

float &Matrix::operator()(int row, int col) { return data[row * n + col]; }
