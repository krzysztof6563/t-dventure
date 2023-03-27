#include "SDL2TextureManager.h"

SDL2TextureManager::~SDL2TextureManager() {
    for (auto c : textures)
    {
        SDL_DestroyTexture(c.second->ptr);
        delete c.second;
    }
    
}

bool SDL2TextureManager::loadTexture(std::string name, std::string path) {
    SDL_Texture* newTexture = nullptr;
    SDL_Surface* tempSurface = IMG_Load(path.c_str());
    if (tempSurface == NULL) {
        throw std::runtime_error(IMG_GetError());
    } else {
        // Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( this->gRenderer, tempSurface );
        if (newTexture == NULL) {
            throw std::runtime_error(SDL_GetError());
        }
        SDL2Texture* tex = new SDL2Texture();
        tex->ptr = newTexture;
        tex->height = tempSurface->h;
        tex->width = tempSurface->w;
        tex->path = path;
        tex->name = name;
        this->textures[name] = tex;
        // Get rid of old loaded surface
        SDL_FreeSurface(tempSurface);
    }

    return true;
}

SDL_Texture* SDL2TextureManager::getTexture(std::string name) {
    return this->textures.at(name)->ptr; 
}

bool SDL2TextureManager::freeTexture(std::string name) {

    return true;
}
