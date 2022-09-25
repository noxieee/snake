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

class Snake {
public:
    Snake();
    vector<pair<int,int>>& getSnakeRef();
private:
    vector<pair<int,int>> snake;
    int direction;
};

#endif //SNAKE_CSNAKE_H
