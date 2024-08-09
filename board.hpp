#include "Cell.hpp"
#include <iostream>
#include <vector>

class Board {
public:
  Board(int width, int height);
  ~Board();
  void iterate();

  void populateStartCells(std::vector<Cell> newCells);
  void printBoard();

private:
  int h, w;
  Cell **cells;
  Cell **Tcells;
  int CountNeighbours(int i, int j); // sosedi
};
