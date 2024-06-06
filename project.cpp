#include <iostream>

const int SIZE = 3;
char board[SIZE][SIZE];

// Function to initialize the board with empty spaces
void initializeBoard() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            board[i][j] = ' ';
        }
    }
}

// Function to display the board
void displayBoard() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            std::cout << board[i][j];
            if (j < SIZE - 1) std::cout << " | ";
        }
        std::cout << std::endl;
        if (i < SIZE - 1) std::cout << "--+---+--" << std::endl;
    }
}

// Function to check if a move is valid
bool isValidMove(int row, int col) {
    return row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ';
}

// Function to check if there is a winner
bool checkWinner(char player) {
    // Check rows and columns
    for (int i = 0; i < SIZE; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check if the board is full (draw)
bool isBoardFull() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    initializeBoard();
    char currentPlayer = 'X';
    int row, col;
    
    while (true) {
        displayBoard();
        std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        std::cin >> row >> col;
        
        if (!isValidMove(row, col)) {
            std::cout << "Invalid move! Try again." << std::endl;
            continue;
        }
        
        board[row][col] = currentPlayer;
        
        if (checkWinner(currentPlayer)) {
            displayBoard();
            std::cout << "Player " << currentPlayer << " wins!" << std::endl;
            break;
        }
        
        if (isBoardFull()) {
            displayBoard();
            std::cout << "The game is a draw!" << std::endl;
            break;
        }
        
        // Switch player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    
    return 0;
}
