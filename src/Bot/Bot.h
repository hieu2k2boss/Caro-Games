#ifndef BOT_H
#define BOT_H

#include "../Player/Player.h"  // Include Player.h for inheritance
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>


class Bot : public Player {
private:
    
    
public:
    Bot(char currentPlayer);
    Bot(int x, int y, char currentPlayer);
    bool makeRandomMove(Board &board);
    bool makeMonteCarloMove(Board &board, int simulations);
    bool simulateGame(Board &board, int x, int y);
    void playerWithBot1(Board &board, bool playerFirst);
    void playerWithBot2(Board &board, bool playerFirst, int simulations);
    void playerWithBot3(Board &board, bool playerFirst);  // If Bot has specific play methods
    virtual ~Bot();  // Virtual destructor if Bot will be inherited further
};

#endif
