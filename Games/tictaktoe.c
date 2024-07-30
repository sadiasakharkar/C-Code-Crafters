#include <stdio.h>

// Function to print the Tic Tac Toe board
void printBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i != 2) printf("\n---|---|---\n");
    }
    printf("\n");
}

// Function to check if someone has won
int checkWin(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return 1;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return 1;
    return 0;
}

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int row, col, currentPlayer = 1;
    
    printf("Welcome to Tic Tac Toe!\n");
    
    while (1) {
        // Print the board
        printBoard(board);
        
        // Take input from the current player
        printf("Player %d's turn. Enter row and column numbers (1-3): ", currentPlayer);
        scanf("%d %d", &row, &col);
        
        // Convert input to array indices
        row--; col--;
        
        // Check if the chosen cell is empty
        if (board[row][col] != ' ') {
            printf("This cell is already occupied. Try again.\n");
            continue;
        }
        
        // Place player's symbol in the chosen cell
        if (currentPlayer == 1)
            board[row][col] = 'X';
        else
            board[row][col] = 'O';
        
        // Check for a win
        if (checkWin(board)) {
            printf("Congratulations! Player %d wins!\n", currentPlayer);
            printBoard(board);
            break;
        }
        
        // Check for a draw
        int isDraw = 1;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    isDraw = 0;
                    break;
                }
            }
            if (!isDraw) break;
        }
        if (isDraw) {
            printf("It's a draw!\n");
            printBoard(board);
            break;
        }
        
        // Switch players
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }
    
    return 0;
}
