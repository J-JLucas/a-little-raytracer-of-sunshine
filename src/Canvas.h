// Represents the screen to be drawn to
#pragma once
#include <sstream>
#include <vector>

class Canvas {
private:
  int const MAX_COLOUR_VALUE{255};
  int width{};
  int height{};
  std::vector<std::vector<class Tuple>> pixelArray{};
  std::stringstream outstream;
  int charCount{};
  int const MAX_CHAR_COUNT{70};

public:
  Canvas(int width, int height);

  int getWidth() const { return width; }
  int getHeight() const { return height; }
  Tuple getPixel(int row, int column) const;
  void writePixel(int row, int column, Tuple colour);
  void exportColours(Tuple pixel);
  void exportCanvas(std::ofstream &outfile);
};
