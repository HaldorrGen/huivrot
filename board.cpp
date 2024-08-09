#include "board.hpp"
#include "Cell.hpp"

Board::Board(int width, int height)
{
    cells = (Cell **)malloc(sizeof(Cell *) * height);
    Tcells = (Cell **)malloc(sizeof(Cell *) * height);
    for (int i = 0; i < height; i++)
    {
        cells[i] = (Cell *)malloc(sizeof(Cell) * width);
        Tcells[i] = (Cell *)malloc(sizeof(Cell) * width);
    }

    w = width;
    h = height;

};
Board::~Board()
{
    for (int i = 0; i < h; i++)
    {
        free(Tcells[i]);
        free(cells[i]);
    }

    free(Tcells);
    free(cells);
    
}


void Board::iterate(){
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            //1. CountNeggers dlya kletki cells[i][j]
            //2. Cell::huita Tcells[i][j]
        }
    }


    // cells = tCells tCells = tmp
    Cell** tmp = cells;
    cells = Tcells;
    Tcells = tmp;
};



