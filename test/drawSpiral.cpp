#include "../src/Canvas.h"
#include "../src/Tuple.h"
#include <cmath>
#include <fstream>
#include <iostream>

constexpr int width = 900;
constexpr int height = 550;
Tuple red = Tuple::Colour(1, 0, 0);

void tick(int t, Tuple &p, Canvas &c)
{
  float a = 0.1f; // spacing constant

  // update point position
  p.x = a * t * std::cos(t) + width / 2;
  p.y = a * t * std::sin(t) + height / 2;

  // draw projectile on canvas
  c.writePixel(std::round(p.x), height - std::round(p.y), red);

  return;
}

int main(int argc, char *argv[])
{
  int t = 0; // tick aka time
  Canvas c = Canvas(width, height);

  Tuple p = Tuple::Point(0, 0, 0);
  // Tuple p = Tuple::Point(width / 2, height / 2, 0);
  std::cout << "Position: (" << std::round(p.x) << ", " << std::round(p.y)
            << ", " << std::round(p.z) << ")" << std::endl;

  while (t++ < 1000) {
    tick(t, p, c);
    std::cout << "Position: (" << std::round(p.x) << ", " << std::round(p.y)
              << ", " << std::round(p.z) << ")" << std::endl;
  }

  // export canvas
  std::ofstream outfile("spiral.ppm");
  c.exportCanvas(outfile);

  return 0;
}
