#include "tuple.h"

#include <iostream>

int main(int argc, char *argv[])
{
  Tuple v = Tuple::vector(1.0f, 2.0f, 3.0f);
  Tuple w = Tuple::vector(1.0000001f, 2.0f, 3.0f);
  Tuple g = Tuple::vector(6.0f, 5.0f, 4.0f);

  Tuple p = Tuple::point(1.0f, 2.0f, 3.0f);
  Tuple q = Tuple::point(1.0000001f, 2.0f, 3.0f);
  Tuple r = Tuple::point(6.0f, 5.0f, 4.0f);

  std::cout << "v: " << v.x << ", " << v.y << ", " << v.z << ", " << v.w
            << std::endl;
  std::cout << "w: " << w.x << ", " << w.y << ", " << w.z << ", " << w.w
            << std::endl;
  std::cout << "g: " << g.x << ", " << g.y << ", " << g.z << ", " << g.w
            << std::endl;
  std::cout << "p: " << p.x << ", " << p.y << ", " << p.z << ", " << p.w
            << std::endl;
  std::cout << "q: " << q.x << ", " << q.y << ", " << q.z << ", " << q.w
            << std::endl;
  std::cout << "r: " << r.x << ", " << r.y << ", " << r.z << ", " << r.w
            << std::endl;

  std::cout << "v is a vector: " << (v.w == 0 ? "true" : "false")
            << "; expected true" << std::endl;
  std::cout << "p is a point: " << (p.w == 1 ? "true" : "false")
            << "; expected true" << std::endl;

  std::cout << "v = p: " << (Tuple::Equal(v, p) ? "true" : "false")
            << "; expected false" << std::endl;
  std::cout << "v = w: " << (Tuple::Equal(v, w) ? "true" : "false")
            << "; expected true" << std::endl;
  std::cout << "v = z: " << (Tuple::Equal(v, v) ? "true" : "false")
            << "; expected true" << std::endl;
  std::cout << "v = g: " << (Tuple::Equal(v, g) ? "true" : "false")
            << "; expected false" << std::endl;

  std::cout << "p = p: " << (Tuple::Equal(p, p) ? "true" : "false")
            << "; expected true" << std::endl;
  std::cout << "p = q: " << (Tuple::Equal(p, q) ? "true" : "false")
            << "; expected true" << std::endl;
  std::cout << "p = r: " << (Tuple::Equal(p, r) ? "true" : "false")
            << "; expected false" << std::endl;

  return 0;
}
