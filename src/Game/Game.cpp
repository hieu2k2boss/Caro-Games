#include "Game.h"

using namespace std;

Game::Game() {}

void Game::startGame()
{
    Menu *menu = new Menu();
    choice = menu->choiceMainMenu();

    while (!exitGame)
    {
        p = new Player('X');
        board = new Board(10);
        bot = new Bot('X');
        switch (choice)
        {
        case 1:
            p->playerWithPlayer(*board);
            cout << "Player " << p->getCurrentPlayer() << " wins!" << endl;
            goToBack(*menu);
            break;
        case 2:
            choiceLevelBot(*menu, *bot);
            goToBack(*menu);
            break;
        case 3:
            getInformationMatch();
            goToBack(*menu);
            break;
        case 4:
            getInformationPlayer();
            goToBack(*menu);
            break;
        case 5:
        {
            FileManager *openGuild = new FileManager();
            openGuild->showGuild();
            goToBack(*menu);
            delete openGuild;
            break;
        }
        case 6:
            Setting();
            goToBack(*menu);
            break;
        case 7:
            exitGame = true;
            cout << "Exiting game." << endl;
            break;
        default:
            cout << "Please enter a valid choice." << endl;
            goToBack(*menu);
            break;
        }
    }

    delete menu;
}

void Game::goToBack(Menu &mainMenu)
{
    delete p;
    delete board;
    do
    {
        cout << "\nPress 'b' to go back to the main menu: ";
        cin >> back;
    } while (back != 'b');
    // Quay lại menu chính sau khi người dùng bấm 'b'
    resetConsole();
    choice = mainMenu.choiceMainMenu();
}

void Game::choiceLevelBot(Menu &mainMenu, Bot &gameBot)
{
    resetConsole();
    botChoice = mainMenu.choicePlayWithBot();
    string name;
    // int win = 0, lose = 0, draw = 0;

    cout << "Enter name player: ";
    cin >> name;

    FileManager *file = new FileManager();
    file->createFolder(name);

    if (botChoice == 1) // Easy bot
    {
        gameBot.playerWithBot1(*board, firstMove(), *file, name);
    }
    else if (botChoice == 2) // Normal bot
    {
        int simulations = 10; // Number of simulations for Monte Carlo
        gameBot.playerWithBotMonteCarlo(*board, firstMove(), simulations, *file, name);
    }
    else if (botChoice == 3) // Hard bot
    {
        int simulations = 100; // Number of simulations for Monte Carlo
        gameBot.playerWithBotMonteCarlo(*board, firstMove(), simulations, *file, name);
    }
    else
    {
        cout << "Invalid choice. Returning to main menu." << endl;
    }

    cout << "Player " << gameBot.getCurrentPlayer() << " wins!" << endl;

    delete file;
}

void Game::resetConsole()
{
#ifdef _WIN32
    system("CLS");
#else
    system("clear");
#endif
}

bool Game ::firstMove()
{
    int firstMoveChoice;
    cout << "Do you want to go first? (1 for Yes, 0 for No): ";
    cin >> firstMoveChoice;
    bool playerFirst = (firstMoveChoice == 1);
    return playerFirst;
}

void Game ::getInformationPlayer()
{
    resetConsole();

    cout << CYAN << "1." << RESET << " Show information player" << endl;
    cout << CYAN << "2." << RESET << " Top player" << endl;

    cout << "Enter your choice: ";
    int choiceInformation;
    cin >> choiceInformation;
    FileManager *file = new FileManager();
    if (choiceInformation == 1)
    {
        resetConsole();
        file->showInformation();
    }
    else if (choiceInformation == 2)
    {
        resetConsole();
        file->displayTopPlayers();
    }

    delete file;
}

void Game ::getInformationMatch()
{
    resetConsole();
    FileManager *file = new FileManager();
    file->showMatch();
    delete file;
}

void Game ::Setting(){
    resetConsole();
    int choiceSetting;
    FileManager *file = new FileManager();
    cout << "1. Delete all data !!!" << endl;
    cout << "Enter your choice: ";
    cin >> choiceSetting;
    if (choiceSetting == 1)
    {
        file->removeAllFilesAndFolders("H:\\Download\\FPT\\TaiLieu\\BaiTap\\Caro\\Status");
    }
    delete file;
}

Game::~Game(){};