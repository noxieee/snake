//
// Created by vojta on 03.09.22.
//

#include "CEngine.h"

Engine::Engine() {
    mainMenuPtr = new MainMenu;
    gamePtr = new Game;
}

Engine::~Engine() {
    delete mainMenuPtr;
    delete gamePtr;
}

void Engine::run() {
    system("clear");

    while (!mainMenuPtr->isQuitSelected()) {
        mainMenuPtr->displayMenu();
        mainMenuPtr->takeUserInput();

        if (mainMenuPtr->isPlaySelected()) {
            gamePtr->run();
            gamePtr->reset();
            mainMenuPtr->resetPlayVariable();
        }
    }
}