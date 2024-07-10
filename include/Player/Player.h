#ifndef PLAYER_H
#define PLAYER_H

#include "../Board/Board.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

class Player
{
protected:
    int x;
    int y;
    char currentPlayer;

public:
    Player(char currentPlayer);
    Player(int x, int y, char currentPlayer);
    bool makeMove(Board &board);
    bool checkWinCondition(int x, int y, Board &board);
    char getCurrentPlayer();
    bool checkDirection(int x, int y, int dx, int dy, char playerSymbol, Board &board);
    void switchPlayer();
    void playerWithPlayer(Board &board);
    ~Player();
};

#endif