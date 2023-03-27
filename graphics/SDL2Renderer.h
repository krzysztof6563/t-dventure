#pragma once
#include <ostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>
#include <memory>
#include "SDL2TextureManager.h"

class SDL2Renderer {
    public:
        SDL2Renderer();
        ~SDL2Renderer();
        int printText(std::string text, int x, int y);
        int updateWindow();
        int paintBackgroundColor(int r, int g, int b);
        void renderTitleScreen();
        void clearRenderer();
        SDL_Renderer* getGPURenderer();
        std::shared_ptr<SDL2TextureManager> textureManager;

    private:
        const int SCREEN_HEIGHT = 720;
        const int SCREEN_WIDTH = 1280;

        SDL_Window* window = NULL;
        // SDL_Surface* screenSurface = NULL;
        SDL_Renderer* gRenderer = NULL;
};