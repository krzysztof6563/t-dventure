#pragma once
#include "AbstractRenderer.h"
#include <ostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>

class SDL2Renderer : AbstractRenderer {
    public:
        SDL2Renderer();
        ~SDL2Renderer();
        int printText(std::string text, int x, int y);
        int updateWindow();
        int paintBackgroundColor(int r, int g, int b);
        bool loadTexture(std::string name, std::string path);
        void renderTitleScreen();
        void clearRenderer();

    private:
        const int SCREEN_HEIGHT = 720;
        const int SCREEN_WIDTH = 1280;

        SDL_Window* window = NULL;
        SDL_Surface* screenSurface = NULL;
        SDL_Renderer* gRenderer = NULL;

        //TODO: Move to SDL2_TextureManager;
        std::map<std::string, SDL_Texture*> textures;
};