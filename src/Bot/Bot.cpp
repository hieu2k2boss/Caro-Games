#include "../../include/Bot/Bot.h"

using namespace std;

Bot::Bot(char currentPlayer) : Player(currentPlayer) {}

Bot::Bot(int x, int y, char currentPlayer) : Player(x, y, currentPlayer) {}

bool Bot::simulateGame(Board &board, int x, int y)
{
    char player = currentPlayer;
    while (true)
    {
        if (checkWinCondition(x, y, board))
        {
            return player == currentPlayer;
        }
        player = (player == 'X') ? 'O' : 'X';

        // Get all valid moves
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

        if (validMoves.empty())
        {
            return false; // Draw
        }

        // Make a random move
        int moveIndex = rand() % validMoves.size();
        x = validMoves[moveIndex].first;
        y = validMoves[moveIndex].second;
        board.updateBoard(x, y, player);
    }
}

bool Bot::makeMonteCarloMove(Board &board, int simulations)
{
    srand(time(0));
    vector<pair<int, int>> validMoves;

    // Get all valid moves
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

    vector<int> winCounts(validMoves.size(), 0);

    // Simulate each move
    for (int i = 0; i < validMoves.size(); ++i)
    {
        for (int j = 0; j < simulations; ++j)
        {
            Board simulationBoard = board;
            simulationBoard.updateBoard(validMoves[i].first, validMoves[i].second, currentPlayer);
            if (simulateGame(simulationBoard, validMoves[i].first, validMoves[i].second))
            {
                winCounts[i]++;
            }
        }
    }

    // Find the move with the highest win count
    int bestMoveIndex = 0;
    for (int i = 1; i < winCounts.size(); ++i)
    {
        if (winCounts[i] > winCounts[bestMoveIndex])
        {
            bestMoveIndex = i;
        }
    }

    // Make the best move
    x = validMoves[bestMoveIndex].first;
    y = validMoves[bestMoveIndex].second;
    board.updateBoard(x, y, currentPlayer);
    return true;
}

void Bot::playerWithBotMonteCarlo(Board &board, bool playerFirst, int simulations, FileManager &filename, std::string name)
{
    int turn = 0;

    filename.createFile(name, 0, 0, 0, playerFirst, 0, turn, 0, 0, currentPlayer, board.getGrid()); // Tạo file
    bool gameEnd = false;
    int win, lose, draw;
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
                gameEnd = true;

                win = filename.getValue(name, "Win:") + 1;
                lose = filename.getValue(name, "Lose:");
                draw = filename.getValue(name, "Draw:");
                filename.recordPlayerInfo(name, win, lose, draw);

                break;
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
                    gameEnd = true;
                    win = filename.getValue(name, "Win:");
                    lose = filename.getValue(name, "Lose:") + 1;
                    draw = filename.getValue(name, "Draw:");
                    filename.recordPlayerInfo(name, win, lose, draw);
                    break;
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
                    gameEnd = true;
                    win = filename.getValue(name, "Win:");
                    lose = filename.getValue(name, "Lose:") + 1;
                    draw = filename.getValue(name, "Draw:");
                    filename.recordPlayerInfo(name, win, lose, draw);
                    break;
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
                gameEnd = true;
                win = filename.getValue(name, "Win:") + 1;
                lose = filename.getValue(name, "Lose:");
                draw = filename.getValue(name, "Draw:");
                filename.recordPlayerInfo(name, win, lose, draw);
                break;
            }
            switchPlayer();
        }
    }
}

Bot::~Bot() {}