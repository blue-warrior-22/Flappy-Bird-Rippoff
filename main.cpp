#include <iostream>
#include "SDL.h"
#include "game.hpp"

Game *game = nullptr;

int main() {
    game = new Game();

    game->init("Flappy Rippoff", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 960, 540, false);

    while(game -> running()){
        game->handleEvents();
        game->update();
        game->render();
    }
    game->clean();
    return 0;
}
