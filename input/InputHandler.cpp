#include "InputHandler.h"

int InputHandler::getCurrentKey() {
    while (SDL_PollEvent(&e) != 0) {
        switch (e.type) {
            // case SDL_KEYDOWN:
            //     switch (e.key.keysym.sym) {
            //         case SDLK_y: r += 10; break;
            //         case SDLK_h: r -= 10; break;
            //         case SDLK_u: g += 10; break;
            //         case SDLK_j: g -= 10; break;
            //         case SDLK_i: b += 10; break;
            //         case SDLK_k: b -= 10; break;
            //     }
            //     break;
        }
    }

    return 0;
}

bool InputHandler::shouldGameClose() {
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_EventType::SDL_QUIT) 
            return true;
    }

    return false;
}