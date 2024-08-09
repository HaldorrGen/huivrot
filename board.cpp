#include "board.hpp"
#include "Cell.hpp"
#include <set>

Board::Board(int width, int height) {

  std::set<Cell> alive_set;

  cells = (Cell **)malloc(sizeof(Cell *) * height);
  Tcells = (Cell **)malloc(sizeof(Cell *) * height);
  for (int i = 0; i < height; i++) {
    cells[i] = (Cell *)malloc(sizeof(Cell) * width);
    Tcells[i] = (Cell *)malloc(sizeof(Cell) * width);
  }

  w = width;
  h = height;
};
Board::~Board() {
  for (int i = 0; i < h; i++) {
    free(Tcells[i]);
    free(cells[i]);
  }

  free(Tcells);
  free(cells);
}

void Board::iterate() {
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      int n = CountNeighbours(i, j);
      Tcells[i][j] = cells[i][j];
      Tcells[i][j].iterate(n);//decideTOCHKAIfCellWantToBeAliveTOCHKABasedOnCalculatedNeighboursCountTOCHKAWhichWasCalculatedByBoard
    }
  }

  // cells = tCells tCells = tmp
  Cell **tmp = cells;
  cells = Tcells;
  Tcells = tmp;
};

int Board::CountNeighbours(int i, int j) {

  int n = 0;
  for (int k = -1; k <= 1; k++) {
    for (int hh = -1; hh <= 1; hh++) {
      if (k == 0 && hh == 0)
        continue;

      int x = (i + k + h) % h;
      int y = (j + hh + w) % w;

      if (cells[x][y].isAlive)
        n++;
    }
  }

  return n;
}
void Board::populateStartCells(std::vector<Cell> newCells) {
  for (auto c : newCells) {
    cells[c.y][c.x] = c;
  }
}

void Board::printBoard() {

  system("clear");

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {

      if (cells[i][j].isAlive)
        std::cout << "*";
      else
        std::cout << ".";
    }
    std::cout << std::endl;
  }
}
