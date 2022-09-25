//
// Created by vojta on 19.09.22.
//

#include "CSnake.h"

Snake::Snake() {
    snake = SNAKE_START;
    direction = DIRECTION_NONE;
}

vector<pair<int,int>>& Snake::getSnakeRef() {
    return snake;
}

