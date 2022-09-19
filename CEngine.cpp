//
// Created by vojta on 03.09.22.
//

#include "CEngine.h"

Engine::Engine() {
    mainMenuPtr = new MainMenu;
    menuChoice = 0;
}

Engine::~Engine() {
    delete mainMenuPtr;
}

void Engine::clearTerminal() {
    if (system("clear")) {
        cout << "!!!Failed to clear terminal!!!" << endl;
    }
}

bool Engine::checkCin() {
    if (!cin) {
        cout << "\nInvalid input." << endl;
        cin.clear();
        cin.ignore();

        return false;
    }

    return true;
}

void Engine::run() {
    clearTerminal();

    while (!mainMenuPtr->isQuitSelected()) {
        mainMenuPtr->displayMenu();
        cin >> menuChoice;

        clearTerminal();

        if (checkCin()) {
            mainMenuPtr->processInput(menuChoice);
        }

        if (mainMenuPtr->isPlaySelected()) {
            game.init();
            game.printPlayground();
        }
    }
}