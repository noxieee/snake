//
// Created by vojta on 03.09.22.
//

#ifndef SNAKE_CGAME_H
#define SNAKE_CGAME_H

#include "CSnake.h"
#include <iostream>

using std::cout;
using std::endl;

#define PLAYGROUND_WIDTH 50
#define PLAYGROUND_HEIGHT 31
#define PLAYER_MIN_X 1
#define PLAYER_MAX_X (PLAYGROUND_WIDTH - 1)
#define PLAYER_MIN_Y 1
#define PLAYER_MAX_Y (PLAYGROUND_HEIGHT - 1)

class Game {
public:
    void initPlayground();
    void printPlayground();
private:
    Snake snakePlayer;
    vector<vector<char>> playground;
};

#endif //SNAKE_CGAME_H
