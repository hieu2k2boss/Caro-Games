#include "Bot.h"

using namespace std;

Bot::Bot(char currentPlayer) : Player(currentPlayer) {}

Bot::Bot(int x, int y, char currentPlayer) : Player(x, y, currentPlayer) {}

bool Bot::simulateGame(Board &board, int x, int y)
{
    char player = currentPlayer;
    vector<pair<int, int>> validMoves;
    while (true)
    {
        if (checkWinCondition(x, y, board))
        {
            return player == currentPlayer;
        }
        player = (player == 'X') ? 'O' : 'X';

        validMoves.clear();
        for (int i = 0; i < board.getSize(); ++i)
        {
            for (int j = 0; j < board.getSize(); ++j)
            {
                if (board.getCell(i, j) == ' ')
                {
                    validMoves.push_back(make_pair(i, j));
                }
            }
        }

        if (validMoves.empty())
        {
            return false; // Draw
        }

        int moveIndex = rand() % validMoves.size();
        x = validMoves[moveIndex].first;
        y = validMoves[moveIndex].second;
        board.updateBoard(x, y, player);
    }
}

void Bot::simulateMove(Board &board, int x, int y, int simulations, atomic<int> &winCount)
{
    for (int j = 0; j < simulations; ++j)
    {
        Board simulationBoard = board;
        simulationBoard.updateBoard(x, y, currentPlayer);
        if (simulateGame(simulationBoard, x, y))
        {
            ++winCount;
        }
    }
}

bool Bot::makeMonteCarloMove(Board &board, int simulations)
{
    static random_device rd;
    static mt19937 gen(rd());

    vector<pair<int, int>> validMoves;
    for (int i = 0; i < board.getSize(); ++i)
    {
        for (int j = 0; j < board.getSize(); ++j)
        {
            if (board.getCell(i, j) == ' ')
            {
                validMoves.push_back(make_pair(i, j));
            }
        }
    }

    vector<atomic<int>> winCounts(validMoves.size());
    vector<thread> threads;

    for (int i = 0; i < validMoves.size(); ++i)
    {
        threads.push_back(thread(&Bot::simulateMove, this, ref(board), validMoves[i].first, validMoves[i].second, simulations, ref(winCounts[i])));
    }

    for (auto &th : threads)
    {
        th.join();
    }

    int bestMoveIndex = 0;
    for (int i = 1; i < winCounts.size(); ++i)
    {
        if (winCounts[i] > winCounts[bestMoveIndex])
        {
            bestMoveIndex = i;
        }
    }

    int x = validMoves[bestMoveIndex].first;
    int y = validMoves[bestMoveIndex].second;
    board.updateBoard(x, y, currentPlayer);
    return true;
}

void Bot::playerWithBotMonteCarlo(Board &board, bool playerFirst, int simulations, FileManager &filename, std::string name)
{
    int turn = 0;
    int win, lose, draw;
    int choiceContinue;

    filename.createFile(name, 0, 0, 0, playerFirst, 0, turn, 0, 0, currentPlayer, board.getGrid()); // Tạo file

    bool gameEnd = false;
    while (!gameEnd)
    {
        board.display();
        if (playerFirst)
        {
            if (!makeMove(board))
            {
                cout << "Invalid move. Try again." << endl;
                continue;
            }
            filename.updateFileGame(name, playerFirst, 0, turn, x, y, currentPlayer, board.getGrid());
            turn++;
            board.display();
            if (checkWinCondition(x, y, board))
            {
                board.display();
                cout << "Player " << currentPlayer << " wins!" << endl;

                win = filename.getValue(name, "Win:") + 1;
                lose = filename.getValue(name, "Lose:");
                draw = filename.getValue(name, "Draw:");
                filename.recordPlayerInfo(name, win, lose, draw);

                cout << "Do you want to continue playing?" << endl;
                cout << "Yes: 1 , No:0 " << endl;
                cin >> choiceContinue;
                if (choiceContinue == 1)
                {
                    board.resetBoard();
                }
                else if (choiceContinue == 0)
                {
                    gameEnd = true;
                    break;
                }
            }
            switchPlayer();
            if (makeMonteCarloMove(board, simulations))
            {
                filename.updateFileGame(name, playerFirst, 0, turn, x, y, currentPlayer, board.getGrid());
                turn++;
                if (checkWinCondition(x, y, board))
                {
                    board.display();
                    cout << "Bot wins!" << endl;

                    win = filename.getValue(name, "Win:");
                    lose = filename.getValue(name, "Lose:") + 1;
                    draw = filename.getValue(name, "Draw:");
                    filename.recordPlayerInfo(name, win, lose, draw);

                    cout << "Do you want to continue playing?" << endl;
                    cout << "Yes: 1 , No:0 " << endl;
                    cin >> choiceContinue;
                    if (choiceContinue == 1)
                    {
                        board.resetBoard();
                    }
                    else if (choiceContinue == 0)
                    {
                        gameEnd = true;
                        break;
                    }
                }
                switchPlayer();
            }
        }
        else
        {
            if (makeMonteCarloMove(board, simulations))
            {
                filename.updateFileGame(name, playerFirst, 0, turn, x, y, currentPlayer, board.getGrid());
                turn++;
                if (checkWinCondition(x, y, board))
                {
                    board.display();
                    cout << "Bot wins!" << endl;

                    win = filename.getValue(name, "Win:");
                    lose = filename.getValue(name, "Lose:") + 1;
                    draw = filename.getValue(name, "Draw:");
                    filename.recordPlayerInfo(name, win, lose, draw);

                    cout << "Do you want to continue playing?" << endl;
                    cout << "Yes: 1 , No:0 " << endl;
                    cin >> choiceContinue;
                    if (choiceContinue == 1)
                    {
                        board.resetBoard();
                    }
                    else if (choiceContinue == 0)
                    {
                        gameEnd = true;
                        break;
                    }
                }
                switchPlayer();
            }
            board.display();
            if (!makeMove(board))
            {
                cout << "Invalid move. Try again." << endl;
                continue;
            }
            filename.updateFileGame(name, playerFirst, 0, turn, x, y, currentPlayer, board.getGrid());
            turn++;
            if (checkWinCondition(x, y, board))
            {
                board.display();
                cout << "Player " << currentPlayer << " wins!" << endl;

                win = filename.getValue(name, "Win:") + 1;
                lose = filename.getValue(name, "Lose:");
                draw = filename.getValue(name, "Draw:");
                filename.recordPlayerInfo(name, win, lose, draw);

                cout << "Do you want to continue playing?" << endl;
                cout << "Yes: 1 , No:0 " << endl;
                cin >> choiceContinue;
                if (choiceContinue == 1)
                {
                    board.resetBoard();
                }
                else if (choiceContinue == 0)
                {
                    gameEnd = true;
                    break;
                }
            }
            switchPlayer();
        }
    }
}

Bot::~Bot() {}
