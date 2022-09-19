//
// Created by vojta on 03.09.22.
//

#ifndef SNAKE_CENGINE_H
#define SNAKE_CENGINE_H

#include "CMenu.h"
#include "CGame.h"

class Engine {
public:
    Engine();
    ~Engine();
    void run();
private:
    MainMenu * mainMenuPtr;
    static void clearTerminal();
    static bool checkCin();
    int menuChoice;
    Game game;
};

#endif //SNAKE_CENGINE_H
