#include "tuple.h"

#include <iostream>

int main(int argc, char *argv[])
{
  Tuple v = Tuple::vector(1.0f, 2.0f, 3.0f);
  Tuple p = Tuple::point(1.0f, 2.0f, 3.0f);

  std::cout << "v: " << v.x << ", " << v.y << ", " << v.z << ", " << v.w
            << std::endl;
  std::cout << "p: " << p.x << ", " << p.y << ", " << p.z << ", " << p.w
            << std::endl;

  std::cout << "v is a vector: " << (v.w == 0 ? "true" : "false") << std::endl;
  std::cout << "p is a point: " << (p.w == 1 ? "true" : "false") << std::endl;

  return 0;
}
