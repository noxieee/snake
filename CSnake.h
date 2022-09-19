//
// Created by vojta on 19.09.22.
//

#ifndef SNAKE_CSNAKE_H
#define SNAKE_CSNAKE_H

#include <iostream>
#include <vector>

using std::vector;
using std::pair;

#define SNAKE_START vector<pair<int,int>> {{18,12},{19,12},{20,12},{21,12}}

class Snake {
public:
    Snake();
    vector<pair<int,int>> & getSnakeRef();
private:
    vector<pair<int,int>> snake;
};

#endif //SNAKE_CSNAKE_H
