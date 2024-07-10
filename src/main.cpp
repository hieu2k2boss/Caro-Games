#include "../include/Game/Game.h"

/*
Build chương trình 
cd CARO
mkdir build
cd build
cmake ..
cmake --build .
*/

int main() {
    Game *game = new Game();
    game->startGame();
    delete game; 
    return 0;
}
