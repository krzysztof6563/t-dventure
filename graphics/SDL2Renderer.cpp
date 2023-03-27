#include "SDL2Renderer.h"

SDL2Renderer::SDL2Renderer() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        throw std::runtime_error(SDL_GetError());
    } else {
        this->window = SDL_CreateWindow(
            "T-Dventure", 
            SDL_WINDOWPOS_UNDEFINED, 
            SDL_WINDOWPOS_UNDEFINED, 
            this->SCREEN_WIDTH, 
            this->SCREEN_HEIGHT, 
            SDL_WINDOW_SHOWN 
        );

        if (window == NULL) {
            throw std::runtime_error(SDL_GetError());
        } else {
            // this->screenSurface = SDL_GetWindowSurface(this->window);
            this->gRenderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
            if (this->gRenderer == nullptr) {
                throw std::runtime_error(SDL_GetError());
            }
            SDL_SetRenderDrawColor( this->gRenderer, 0x0, 0x0, 0x0, 0xFF );

            int imgFlags = IMG_INIT_PNG;
            if( !( IMG_Init( imgFlags ) & imgFlags ) )
            {
                throw std::runtime_error(IMG_GetError());
            }
        }
    }
}

int SDL2Renderer::printText(std::string text, int x, int y) {
    
    return 0;
}


int SDL2Renderer::updateWindow() {
    SDL_RenderPresent(this->gRenderer);
    return 0;
}

int SDL2Renderer::paintBackgroundColor(int r, int g, int b) {
    // if (r < 0 || r > 255) return 1;
    // if (g < 0 || g > 255) return 2;
    // if (b < 0 || b > 255) return 3;
    
    // SDL_FillRect(
    //     this->screenSurface, 
    //     NULL, 
    //     SDL_MapRGB( 
    //         this->screenSurface->format, 
    //         r, 
    //         g, 
    //         b
    //     )
    // );

    return 0;
}

void SDL2Renderer::renderTitleScreen() {
    SDL_Rect srcQuad = {0, 0, 64, 64};
    SDL_Rect destQuad = {0, 0, 64, 64};
    for (size_t i = 0; i < this->SCREEN_WIDTH; i += 64) {
        for (size_t j = 0; j < this->SCREEN_HEIGHT; j += 64) {
            destQuad.x = i;
            destQuad.y = j;
            SDL_RenderCopy(this->gRenderer, this->textureManager->getTexture("main"), &srcQuad, &destQuad);
        }
    }

    SDL_Rect logoDest = {490, 50, 300, 150};
    SDL_RenderCopy(this->gRenderer, this->textureManager->getTexture("logo"), nullptr, &logoDest);
}

void SDL2Renderer::clearRenderer() {
    SDL_RenderClear(this->gRenderer);
}

SDL_Renderer* SDL2Renderer::getGPURenderer() {
    return this->gRenderer;
}


SDL2Renderer::~SDL2Renderer() {
    SDL_DestroyRenderer(this->gRenderer);
    SDL_DestroyWindow(this->window);
    IMG_Quit();
    SDL_Quit();
}