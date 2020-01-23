#include "main.h"

void printUI(int board[4][4]) {
    cout << "\n \x1b[36m" << "    /\\\\\\\\\\\\\\\\\\         /\\\\\\\\\\\\\\               /\\\\\\        /\\\\\\\\\\\\\\\\\\\n"
            "   /\\\\\\///////\\\\\\     /\\\\\\/////\\\\\\           /\\\\\\\\\\      /\\\\\\///////\\\\\\\n"
            "   \\///      \\//\\\\\\   /\\\\\\    \\//\\\\\\        /\\\\\\/\\\\\\     \\/\\\\\\     \\/\\\\\\\n"
            "              /\\\\\\/   \\/\\\\\\     \\/\\\\\\      /\\\\\\/\\/\\\\\\     \\///\\\\\\\\\\\\\\\\\\/\n"
            "            /\\\\\\//     \\/\\\\\\     \\/\\\\\\    /\\\\\\/  \\/\\\\\\      /\\\\\\///////\\\\\\\n"
            "          /\\\\\\//        \\/\\\\\\     \\/\\\\\\  /\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\  /\\\\\\      \\//\\\\\\\n"
            "         /\\\\\\/           \\//\\\\\\    /\\\\\\  \\///////////\\\\\\//  \\//\\\\\\      /\\\\\\\n"
            "         /\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\  \\///\\\\\\\\\\\\\\/             \\/\\\\\\     \\///\\\\\\\\\\\\\\\\\\/\n"
            "         \\///////////////     \\///////               \\///        \\/////////" << " \x1b[0m \n" << endl;

    cout << "                              ╔════╦════╦════╦════╗"<< endl;
    for (int i = 0; i < 4; i++) {
        cout << "                              ║";
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 0) cout.width(4);
            else if (board[i][j] < 10) cout.width(7);
            else if (board[i][j] < 100) cout.width(6);
            else if (board[i][j] < 1000) cout.width(6);
            else cout.width(5);
            switch (board[i][j]) {
                case 0:
                    cout << "";
                    break;
                case 2:
                    cout << "\x1b[32m" << board[i][j] << " \x1b[0m";
                    break;
                case 4:
                    cout << "\x1b[33m" << board[i][j] << " \x1b[0m";
                    break;
                case 8:
                    cout << "\x1b[31m" << board[i][j] << " \x1b[0m";
                    break;
                case 16:
                    cout << "\x1b[36m" << board[i][j] << " \x1b[0m";
                    break;
                case 32:
                    cout << "\x1b[35m" << board[i][j] << " \x1b[0m";
                    break;
                case 64:
                    cout << "\x1b[34m" << board[i][j] << " \x1b[0m";
                    break;
                case 128:
                    cout << "\x1b[32m" << board[i][j] << "\x1b[0m";
                    break;
                case 256:
                    cout << "\x1b[33m" << board[i][j] << "\x1b[0m";
                    break;
                case 512:
                    cout << "\x1b[31m" << board[i][j] << "\x1b[0m";
                    break;
                case 1024:
                    cout << "\x1b[36m" << board[i][j] << "\x1b[0m";
                    break;
                case 2048:
                    cout << "\x1b[35m" << board[i][j] << "\x1b[0m";
                    break;
            }
            cout << "║";
        }
        cout << "\n";
        if (i != 3) cout << "                              ╠════╬════╬════╬════╣" << endl;
    }
    cout << "                              ╚════╩════╩════╩════╝\n" << endl;
    cout << "                         Score: ";
    cout.width(4);
    cout << scoreCounter()<< "   Best Score: ";
    cout.width(4);
    if (scoreCounter() > getBestScore()) cout << scoreCounter() <<endl << endl;
    else cout << getBestScore() <<endl << endl;
    cout << "               n: new game, w: up, s: down, d: right, a: left, q: quit" << endl;
}