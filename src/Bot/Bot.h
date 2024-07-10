#ifndef BOT_H
#define BOT_H

#include "../Player/Player.h" // Include Player.h for inheritance
#include "../FileManager/FileManager.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <string>
#include<thread>
#include<mutex>
#include <utility>
#include <random>
#include <atomic>

class Bot : public Player
{

private:
    bool gameEnd ;
    std::mutex mtx;
public:
    Bot(char currentPlayer);
    Bot(int x, int y, char currentPlayer);
    bool makeMonteCarloMove(Board &board, int simulations);
    bool simulateGame(Board &board, int x, int y);
    void playerWithBotMonteCarlo(Board &board, bool playerFirst, int simulations, FileManager &filename, std::string name);
    void simulateMove(Board &board, int x, int y, int simulations, std::atomic<int> &winCount);
    virtual ~Bot(); // Virtual destructor if Bot will be inherited further
};

#endif
