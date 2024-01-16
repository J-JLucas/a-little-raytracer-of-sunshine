#include "Canvas.h"
#include "Tuple.h"
#include <cassert>
#include <fstream>

Canvas::Canvas(int width, int height)
    : pixelArray(height, std::vector<Tuple>(width, Tuple::Colour(0, 0, 0)))
{
  this->width = width;
  this->height = height;
}

Tuple Canvas::getPixel(int row, int column) const
{
  return pixelArray[row][column];
}

void Canvas::writePixel(int row, int column, class Tuple colour)
{
  // no out of bounds writes
  assert(row >= 0 && row < height);
  assert(column >= 0 && column < width);

  pixelArray[row][column] = colour;
}

void Canvas::exportCanvas(std::ofstream &outfile)
{
  // PPM header
  outstream << "P3\n"                         // PPM Type ID
            << width << " " << height << "\n" // width and height
            << "255" << std::endl;            // max colour value

  outfile << outstream.str();
}
