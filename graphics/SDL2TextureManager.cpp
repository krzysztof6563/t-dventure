#include "SDL2TextureManager.h"


bool SDL2TextureManager::loadTexture(std::string name, std::string path) {
    SDL_Texture* newTexture = NULL;
    SDL_Surface* tempSurface = IMG_Load(path.c_str());
    if (tempSurface == NULL) {
        throw std::runtime_error(IMG_GetError());
    } else {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( this->gRenderer, tempSurface );
        if (newTexture == NULL) {
            throw std::runtime_error(SDL_GetError());
        }
        // SDL2Texture tex;
        // tex.ptr = newTexture;
        this->textures[name] = newTexture;
        //Get rid of old loaded surface
        SDL_FreeSurface(tempSurface);
    }

    return true;
}

SDL_Texture* SDL2TextureManager::getTexture(std::string name) {
    auto tex = this->textures.at(name); 
    return tex;
    // return nullptr;
}

bool SDL2TextureManager::freeTexture(std::string name) {

    return true;
}
