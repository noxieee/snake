//
// Created by vojta on 19.09.22.
//

#ifndef SNAKE_CSNAKE_H
#define SNAKE_CSNAKE_H

#include <iostream>
#include <vector>

using std::vector;
using std::pair;

#define SNAKE_START vector<pair<int,int>> {{23,15},{24,15},{25,15},{26,15}}
#define DIRECTION_NONE 0
#define DIRECTION_UP 1
#define DIRECTION_DOWN 2
#define DIRECTION_LEFT 3
#define DIRECTION_RIGHT 4

#define PLAYGROUND_WIDTH 50
#define PLAYGROUND_HEIGHT 31
#define PLAYER_MIN_X 1
#define PLAYER_MAX_X (PLAYGROUND_WIDTH - 2)
#define PLAYER_MIN_Y 1
#define PLAYER_MAX_Y (PLAYGROUND_HEIGHT - 2)

class Snake {
public:
    Snake();
    vector<pair<int,int>>& getSnakeRef();
    void setDirection(const int& direction);
    void update();
    bool hasDirection() const;
    bool hasSnakeCrashed() const;

private:
    vector<pair<int,int>> snakeVect;
    void popTail();
    void pushFrontNewHead();
    void correctHeadCoords();
    void checkSakeCollision();
    int direction;
    bool crashed;
};

#endif //SNAKE_CSNAKE_H
