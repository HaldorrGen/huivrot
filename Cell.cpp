#include "Cell.hpp"

Cell::Cell(int x1, int y1, bool isAlive1) {
  x = x1;
  y = y1;

  isAlive = isAlive1;
};

void Cell::
    decideIfCellWantToBeAliveBasedOnCalculatedNeighboursCountWhichWasCalculatedByBoard(

        int n) {

  if (!isAlive && n == 3)
    isAlive = true;
  if (isAlive && (n > 3 || n < 2))
    isAlive = false;
}

bool Cell::operator==(const Cell &c) const noexcept {
  return x == c.x && y == c.y && isAlive == c.isAlive;
}

// Implementing the '<' operator
bool Cell::operator<(const Cell &c) const noexcept {
  if (x < c.x)
    return true;
  if (x == c.x && y < c.y)
    return true;
  return false;
}

// Implementing the '>' operator
bool Cell::operator>(const Cell &c) const noexcept {
  return !(*this < c) && !(*this == c);
}
