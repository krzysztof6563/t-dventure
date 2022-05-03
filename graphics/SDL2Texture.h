#pragma once

#include <string>

class SDL2Texture {
    public:
        int width = 0;
        int height = 0;
        std::string name = "";
        std::string path = "";
        SDL_Texture* ptr;
        ~SDL2Texture() {
            SDL_DestroyTexture(this->ptr);
        }
};