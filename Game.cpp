#include "Game.h"

int Game::init() {
    this->mainRenderer = std::make_unique<SDL2Renderer>();
    this->inputHandler = std::make_unique<InputHandler>();
    this->textureManager = std::make_unique<SDL2TextureManager>();
    this->mainRenderer->textureManager = this->textureManager;
    this->textureManager->gRenderer = this->mainRenderer->getGPURenderer();

    // this->textureManager->loadTexture("main", "assets/textures.png");
    this->textureManager->loadTexture("logo", "assets/logo.png");
    this->textureManager->loadTexture("title-screen", "assets/title-screen.png");

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
        this->renderTitleScreen();
        mainRenderer->updateWindow();

        if (this->inputHandler->shouldGameClose() || this->shouldGameClose) {
            handled = true;
            this->quitMainLoop = true;
        }
    }

    return 0;
}


void Game::renderTitleScreen() {
    //rendering background tiles
    SDL_Rect srcQuad = {0, 0, 64, 64};
    SDL_Rect destQuad = {0, 0, 64, 64};
    for (size_t i = 0; i < this->mainRenderer->SCREEN_WIDTH; i += 64) {
        for (size_t j = 0; j < this->mainRenderer->SCREEN_HEIGHT; j += 64) {
            destQuad.x = i;
            destQuad.y = j;
            SDL_RenderCopy(this->mainRenderer->gRenderer, this->textureManager->getTexture("title-screen"), &srcQuad, &destQuad);
        }
    }

    //rendering logo
    SDL_Rect logoDest = {490, 50, 300, 150};
    SDL_RenderCopy(this->mainRenderer->gRenderer, this->textureManager->getTexture("logo"), nullptr, &logoDest);

    //render menu bg
    int menuWidth = 4 * 64 + 32;
    int menuX = (this->mainRenderer->SCREEN_WIDTH / 2) - (menuWidth / 2);
    int menuHeight = 3 * 64; 
    int menuY = (this->mainRenderer->SCREEN_HEIGHT / 2) - (menuHeight / 2);
    srcQuad = {64, 0, 64, 64};
    destQuad = {menuX, menuY, menuWidth, menuHeight};
    SDL_RenderCopy(this->mainRenderer->gRenderer, this->textureManager->getTexture("title-screen"), &srcQuad, &destQuad);

    //render border
    int borderSize = 6;
    srcQuad = {128, 0, borderSize, borderSize + 3};
    destQuad = {menuX, menuY, borderSize, borderSize + 3};
    for (size_t i = menuX; i < menuWidth + menuX; i += borderSize) {
        destQuad.x = i;
        destQuad.y = menuY;
        SDL_RenderCopy(this->mainRenderer->gRenderer, this->textureManager->getTexture("title-screen"), &srcQuad, &destQuad);
        destQuad.y = menuY + menuHeight - borderSize;
        SDL_RenderCopy(this->mainRenderer->gRenderer, this->textureManager->getTexture("title-screen"), &srcQuad, &destQuad);
    }
    destQuad.x = menuX;
    for (size_t i = menuY; i < menuHeight + menuY; i += borderSize) {
        destQuad.x = menuX;
        destQuad.y = i;
        SDL_RenderCopy(this->mainRenderer->gRenderer, this->textureManager->getTexture("title-screen"), &srcQuad, &destQuad);
        destQuad.x = menuX + menuWidth - borderSize;
        SDL_RenderCopy(this->mainRenderer->gRenderer, this->textureManager->getTexture("title-screen"), &srcQuad, &destQuad);
    }

    //render options
    std::vector<std::string> menuOptions = {"NEW_GAME", "LEVEL_SELECT", "QUIT"};
    srcQuad = {0, 64, 3 * 64, 64 / 2};
    destQuad = {menuX + 64 / 2, menuY + 32, 3 * 64, 64 / 2};
    for (size_t i = 0; i < menuOptions.size(); i++)
    {   
        srcQuad.y = i * 32 + 64;
        destQuad.y = menuY + 32 + i * 32;
        SDL_RenderCopy(this->mainRenderer->gRenderer, this->textureManager->getTexture("title-screen"), &srcQuad, &destQuad);
    }

    //render option marker
    int markerSize = 16;
    srcQuad = {64 * 3 - markerSize, 0, markerSize, markerSize};\
    //{gap for marker, start of menu + offset by option + vertical center}
    destQuad = {menuX + markerSize, menuY + 32 + selectedMenuOption * 32 + 12, markerSize / 2, markerSize / 2};
    SDL_RenderCopy(this->mainRenderer->gRenderer, this->textureManager->getTexture("title-screen"), &srcQuad, &destQuad);
    
    //handle input
    switch (this->inputHandler->getCurrentKey())
    {
        case SDLK_DOWN:
            this->selectedMenuOption = fmin(this->selectedMenuOption + 1, menuOptions.size() - 1);
            break;
    
        case SDLK_UP:
            this->selectedMenuOption = fmax(this->selectedMenuOption - 1, 0);
            break;
        
        case SDLK_RETURN: {
            if (this->selectedMenuOption == 2) {
                this->shouldGameClose = true;
            }
            break;
        }
    }

    // std::cout << "Selected menu index: " << this->selectedMenuOption << std::endl;
}

int Game::shutdown() {

    return 0;
}