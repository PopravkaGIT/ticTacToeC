#include "functions.h"
#include <iostream>
using namespace std;

void playerMove(Player* player, char** board) {
    int move;
    while (true) {
        cout << player->name << " (" << player->mark << "), enter move (1-9): ";
        cin >> move;
        if (move < 1 || move > 9) {
            cout << "Invalid number. Try 1-9.\n";
            continue;
        }
        int r = (move - 1) / 3, c = (move - 1) % 3;
        if (board[r][c] != 'X' && board[r][c] != 'O') {
            board[r][c] = player->mark;
            break;
        }
        else {
            cout << "Cell taken. Try again.\n";
        }
    }
}
