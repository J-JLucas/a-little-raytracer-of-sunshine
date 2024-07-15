#include "../src/Canvas.h"
#include "../src/Matrix.h"
#include "../src/Tuple.h"
#include <cmath>
#include <fstream>

constexpr int width = 900;
constexpr int height = 550;
Tuple red = Tuple::Colour(1, 0, 0);

void drawClock(Canvas *c)
{

  Tuple white = Tuple::Colour(1, 1, 1);
  Tuple red = Tuple::Colour(1, 0, 0);

  Tuple origin = Tuple::Vector(width / 2, height / 2, 0);
  // Tuple radius = Tuple::Vector(0, height / 4, 0);
  Tuple radius = Tuple::Vector(0, origin.getY() + 100, 0);
  Tuple position = Matrix::translation(0, radius.getY(), 0) * origin;

  c->writePixel(origin.getX(), origin.getY(), white);
  c->writePixel(position.getX(), position.getY(), white);

  /*
  float angle = 0;
  for (int i = 0; i < 12; i++) {
    Tuple hour = Matrix::rotation_z(angle) * position;
    c->writePixel(hour.getX(), hour.getY(), white);
    angle += +pi / 6;
  }
  */
}

int main(int argc, char *argv[])
{
  Canvas c = Canvas(width, height);

  drawClock(&c);

  // export canvas
  std::ofstream outfile("clock.ppm");
  c.exportCanvas(outfile);

  return 0;
}
