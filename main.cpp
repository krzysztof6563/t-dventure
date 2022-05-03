#include <iostream>
#include "Game.h"

std::unique_ptr<Game> game;

int main(int argc, char* args[]) {
    std::cout.setf(std::ios::unitbuf);
    game = std::make_unique<Game>();
    game->init();
    game->mainLoop();
    game->shutdown();
    return 0;
}