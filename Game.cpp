#include "Game.h"

int Game::init() {
    this->mainRenderer = std::make_unique<SDL2Renderer>();
    this->inputHandler = std::make_unique<InputHandler>();
    this->textureManager = std::make_unique<SDL2TextureManager>();
    this->mainRenderer->textureManager = this->textureManager;
    this->textureManager->gRenderer = this->mainRenderer->getGPURenderer();

    this->textureManager->loadTexture("main", "assets/textures.png");
    this->textureManager->loadTexture("logo", "assets/logo.png");

    this->currentState = GameStates::INITIALIZED;
    return 0;
}

int Game::mainLoop() {
    this->currentState = GameStates::INITIALIZED;
    if (this->currentState == GameStates::INITIALIZED) {
        //setup initial state and begin main loop
        this->currentState = GameStates::TITLE_SCREEN;
        while (!this->quitMainLoop) {
            switch (this->currentState) {
                case GameStates::TITLE_SCREEN:
                    this->handleTitleScreen();
                    break;
                
            default:
                break;
            }
            


        }
    }

    return 0;
}

int Game::handleTitleScreen() {
    int handled = false;

    while (!handled) {
        mainRenderer->clearRenderer();        
        mainRenderer->renderTitleScreen();
        mainRenderer->updateWindow();

        if (this->inputHandler->shouldGameClose()) {
            handled = true;
            this->quitMainLoop = true;
        }
    }

    return 0;
}

int Game::shutdown() {

    return 0;
}