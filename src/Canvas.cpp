#include "Canvas.h"
#include "Tuple.h"
#include <algorithm>
#include <cassert>
#include <fstream>
#include <iomanip>
#include <iostream>

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
  // ignore out of bounds writes
  if (row < 0 || row > height || column < 0 || column > width) {
    std::cout << "Canvas::writePixel: out of bounds write at (" << row << ", "
              << column << ")" << std::endl;
    return;
  }
  pixelArray[row][column] = colour;
}

void Canvas::exportColours(Tuple pixel)
{
  // this is bad, but it works! (thanks copilot LMAO)
  // probably refactor pixel members to be an array

  std::string red = std::to_string(
      std::clamp(int(pixel.getRed() * MAX_COLOUR_VALUE), 0, MAX_COLOUR_VALUE));
  charCount += red.length();
  if (charCount > MAX_CHAR_COUNT) {
    outstream << "\n";
    charCount = 0;
  }
  outstream << std::fixed << std::setprecision(1) << red << " ";

  std::string green = std::to_string(std::clamp(
      int(pixel.getGreen() * MAX_COLOUR_VALUE), 0, MAX_COLOUR_VALUE));
  charCount += green.length();
  if (charCount > MAX_CHAR_COUNT) {
    outstream << "\n";
    charCount = 0;
  }
  outstream << std::fixed << std::setprecision(1) << green << " ";

  std::string blue = std::to_string(
      std::clamp(int(pixel.getBlue() * MAX_COLOUR_VALUE), 0, MAX_COLOUR_VALUE));
  charCount += blue.length();
  if (charCount > MAX_CHAR_COUNT) {
    outstream << "\n";
    charCount = 0;
  }
  outstream << std::fixed << std::setprecision(1) << blue << " ";
}

void Canvas::exportCanvas(std::ofstream &outfile)
{
  // PPM Header
  outstream << "P3\n" // PPM Type ID
            << width << " " << height << "\n"
            << MAX_COLOUR_VALUE << std::endl;

  // Pixel Data
  outstream << "\n";
  for (auto &row : pixelArray) {
    for (auto &p : row) {
      exportColours(p);
    }
  }
  // Newline Footer
  outstream << std::endl;

  // Write to file
  outfile << outstream.str();
}
