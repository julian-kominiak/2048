#include "main.h"
#include <stdio.h>

int main() {
    char commandToDir[128];
    commandToDir['B'] = 0;
    commandToDir['C'] = 1;
    commandToDir['A'] = 2;
    commandToDir['D'] = 3;
    newGame();
    while (true) {
        refresh();
        if (check2048()) break;
        string command;
        //getline(cin, command);
        system("stty raw");
        command = getchar();
        system("stty cooked");
        while (command.length() != 1) {
            refresh();
            cout << "Please enter only one letter at a time." << endl;
            getline(cin, command);
        }
        if (command[0] == 'n') {
            newHighScoreCheck();
            newGame();
        }
        else if (command[0] == 'q') {
            newHighScoreCheck();
            break;
        }
        else if (command == "s"){
            applyMove(0);
        }
        else if (command == "d"){
            applyMove(1);
        }
        else if (command == "w"){
            applyMove(2);
        }
        else if (command == "a"){
            applyMove(3);
        }
    }
    return 0;
}
