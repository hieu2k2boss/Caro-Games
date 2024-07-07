#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <stack>
#include <iostream>
#include <iomanip>

class Board
{
private:
    std::vector<std::vector<char>> grid;
    int size;
    std::stack<std::pair<int, int>> moveHistory; // Stack to store moves
public:
    Board(int size = 10);

    void display();
    bool updateBoard(int x, int y, char playerSymbol);
    char getCell(int x, int y);
    int getSize();
    void undoMove();
    const std::vector<std::vector<char>> &getGrid() const;

};

#endif