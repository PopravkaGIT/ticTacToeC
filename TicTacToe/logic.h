#ifndef LOGIC_H
#define LOGIC_H

#include <string>
using namespace std;

struct Player {
    string name;
    char mark;
};

char** createBoard();
void displayBoard(char** board);
char checkWin(char** board);
bool isDraw(char** board);
void computerMove(char** board);
void saveResult(const string& text);
void deleteBoard(char** board);

#endif // LOGIC_H
