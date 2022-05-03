#pragma once

#include <string>
#include <map>
#include <stdexcept>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "SDL2Texture.h"

class SDL2TextureManager {
    public:
        bool loadTexture(std::string name, std::string path);
        SDL_Texture* getTexture(std::string name);
        bool freeTexture(std::string name);
        SDL_Renderer* gRenderer = NULL;

    private:
        std::map<std::string, SDL_Texture*> textures;
};