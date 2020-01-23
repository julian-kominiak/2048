#ifndef INC_2048_MAIN_H
#define INC_2048_MAIN_H
#include <iostream>
#include <random>

using namespace std;

void addPiece();
void newGame();
void printUI(int board[4][4]);
bool canDoMove(int line, int column, int nextLine, int nextColumn);
void applyMove(int direction);
void refresh();
bool check2048();
int scoreCounter();
void newHighScoreCheck();
void bestScoreChecker();
int getBestScore();
#endif //INC_2048_MAIN_H
