#ifndef GAME_H
#define GAME_H

#include "../Board/Board.h"
#include "../Player/Player.h"
#include "../Menu/Menu.h"
#include "../Bot/Bot.h"
#include <iostream>
#include <fstream>
#include "../FileManager/FileManager.h"
#include <windows.h>

class Game
{
private:
    Board *board;
    Player *p; 
    Bot *bot;
    char back;
    bool exitGame = false;
    int botChoice = -1;
    int choice ; 
    std::string playerName;

public:
    Game();
    void startGame();
    void goToBack(Menu &menu);
    void choiceLevelBot(Menu &mainMenu, Bot &gamePlayer) ;
    bool firstMove();
    void resetConsole(); 
    void endGame(bool playerWon, bool draw);
    void updatePlayerScore(int points);
    void inputPlayerName(); 
    ~Game();
    
};

#endif
