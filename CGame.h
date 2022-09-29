//
// Created by vojta on 03.09.22.
//

#ifndef SNAKE_CGAME_H
#define SNAKE_CGAME_H

#include "CSnake.h"
#include <iostream>
#include <unistd.h>

using std::cout;
using std::endl;

class Game {
public:
    Game();
    ~Game();
    void run();
    void reset();
private:
    void initPlayground();
    void printPlayground();
    void putSnakeInPlayground();
    void updatePlaygroundSnakeHead();
    void updatePlaygroundSnakeTail();
    bool gameEnded;
    int score;
    Snake * snakePlayer;
    vector<vector<char>> playground;
};

#endif //SNAKE_CGAME_H
