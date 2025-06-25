#include "logic.h"
#include "functions.h"
#include <iostream>
using namespace std;

int main() {
    cout << "=========================\n";
    cout << "\"Welcome to Tic Tac Toe!\"\n";
    cout << "=========================\n\n";

    int mode;
    cout << "Select mode:\n1 - vs Computer\n2 - 2 Players\n3 - Exit\nChoice: ";
    cin >> mode;

    if (mode == 3) {
        cout << "Goodbye!\n";
        return 0;
    }

    Player player1, player2;
    player1.mark = 'X';
    player2.mark = 'O';

    if (mode == 1) {
        player1.name = "You";
        player2.name = "Computer";
    }
    else if (mode == 2) {
        cout << "Enter name for Player 1: ";
        cin >> player1.name;
        cout << "Enter name for Player 2: ";
        cin >> player2.name;
    }
    else {
        cout << "Invalid choice.\n";
        return 0;
    }

    while (true) {
        char** board = createBoard();
        Player* current = &player1;
        bool gameOver = false;

        while (!gameOver) {
            displayBoard(board);
            if (mode == 1 && current == &player2)
                computerMove(board);
            else
                playerMove(current, board);

            char winner = checkWin(board);
            if (winner != ' ') {
                displayBoard(board);
                string winText;
                if (winner == player1.mark)
                    winText = player1.name + " wins!";
                else
                    winText = player2.name + " wins!";
                cout << winText << endl;
                saveResult(winText);
                gameOver = true;
            }
            else if (isDraw(board)) {
                displayBoard(board);
                cout << "It's a draw!\n";
                saveResult("Draw");
                gameOver = true;
            }

            current = (current == &player1) ? &player2 : &player1;
        }

        deleteBoard(board);

        char choice;
        cout << "Play again? (y/n): ";
        cin >> choice;
        if (choice != 'y' && choice != 'Y') break;
    }

    cout << "Thanks for playing!\n";
    return 0;
}
