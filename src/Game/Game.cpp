#include "../../include/Game/Game.h"

using namespace std;

Game::Game() {}

void Game::startGame()
{
    unique_ptr<Menu> menu = make_unique<Menu>();
    choice = menu->choiceMainMenu();

    while (!exitGame)
    {
        board = make_unique<Board>(10);
        bot = make_unique<Bot>('O');
        p = make_unique<Player>('X');

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
            unique_ptr<FileManager> openGuild = make_unique<FileManager>();
            openGuild->showGuild();
            goToBack(*menu);
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
}

void Game::goToBack(Menu &mainMenu)
{
    p.reset();
    board.reset();
    do
    {
        cout << "\nPress 'b' to go back to the main menu: ";
        cin >> back;
    } while (back != 'b');
    resetConsole();
    choice = mainMenu.choiceMainMenu();
}

void Game::choiceLevelBot(Menu &mainMenu, Bot &gameBot)
{
    resetConsole();
    botChoice = mainMenu.choicePlayWithBot();
    string name;

    cout << "Enter name player: ";
    cin >> name;

    unique_ptr<FileManager> file = make_unique<FileManager>();
    file->createFolder(name);

    if (botChoice == 1) // Easy bot
    {
        int simulations = 100; // Number of simulations for Monte Carlo
        gameBot.playerWithBotMonteCarlo(*board, firstMove(), simulations, *file, name);
    }
    else if (botChoice == 2) // Normal bot
    {
        int simulations = 500; // Number of simulations for Monte Carlo
        gameBot.playerWithBotMonteCarlo(*board, firstMove(), simulations, *file, name);
    }
    else if (botChoice == 3) // Hard bot
    {
        int simulations = 1000; // Number of simulations for Monte Carlo
        gameBot.playerWithBotMonteCarlo(*board, firstMove(), simulations, *file, name);
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

bool Game::firstMove()
{
    int firstMoveChoice;
    cout << "Do you want to go first? (1 for Yes, 0 for No): ";
    cin >> firstMoveChoice;
    return firstMoveChoice == 1;
}

void Game::getInformationPlayer()
{
    resetConsole();

    cout << CYAN << "1." << RESET << " Show information player" << endl;
    cout << CYAN << "2." << RESET << " Top player" << endl;

    cout << "Enter your choice: ";
    int choiceInformation;
    cin >> choiceInformation;
    unique_ptr<FileManager> file = make_unique<FileManager>();
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
}

void Game::getInformationMatch()
{
    resetConsole();
    unique_ptr<FileManager> file = make_unique<FileManager>();
    file->showMatch();
}

void Game::Setting(){
    resetConsole();
    int choiceSetting;
    unique_ptr<FileManager> file = make_unique<FileManager>();
    cout << "1. Delete all data !!!" << endl;
    cout << "Enter your choice: ";
    cin >> choiceSetting;
    if (choiceSetting == 1)
    {
        file->removeAllFilesAndFolders("H:\\Download\\FPT\\TaiLieu\\BaiTap\\Caro\\Status");
    }
}

Game::~Game() {}
