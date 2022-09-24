//
// Created by vojta on 03.09.22.
//

#include "CGame.h"

Game::Game() {
    gameEnded = false;
}

void Game::initPlayground() {
    for (int y = 0; y < PLAYGROUND_HEIGHT; y++) {
        vector<char> tmp;

        for (int x = 0; x < PLAYGROUND_WIDTH; x++) {
            if (y == 0 || y == PLAYGROUND_HEIGHT - 1) {
                tmp.push_back('-');
            }
            else if (x == 0 || x == PLAYGROUND_WIDTH - 1) {
                tmp.push_back('|');
            }
            else {
                tmp.push_back(' ');
            }
        }

        playground.push_back(tmp);
    }
}

void Game::printPlayground() {
    for (const auto & y : playground) {
        for (const auto & x : y) {
            cout << x;
        }

        cout << endl;
    }
}

void Game::putSnakeInPlayground() {
    vector<pair<int,int>> tmp = snakePlayer.getSnakeRef();

    for (const auto & coords: tmp) {
        playground[coords.second][coords.first] = 'S';
    }
}

void Game::run() {
    initPlayground();
    putSnakeInPlayground();


    while (!gameEnded) {
        printPlayground();
        // Update game - update snake, check for collision, update snake head in playground, remove tail piece
    }
}

void Game::reset() {
    playground.clear();
    gameEnded = false;
}