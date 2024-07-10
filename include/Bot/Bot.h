#ifndef BOT_H
#define BOT_H

#include "../../include/Player/Player.h"  // Include Player.h for inheritance
#include "../../include/FileManager/FileManager.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include<string>


class Bot : public Player {
public:
    Bot(char currentPlayer);
    Bot(int x, int y, char currentPlayer);
    bool makeMonteCarloMove(Board &board, int simulations);
    bool simulateGame(Board &board, int x, int y);
    void playerWithBotMonteCarlo(Board &board, bool playerFirst, int simulations,FileManager &filename, std::string name);
    virtual ~Bot();  // Virtual destructor if Bot will be inherited further
};

#endif