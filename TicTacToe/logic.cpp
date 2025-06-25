#include "logic.h"
#include <iostream>
#include <fstream>
using namespace std;

char** createBoard() {
    char** board = new char* [3];
    char ch = '1';
    for (int i = 0; i < 3; ++i) {
        board[i] = new char[3];
        for (int j = 0; j < 3; ++j)
            board[i][j] = ch++;
    }
    return board;
}

void displayBoard(char** board) {
    cout << "\nCurrent board:\n";
    for (int i = 0; i < 3; ++i) {
        cout << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << endl;
}

char checkWin(char** board) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return board[i][0];
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return board[0][i];
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return board[0][2];
    return ' ';
}

bool isDraw(char** board) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] != 'X' && board[i][j] != 'O') return false;
    return true;
}

void computerMove(char** board) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                board[i][j] = 'O';
                return;
            }
}

void saveResult(const string& text) {
    ofstream fout("result.txt");
    if (fout.is_open()) {
        fout << text << "\n";
        fout.close();
    }
}

void deleteBoard(char** board) {
    for (int i = 0; i < 3; ++i)
        delete[] board[i];
    delete[] board;
}
