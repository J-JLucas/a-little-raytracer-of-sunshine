#include "testCanvas.h"
#include "../src/Canvas.h"
#include "../src/Tuple.h"
#include <cassert>

void testCanvas()
{
  Tuple black = Tuple::Colour(0, 0, 0);
  Tuple red = Tuple::Colour(1, 0, 0);

  int width = 10;
  int height = 20;

  Canvas c = Canvas(width, height);
  assert((c.getWidth() == width) && "Canvas width should be 10");
  assert((c.getHeight() == height) && "Canvas height should be 20");

  // assert that all pixels are black in fresh canvas
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      assert(c.getPixel(i, j) == black && "Canvas pixel should be black");
    }
  }

  // write pixels
  c.writePixel(2, 3, red);
  assert((c.getPixel(2, 3) == red) && "Canvas pixel should be red");

  return;
}