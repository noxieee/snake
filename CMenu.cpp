//
// Created by vojta on 02.09.22.
//

#include "CMenu.h"

MainMenu::MainMenu() {
    menuText = "\nMain menu - select:\n1 - Play\n2 - View highscore\n3 - Quit.\n";
    quitSelected = false;
    playSelected = false;
}

void MainMenu::displayMenu() const {
    cout << menuText;
}

bool MainMenu::isQuitSelected() const {
    if (quitSelected) {
        return true;
    }
    return false;
}

bool MainMenu::isPlaySelected() const {
    if (playSelected) {
        return true;
    }
    return false;
}

void MainMenu::displayHighscore(const string &fileName) {
    ifstream inFile(fileName);
    string line;

    if (!inFile) {
        cout << "\n!!!Error reading file!!!\n" << endl;
    }
    else {
        getline(inFile, line);
        cout << "\nHighscore is: " << line << endl;
    }
}

void MainMenu::processInput(const int &userInput) {
    switch (userInput) {
        case 1:
            playSelected = true;
            cout << "\nPlaying..." << endl;
            break;
        case 2:
            displayHighscore(HIGHSCORE_FILENAME);
            break;
        case 3:
            quitSelected = true;
            break;
        default:
            cout << "\nInvalid input." << endl;
            break;
    }
}

void MainMenu::resetVariables() {
    playSelected = false;
    quitSelected = false;
}