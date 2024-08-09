#ifndef CELL_HPP
#define CELL_HPP
#include <string>

class Cell {
public:
  void
  decideIfCellWantToBeAliveBasedOnCalculatedNeighboursCountWhichWasCalculatedByBoard(
      int n);

  bool isAlive;
  int x, y;

  Cell(int x1, int y1, bool isAlive1);

  void revive() { isAlive = true; }

  void kill() { isAlive = false; }

  std::string print() const {
    if (isAlive) {
      return "x";
    } else {
      return "";
    }
  }
};

#endif
