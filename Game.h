#pragma once 

#include <memory>
#include "graphics/SDL2Renderer.h"
#include "graphics/SDL2TextureManager.h"
#include "input/InputHandler.h"

enum GameStates {
    BOOTING,
    INITIALIZED,
    TITLE_SCREEN,
    LEVEL,
    SHUTTING_DOWN
};

class Game {
    public: 
        int init();
        int mainLoop();
        int shutdown();

        int handleTitleScreen();

        GameStates currentState = GameStates::BOOTING;

    private:    
        std::unique_ptr<SDL2Renderer> mainRenderer;
        std::unique_ptr<InputHandler> inputHandler;
        std::shared_ptr<SDL2TextureManager> textureManager;
        
        bool quitMainLoop = false;

        int r = 0x00;
        int g = 0x00;
        int b = 0x00;


};