#include "Cell.hpp"
#include "board.hpp"
#include <iostream>
#include <unistd.h>
#include <vector>

#define W 100
#define H 30

int main(int argc, char **argv) {
  std::vector<Cell> cells;



  Board b = Board(W, H);

  b.populateStartCells(cells);

  while (true) {
    b.printBoard();
    b.iterate();
    usleep(90000);
  }
}
