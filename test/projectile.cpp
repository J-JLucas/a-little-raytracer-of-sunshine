#include "../src/Canvas.h"
#include "../src/Tuple.h"
#include <cmath>
#include <fstream>
#include <iostream>

constexpr int width = 900;
constexpr int height = 550;
Tuple red = Tuple::Colour(1, 0, 0);

struct Projectile {
  Tuple position;
  Tuple velocity;
};

struct Environment {
  Tuple gravity;
  Tuple wind;
};

void tick(Environment &env, Projectile &proj, Canvas &c)
{
  proj.position = proj.position + proj.velocity;
  proj.velocity = proj.velocity + env.gravity + env.wind;

  // draw projectile on canvas
  c.writePixel(std::round(proj.position.getX()),
               height - std::round(proj.position.getY()), red);

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

  Canvas c = Canvas(width, height);

  Projectile p = {
      Tuple::Point(0, 1, 0),
      Tuple::normalize(Tuple::Vector(std::stof(argv[1]), std::stof(argv[2]),
                                     std::stof(argv[3]))) *
          11.25f};

  // gravity -0.1 unit/tick, and wind is -0.01 unit/tick
  Environment e = {Tuple::Vector(0, -0.1, 0), Tuple::Vector(-0.01, 0, 0)};

  while (p.position.getY() > 0) {
    tick(e, p, c);
    std::cout << "Position: (" << std::round(p.position.getX()) << ", "
              << std::round(p.position.getY()) << ", "
              << std::round(p.position.getZ()) << ")" << std::endl;
  }

  // export canvas
  std::ofstream outfile("projectile.ppm");
  c.exportCanvas(outfile);

  return 0;
}
