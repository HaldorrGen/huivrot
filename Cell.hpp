#ifndef CELL_HPP
#define CELL_HPP
#include <string>

class Cell {
public:
    bool isAlive;
    int x, y;

    // Конструктор по умолчанию
    Cell();
    
    // Конструктор с параметрами
    Cell(int x1, int y1, bool isAlive);

    void revive(){
        isAlive = true;
    }

    void kill() {
        isAlive = false;
    }
    
    // Метод для получения строки представления клетки
    std::string print() const {
        if (isAlive) {
            return "x";  
        } else {
            return "";   
        }
    }

};

#endif // CELL_HPP
