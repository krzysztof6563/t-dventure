#include <iostream>
#include "Game.h"

std::unique_ptr<Game> game;

int main(int argc, char* args[]) {
    std::cout.setf(std::ios::unitbuf);
    game = std::make_unique<Game>();
    try
    {
        game->init();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    game->mainLoop();
    game->shutdown();
    return 0;
}