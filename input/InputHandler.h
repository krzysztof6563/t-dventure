#pragma once
#include <SDL2/SDL.h>


class InputHandler {
    public:
        bool shouldGameClose();
        int getCurrentKey();

    private: 
        SDL_Event e;
};