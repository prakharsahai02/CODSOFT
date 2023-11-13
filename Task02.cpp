#include <iostream>
using namespace std;

char grid[3][3]; 

void initialize_Grid() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            grid[i][j] = ' ';
        }
    }
}

void print_Grid() {
    cout << "  0    1   2" << endl;
    for(int i = 0; i < 3; i++) {
        cout << i << " ";
        for(int j = 0; j < 3; j++) {
            cout << grid[i][j];
            if(j < 2) cout << "  |";
        }
        cout << endl;
        if(i < 2) cout << "  -----------" << endl;
    }
}

bool makeMove(int row, int col, char player) {
    if(row >= 0 && row < 3 && col >= 0 && col < 3 && grid[row][col] == ' ') {
        grid[row][col] = player;
        return true;
    } else {
        return false;
    }
}

bool checkWin(char player) {
     for(int i = 0; i < 3; i++) {
        if(grid[0][i] == player && grid[1][i] == player && grid[2][i] == player)
            return true;
    }
    for(int i = 0; i < 3; i++) {
        if(grid[i][0] == player && grid[i][1] == player && grid[i][2] == player)
            return true;
    }
    if(grid[0][0] == player && grid[1][1] == player && grid[2][2] == player)
        return true;
    if(grid[0][2] == player && grid[1][1] == player && grid[2][0] == player)
        return true;
    return false;
}

bool isBoardFull() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(grid[i][j] == ' ')
                return false;
        }
    }
    return true;
}

int main() {
    initialize_Grid();
    char currentPlayer = 'X';

    while(true) {
        print_Grid();
        int row, col;
        cout << "Player " << currentPlayer << ", enter row (0-2) and column (0-2) separated by space (e.g. '1 1'): ";
        cin >> row >> col;

        if(makeMove(row, col, currentPlayer)) {
            if(checkWin(currentPlayer)) {
                print_Grid();
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            } else if(isBoardFull()) {
                print_Grid();
                cout << "It's a draw!" << endl;
                break;
            } else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        } else {
            cout << " Try again." << endl;
        }
    }

    return 0;
}