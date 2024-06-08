#include <iostream>
using namespace std;

void displayGame(char gameGrid[3][3]) {
    cout << "-------------\n";
    for (int row = 0; row < 3; row++) {
        cout << "| ";
        for (int col = 0; col < 3; col++) {
            cout << gameGrid[row][col] << " | ";
        }
        cout << "\n-------------\n";
    }
}

bool isWinner(char gameGrid[3][3], char currentPlayer) {
    for (int index = 0; index < 3; index++) {
        if (gameGrid[index][0] == currentPlayer && gameGrid[index][1] == currentPlayer
            && gameGrid[index][2] == currentPlayer)
            return true;
        if (gameGrid[0][index] == currentPlayer && gameGrid[1][index] == currentPlayer
            && gameGrid[2][index] == currentPlayer)
            return true;
    }
    if (gameGrid[0][0] == currentPlayer && gameGrid[1][1] == currentPlayer
        && gameGrid[2][2] == currentPlayer)
        return true;
    if (gameGrid[0][2] == currentPlayer && gameGrid[1][1] == currentPlayer
        && gameGrid[2][0] == currentPlayer)
        return true;
    return false;
}

int main() {
    char gameGrid[3][3] = { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };
    char currentPlayer = 'X';
    int gridRow, gridCol;
    int gameTurn;
    cout << "Welcome to Tic-Tac-Toe Game!\n";
    for (gameTurn = 0; gameTurn < 9; gameTurn++) {
        displayGame(gameGrid);
        while (true) {
            cout << "Player " << currentPlayer << ", enter row (0-2) and column (0-2): ";
            cin >> gridRow >> gridCol;
            if (gameGrid[gridRow][gridCol] != ' ' || gridRow < 0 || gridRow > 2 || gridCol < 0 || gridCol > 2) {
                cout << "Invalid move. Try again.\n";
            }
            else {
                break;
            }
        }
        gameGrid[gridRow][gridCol] = currentPlayer;
        if (isWinner(gameGrid, currentPlayer)) {
            displayGame(gameGrid);
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    displayGame(gameGrid);
    if (gameTurn == 9 && !isWinner(gameGrid, 'X') && !isWinner(gameGrid, 'O')) {
        cout << "It's a draw!\n";
    }
    return 0;
}
