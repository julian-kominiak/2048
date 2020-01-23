#include "main.h"
#include <fstream>

int board[4][4];
// direction = {down, right, up, left}
int lineStepping[] = {1, 0, -1, 0};
int columnStepping[] = {0, 1, 0, -1};
bool firstTurn = true;
bool win = false;
int bestScore;

// random generator
random_device device{};
mt19937 generator(device());
uniform_int_distribution<int> board_distribution(0, 3);
uniform_int_distribution<int> piece_distribution(0, 1);

int scoreCounter() {
    int score{};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            score += board[i][j];
        }
    }
    return score - 2;
}

void refresh() {
    system("clear");
    printUI(board);
}

bool check2048() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 2048) {
                win = true;
            }
        }
    }
    if (win) {
        newHighScoreCheck();
        cout << "You win" << endl;
        cout << "Would You like to play again ? \n yes -> y \n no -> n";
        bool answer = false;
        char playAgain;
        while (!answer) {
            cin >> playAgain;
            cout << endl;
            if (playAgain == 'y') {
                answer = true;
                newGame();
                refresh();
            } else if (playAgain == 'n') {
                answer = true;
                return true;
            } else {
                cout << "Invalid character, please try again.";
            }
        }
    }
    int loss_counter{};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] != 0) {
                loss_counter++;
            }
        }
    }
    if (loss_counter == 16) {
        newHighScoreCheck();
        cout << "You lose" << endl;
        cout << "Would You like to play again ? \n yes -> y \n no -> n";
        bool answer = false;
        char playAgain;
        while (!answer) {
            cin >> playAgain;
            cout << endl;
            if (playAgain == 'y') {
                answer = true;
                newGame();
                refresh();
            } else if (playAgain == 'n') {
                answer = true;
                return true;
            } else {
                cout << "Invalid character, please try again.";
            }
        }
    }
    return false;
}

void newHighScoreCheck() {
    if (scoreCounter() > bestScore) {
        cout << "New High Score!" << endl;
        ofstream newBestScore;
        newBestScore.open("bestScore", std::ofstream::out | std::ofstream::trunc);
        newBestScore << scoreCounter();
        newBestScore.close();
    }
}

void bestScoreChecker() {
    ifstream best("bestScore");
    if (best.is_open()) {
        best >> bestScore;
    }
    best.close();
}

int getBestScore() {
    return bestScore;
}


void newGame() {
    bestScoreChecker();
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            board[i][j] = 0;
        }
    }
    firstTurn = true;
    addPiece();
}

void addPiece() {
    int line{}, column{};
    bool occupied = true;
    while (occupied) {
        line = board_distribution(generator);
        column = board_distribution(generator);
        if (board[line][column] == 0) {
            occupied = false;
            if (firstTurn == false) {
                if (piece_distribution(generator)) board[line][column] = 2;
                else board[line][column] = 4;
            } else board[line][column] = 2;
        }
    }
}

void applyMove(int direction) {
    int startLine{}, startColumn{};
    int lineStep = 1, columnStep = 1; //  and up
    if (direction == 0) { // down
        startLine = 3;
        lineStep = -1;
    }
    if (direction == 1) { // right
        startColumn = 3;
        columnStep = -1;
    }
    bool movePossible{}, canAddPiece{}, alreadyMoved[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            alreadyMoved[i][j] = false;
        }
    }
    do {
        movePossible = false;
        for (int i = startLine; i >= 0 && i < 4; i += lineStep) {
            for (int j = startColumn; j >= 0 && j < 4; j += columnStep) {
                int nextI = i + lineStepping[direction], nextJ = j + columnStepping[direction];
                if (board[i][j] != 0 && canDoMove(i, j, nextI, nextJ) &&
                    !alreadyMoved[nextI][nextJ] && !alreadyMoved[i][j]) {
                    if (board[nextI][nextJ] != 0) alreadyMoved[nextI][nextJ] = true;
                    board[nextI][nextJ] += board[i][j];
                    board[i][j] = 0;
                    movePossible = true;
                    canAddPiece = true;
                }
            }
        }
    } while (movePossible);
    if (canAddPiece) addPiece();
}

bool canDoMove(int line, int column, int nextLine, int nextColumn) {
    return !(nextLine < 0 || nextLine >= 4 || nextColumn < 0 || nextColumn >= 4
             || (board[line][column] != board[nextLine][nextColumn]
                 && board[nextLine][nextColumn] != 0));
}