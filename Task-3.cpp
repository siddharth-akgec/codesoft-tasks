
#include <iostream>
using namespace std;

char board[3][3];  // Game board
char currentPlayer;  // Current player: 'X' or 'O'

// Function to reset board
void resetBoard() {
    char pos = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = pos++;
        }
    }
}

// Function to display board
void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

// Function to switch player
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Function to check win
bool checkWin() {
    // Check rows & columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) || 
            (board[0][i] == board[1][i] && board[1][i] == board[2][i]))
            return true;
    }
    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
        return true;

    return false;
}

// Function to check draw
bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }
    return true;
}

// Function to update board
bool updateBoard(int move) {
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentPlayer;
        return true;
    }
    return false;
}

// Main game function
void playGame() {
    int move;
    resetBoard();
    currentPlayer = 'X';

    while (true) {
        displayBoard();
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        if (move < 1 || move > 9) {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        if (!updateBoard(move)) {
            cout << "Cell already taken! Try again.\n";
            continue;
        }

        if (checkWin()) {
            displayBoard();
            cout << "Player " << currentPlayer << " wins! 🎉\n";
            break;
        }

        if (checkDraw()) {
            displayBoard();
            cout << "It's a draw! 🤝\n";
            break;
        }

        switchPlayer();
    }
}

int main() {
    char choice;
    do {
        playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "Thanks for playing Tic-Tac-Toe! 👋\n";
    return 0;
}
