#include "Cell.hpp"

Cell::Cell(int x1, int y1, bool isAlive1) {
  x = x1;
  y = y1;

  isAlive = isAlive1;
};

void Cell::iterate(int n) { //decideTOCHKAIfCellWantToBeAliveTOCHKABasedOnCalculatedNeighboursCountTOCHKAWhichWasCalculatedByBoard
  if (!isAlive && n == 3)
    isAlive = true;
  if (isAlive && (n > 3 || n < 2))
    isAlive = false;

}
