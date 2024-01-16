// Represents the screen to be drawn to
#pragma once
#include <sstream>
#include <vector>

class Canvas {
private:
  int width{};
  int height{};
  std::vector<std::vector<class Tuple>> pixelArray{};
  std::stringstream outstream;

public:
  Canvas(int width, int height);

  int getWidth() const { return width; }
  int getHeight() const { return height; }
  Tuple getPixel(int row, int column) const;
  void writePixel(int row, int column, Tuple colour);
  void exportCanvas(std::ofstream &outfile);
};
