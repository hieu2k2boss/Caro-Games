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
    void playerWithBotMonteCarlo(Board &board, bool playerFirst, int simulations);
    virtual ~Bot();  // Virtual destructor if Bot will be inherited further
};

#endif
