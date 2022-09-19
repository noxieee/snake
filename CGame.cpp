//
// Created by vojta on 03.09.22.
//

#include "CGame.h"

void Game::init() {
    vector<pair<int,int>> snakeTmp = snakePlayer.getSnakeRef();
}

void Game::printPlayground() {
    for (const auto & y : playground) {
        for (const auto & x : y) {
            cout << x;
        }

        cout << endl;
    }
}