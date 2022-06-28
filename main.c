#include <stdio.h>

#define BOARD_LENGTH 8;

int SIZE;
int solve(int board[SIZE], int column, int nQueens);
int LegalMove(int board[SIZE], int row, int column, int nQueens);
void printSolve(int board[SIZE], int nQueens);

int main(int argc, char** argv) {
    
    int length = BOARD_LENGTH;
    SIZE = length*length;
    int board[SIZE];
    for (int i=0; i<SIZE; i++ )
        board[i] = 0;

    if (solve(board, 0, length)) printSolve(board, length);
    else printf("No solution\n");

    return 0;
}

void printSolve(int board[SIZE], int nQueens) {
    for (int i=0; i<SIZE; i+=nQueens) {
        for (int j=0; j<nQueens; j++) {
            printf(" %d ", board[i+j]);
        }
        printf("\n");
    }
    fflush(stdout);
}

int LegalMove(int board[SIZE], int row, int column, int nQueens) {
    int i, j;
    for (i=0; i<column; i++) 
        if (board[row+i] == 1) return 0;
    
    for (i=row, j=column; i>=0 && j>=0; i-=nQueens, j--) 
        if (board[j+i] == 1) return 0;

    for (i=row, j=column; i<SIZE && j>=0; i+=nQueens, j--)
        if (board[j+i] == 1) return 0;

    return 1;
}

int solve(int board[SIZE], int column, int nQueens) {
    if (column >= nQueens) return 1;
    for (int i=0; i<SIZE; i+= nQueens) {
        if (LegalMove(board, i, column, nQueens)) {
            board[i+column] = 1;
            if (solve(board, column+1, nQueens)) return 1;
            board[i+column] = 0;
        }
    }
    return 0;
}


