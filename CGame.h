//
// Created by vojta on 03.09.22.
//

#ifndef SNAKE_CGAME_H
#define SNAKE_CGAME_H

#include "CSnake.h"
#include <iostream>

using std::cout;
using std::endl;

#define PLAYGROUND_MAX_X 39
#define PLAYGROUND_MAX_Y 24

class Game {
public:
    void init();
    void printPlayground();
private:
    Snake snakePlayer;
    vector<vector<char>> playground;
};

#endif //SNAKE_CGAME_H
