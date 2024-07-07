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
            cout << "Replay functionality not implemented." << endl;
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
    int win = 0, lose = 0, draw = 0;

    cout << "Enter name player: ";
    cin >> name;

    FileManager *file = new FileManager();
    file->createFolder(name);
    file->createFile(name, win, lose, draw, 1, 1, 1, 1, 1, 'X', board->getGrid());

    if (botChoice == 1) // Easy bot
    {
        gameBot.playerWithBot1(*board, firstMove());
    }
    else if (botChoice == 2) // Normal bot
    {
        int simulations = 10; // Number of simulations for Monte Carlo
        gameBot.playerWithBotMonteCarlo(*board, firstMove(), simulations);
    }
    else if (botChoice == 3) // Hard bot
    {
        int simulations = 100; // Number of simulations for Monte Carlo
        gameBot.playerWithBotMonteCarlo(*board, firstMove(), simulations);
    }
    else
    {
        cout << "Invalid choice. Returning to main menu." << endl;
    }

    cout << "Player " << gameBot.getCurrentPlayer() << " wins!" << endl;
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
    FileManager *file = new FileManager();
    file->showInformation();
    delete file;
}

Game::~Game(){};