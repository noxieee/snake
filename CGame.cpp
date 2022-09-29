//
// Created by vojta on 03.09.22.
//

#include "CGame.h"

Game::Game() {
    gameEnded = false;
    snakePlayer = new Snake;
    score = 0;
}

Game::~Game() {
    delete snakePlayer;
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

void Game::run() {
    initPlayground();
    putSnakeInPlayground();

    for (int i = 3; i > 0; i--) {
        system("clear");
        cout << "Starting in: " << i << endl;
        printPlayground();
        sleep(1);
    }

    snakePlayer->setDirection(DIRECTION_LEFT);

    system("clear");

    while (!gameEnded) {
        cout << "Score: " << score << endl;
        printPlayground();
        updatePlaygroundSnakeTail();
        snakePlayer->update();
        updatePlaygroundSnakeHead();

        if (snakePlayer->hasSnakeCrashed()) {
            gameEnded = true;
            cout << "Snake crashed" << endl;
        }

        usleep(150000);
        system("clear");
    }
}

void Game::reset() {
    playground.clear();
    gameEnded = false;
    delete snakePlayer;
    snakePlayer = new Snake;
}

void Game::putSnakeInPlayground() {
    vector<pair<int,int>> tmpSnakeVect = snakePlayer->getSnakeRef();

    for (const auto& coords: tmpSnakeVect) {
        playground[coords.second][coords.first] = 'S';
    }
}

void Game::updatePlaygroundSnakeHead() {
    if (snakePlayer->hasDirection()) {
        vector<pair<int,int>> tmpSnakeVect = snakePlayer->getSnakeRef();
        playground[tmpSnakeVect[0].second][tmpSnakeVect[0].first] = 'S';
    }
}

void Game::updatePlaygroundSnakeTail() {
    if (snakePlayer->hasDirection()) {
        vector<pair<int,int>> tmpSnakeVect = snakePlayer->getSnakeRef();
        playground[tmpSnakeVect.back().second][tmpSnakeVect.back().first] = ' ';
    }
}