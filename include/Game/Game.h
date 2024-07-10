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
#include <memory>

class Game
{
private:
    std::unique_ptr<Board> board;
    std::unique_ptr<Player> p;
    std::unique_ptr<Bot> bot;

    char back;
    bool exitGame = false;
    int botChoice = -1;
    int choice;

public:
    Game();
    bool firstMove();
    void startGame();
    void getInformationMatch();
    void Setting();
    void resetConsole();
    void getInformationPlayer();
    void goToBack(Menu &menu);
    void choiceLevelBot(Menu &mainMenu, Bot &gamePlayer);
    ~Game();
};

#endif
