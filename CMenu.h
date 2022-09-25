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
    bool isQuitSelected() const;
    bool isPlaySelected() const;
    void resetPlayVariable();
    void takeUserInput();
private:
    string menuText;
    int menuChoice;
    bool quitSelected;
    bool playSelected;
    void processInput();
    static bool checkCin();
    static void displayHighscore(const string &fileName);
};

#endif //SNAKE_CMENU_H
