#include "src/Game/Game.h"


int main() {
    Game *game = new Game();
    game->startGame();
    delete game; 
    return 0;
}
