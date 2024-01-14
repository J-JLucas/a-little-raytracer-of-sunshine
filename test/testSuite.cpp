#include "testCanvas.h"
#include "testTuple.h"
#include <iostream>

int main(int argc, char *argv[])
{
  testTuple();
  std::cout << "All Tuple tests passed!" << std::endl;

  testCanvas();
  std::cout << "All Canvas tests passed!" << std::endl;

  return 0;
}
