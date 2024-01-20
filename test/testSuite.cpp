#include "testCanvas.h"
#include "testMatrix.h"
#include "testTuple.h"
#include <iostream>

int main(int argc, char *argv[])
{
  testTuple();
  std::cout << "All Tuple tests passed!" << std::endl;

  testMatrix();
  std::cout << "All Matrix tests passed!" << std::endl;

  testCanvas();
  std::cout << "All Canvas tests passed!" << std::endl;

  return 0;
}
