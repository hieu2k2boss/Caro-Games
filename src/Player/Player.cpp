#include "Player.h"

using namespace std;

Player::Player(char currentPlayer) : currentPlayer(currentPlayer){};

Player::Player(int x, int y, char currentPlayer) : x(x), y(y), currentPlayer(currentPlayer) {}

bool Player::makeMove(Board &board)
{
    cout << "Player " << currentPlayer << ", enter your move (row and column): ";
    cin >> x >> y;
    if (board.updateBoard(x, y, currentPlayer))
    {
        return true;
    }
    return false;
}

bool Player::checkWinCondition(int x, int y, Board &board)
{
    char playerSymbol = board.getCell(x, y);
    return checkDirection(x, y, 1, 0, playerSymbol, board) || // Horizontal
           checkDirection(x, y, 0, 1, playerSymbol, board) || // Vertical
           checkDirection(x, y, 1, 1, playerSymbol, board) || // Diagonal
           checkDirection(x, y, 1, -1, playerSymbol, board);  // Anti-diagonal
}

bool Player::checkDirection(int x, int y, int dx, int dy, char playerSymbol, Board &board)
{
    int count = 1;

    // Check in the positive direction
    for (int step = 1; step < 4; ++step)
    {
        int newX = x + step * dx;
        int newY = y + step * dy;
        if (newX >= 0 && newX < board.getSize() && newY >= 0 && newY < board.getSize() && board.getCell(newX, newY) == playerSymbol)
        {
            count++;
        }
        else
        {
            break;
        }
    }

    // Check in the negative direction
    for (int step = 1; step < 4; ++step)
    {
        int newX = x - step * dx;
        int newY = y - step * dy;
        if (newX >= 0 && newX < board.getSize() && newY >= 0 && newY < board.getSize() && board.getCell(newX, newY) == playerSymbol)
        {
            count++;
        }
        else
        {
            break;
        }
    }

    return count >= 4; // Winning condition for 4 in a row
}

void Player::playerWithPlayer(Board &board)
{
    bool gameEnd = false;
    while (!gameEnd)
    {
        board.display();
        if (!makeMove(board))
        {
            cout << "Invalid move. Try again." << endl;
            continue;
        }
        if (checkWinCondition(x, y, board))
        {
            board.display();
            gameEnd = true;
            break;
        }
        switchPlayer();
    }
};

void Player::switchPlayer() { currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; };

char Player::getCurrentPlayer()
{
    return currentPlayer;
}

Player::~Player()
{
}