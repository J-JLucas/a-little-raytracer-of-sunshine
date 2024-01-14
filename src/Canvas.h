// Represents the screen to be drawn to
#pragma once
#include <string>
#include <vector>

class Canvas {
private:
  int width{};
  int height{};
  std::vector<std::vector<class Tuple>> pixelArray{};

public:
  Canvas(int width, int height);

  int getWidth() const { return width; }
  int getHeight() const { return height; }
  Tuple getPixel(int row, int column) const;
  void writePixel(int row, int column, Tuple colour);
  void exportCanvas(const std::string &filename) const;
};
