#include "Cell.hpp"
#include "board.hpp"
#include <iostream>
#include <unistd.h>
#include <vector>

#define W 20
#define H 20

int main(int argc, char **argv) {
  std::vector<Cell> cells;
  cells.push_back(Cell(10, 10, true));
  cells.push_back(Cell(11, 10, true));
  cells.push_back(Cell(12, 10, true));
  cells.push_back(Cell(12, 9, true));
  cells.push_back(Cell(11, 8, true));

  Board b = Board(W, H);

  b.populateStartCells(cells);

  while (true) {
    b.printBoard();
    b.iterate();
    usleep(90000);
  }
}
