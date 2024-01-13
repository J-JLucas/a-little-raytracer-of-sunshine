#include "../src/tuple.h"
#include <iostream>

struct Projectile {
  Tuple position;
  Tuple velocity;
};

struct Environment {
  Tuple gravity;
  Tuple wind;
};

void tick(Environment &env, Projectile &proj)
{
  proj.position = proj.position + proj.velocity;
  proj.velocity = proj.velocity + env.gravity + env.wind;
  return;
}

int main(int argc, char *argv[])
{
  // Projectile starts one unit above the origin
  // velocity is normalized to 1 unit/tick
  if (argc != 4) {
    std::cout << "Usage: projectile requires velocity x y z values"
              << std::endl;
    return 1;
  }

  Projectile p = {
      Tuple::Point(0, 1, 0),
      Tuple::normalize(Tuple::Vector(std::stof(argv[1]), std::stof(argv[2]),
                                     std::stof(argv[3])))};

  // gravity -0.1 unit/tick, and wind is -0.01 unit/tick
  Environment e = {Tuple::Vector(0, -0.1, 0), Tuple::Vector(-0.01, 0, 0)};

  while (p.position.y > 0) {
    tick(e, p);
    std::cout << "Position: (" << p.position.x << ", " << p.position.y << ", "
              << p.position.z << ")" << std::endl;
  }

  return 0;
}
