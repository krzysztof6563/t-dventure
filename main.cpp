#include <iostream>
#include <memory>
#include "renderer/SDL2Renderer.h"

int main(int argc, char* args[]) {
    std::cout.setf(std::ios::unitbuf);
    std::unique_ptr<SDL2Renderer> mainRenderer(new SDL2Renderer());
    SDL_Event e;
    bool quit = false;
    int r = 0x00;
    int g = 0x00;
    int b = 0x00;

    mainRenderer->loadTexture("main", "assets/textures.png");
    mainRenderer->loadTexture("logo", "assets/logo.png");

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {

            switch (e.type) {
                case SDL_QUIT:
                    quit = true;
                    break;
                
                case SDL_KEYDOWN:
                    switch (e.key.keysym.sym) {
                        case SDLK_y: r += 10; break;
                        case SDLK_h: r -= 10; break;
                        case SDLK_u: g += 10; break;
                        case SDLK_j: g -= 10; break;
                        case SDLK_i: b += 10; break;
                        case SDLK_k: b -= 10; break;
                    }
                    break;
            }
        }

        mainRenderer->clearRenderer();        
        mainRenderer->renderTitleScreen();
        mainRenderer->updateWindow();
    }

    return 0;
}