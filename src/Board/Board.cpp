#include "Board.h"
#include "../Menu/Menu.h"

using namespace std;

Board::Board(int size) : size(size) {
    grid.resize(size, std::vector<char>(size, ' ')); // Khởi tạo bảng 10x10 với ký tự trống ' '
}

void Board::display() {
    // Xóa màn hình
  
    #ifdef _WIN32
        system("CLS");
    #else
        system("clear");
    #endif
   
    cout << "==> "<<GREEN<<"Player 1:"<<RESET<<"X"<< BLUE <<" Player 2" << RESET<< ":O"<<endl; 
    cout << "  0   1   2   3   4   5   6   7   8   9 "<< endl;
    cout << CYAN<< "-----------------------------------------"<<RESET<< endl;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << CYAN <<"| "<< RESET << grid[i][j] << " ";
        }
        cout << CYAN << "|" << RESET << i<< endl;
        for (int j = 0; j < size; ++j) {
            cout << CYAN  << "|---" << RESET;
        }
        cout<< CYAN<<"|" << RESET << endl;
    }
}

bool Board::updateBoard(int x, int y, char playerSymbol) {
    if (x < 0 || x >= size || y < 0 || y >= size || grid[x][y] != ' ') {
        return false; // Không thể cập nhật vị trí đã đánh
    }
    grid[x][y] = playerSymbol;
    moveHistory.push({x, y}); // Lưu nước đi vào stack
    return true;
}

char Board::getCell(int x, int y) {
    return grid[x][y];
}

int Board::getSize() {
    return size;
}

void Board::undoMove(){
        if (!moveHistory.empty()) {
        auto lastMove = moveHistory.top();
        grid[lastMove.first][lastMove.second] = ' '; // Hoàn tác nước đi trên bảng
        moveHistory.pop(); // Xóa nước đi khỏi stack
    }
};