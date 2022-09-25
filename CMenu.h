//
// Created by vojta on 02.09.22.
//

#ifndef SNAKE_CMENU_H
#define SNAKE_CMENU_H

#include <string>
#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;

#define HIGHSCORE_FILENAME "highscore"

class MainMenu {
public:
    MainMenu();
    void displayMenu() const;
    void processInput(const int &userInput);
    bool isQuitSelected() const;
    bool isPlaySelected() const;
    void resetPlayVariable();
private:
    string menuText;
    bool quitSelected;
    bool playSelected;
    static void displayHighscore(const string &fileName);
};

#endif //SNAKE_CMENU_H
