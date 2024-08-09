#include <iostream>
#include "Cell.hpp"

class Board
{
public:
    Board(int width, int height);
    ~Board();
    void iterate();


private:
    int h, w;
    Cell **cells;
    Cell **Tcells;
    int CountNeighbours(Cell c);// sosedi

};
