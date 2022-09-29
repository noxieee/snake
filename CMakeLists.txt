cmake_minimum_required(VERSION 3.21)
project(snake)

set(CMAKE_CXX_STANDARD 14)

add_executable(snake
        main.cpp CMenu.h CMenu.cpp CEngine.h CEngine.cpp CGame.h CGame.cpp CSnake.h CSnake.cpp CSfmlEngine.h CSfmlEngine.cpp)
