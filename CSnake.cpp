//
// Created by vojta on 19.09.22.
//

#include "CSnake.h"

Snake::Snake() {
    snakeVect = SNAKE_START;
    direction = DIRECTION_NONE;
    crashed = false;
}

vector<pair<int,int>>& Snake::getSnakeRef() {
    return snakeVect;
}

void Snake::setDirection(const int &newDirection) {
    direction = newDirection;
}

void Snake::popTail() {
    snakeVect.pop_back();
}

void Snake::correctHeadCoords() {
    if (snakeVect.begin()->first > PLAYER_MAX_X) {
        snakeVect.begin()->first = PLAYER_MIN_X;
    }

    if (snakeVect.begin()->first < PLAYER_MIN_X) {
        snakeVect.begin()->first = PLAYER_MAX_X;
    }

    if (snakeVect.begin()->second > PLAYER_MAX_Y) {
        snakeVect.begin()->second = PLAYER_MIN_Y;
    }

    if (snakeVect.begin()->second < PLAYER_MIN_Y) {
        snakeVect.begin()->second = PLAYER_MAX_Y;
    }
}

void Snake::pushFrontNewHead() {
    pair<int,int> tmpHead = snakeVect[0];

    switch (direction) {
        case DIRECTION_UP:
            tmpHead.second = tmpHead.second - 1;
            break;
        case DIRECTION_DOWN:
            tmpHead.second = tmpHead.second + 1;
            break;
        case DIRECTION_LEFT:
            tmpHead.first = tmpHead.first - 1;
            break;
        case DIRECTION_RIGHT:
            tmpHead.first = tmpHead.first + 1;
        default:
            break;
    }

    snakeVect.insert(snakeVect.begin(), tmpHead);
}

void Snake::update() {
    checkSakeCollision();
    popTail();
    pushFrontNewHead();
    correctHeadCoords();
}

bool Snake::hasDirection() const {
    bool returnVal = false;

    if (direction) {
        returnVal = true;
    }

    return returnVal;
}

void Snake::checkSakeCollision() {
    for (unsigned long i = 1; i < snakeVect.size(); i++) {
        if (snakeVect[i] == snakeVect[0]) {
            crashed = true;
        }
    }
}

bool Snake::hasSnakeCrashed() const {
    return crashed;
}

