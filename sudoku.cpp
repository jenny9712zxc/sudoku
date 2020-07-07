#include "sudoku.h"

void printsudoku(int sudoku[9][9]) {

    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cout<<sudoku[i][j];

            if(j==8)cout<<endl;
            else  cout<<" ";
        }
    }
    return;
}

bool SolveSudoku(int grid[N][N]) {
    int row, col;

    // If there is no unassigned location,
    // we are done
    if (!FindUnassignedLocation(grid, row, col))
        return true; // success!

    // consider digits 1 to 9
    for (int num = 1; num <= 9; num++) {
        // if looks promising
        if (isSafe(grid, row, col, num)) {
            // make tentative assignment
            grid[row][col] = num;

            // return, if success, yay!
            if (SolveSudoku(grid))
                return true;

            // failure, unmake & try again
            grid[row][col] = UNASSIGNED;
        }
    }
    return false; // this triggers backtracking
}

//find empty cell1
bool FindUnassignedLocation(int grid[N][N],int &row, int &col) {
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == UNASSIGNED)
                return true;
    return false;
}

bool UsedInRow(int grid[N][N], int row, int num) {
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}

bool UsedInCol(int grid[N][N], int col, int num) {
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}

bool UsedInBox(int grid[N][N], int boxStartRow,int boxStartCol, int num) {
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row + boxStartRow]
                    [col + boxStartCol] == num)
                return true;
    return false;
}


bool isSafe(int grid[N][N], int row,int col, int num) { //only check
    /* Check if 'num' is not already placed in
    current row, current column and current 3x3 box */
    return !UsedInRow(grid, row, num) &&
           !UsedInCol(grid, col, num) &&
           !UsedInBox(grid, row - row % 3,
                      col - col % 3, num) &&
           grid[row][col] == UNASSIGNED;
}

void copy(int A[N][N],int B[N][N]) {
    for (int row = 0; row < N; row++)
        for (int col = 0; col < N; col++)
            B[row][col]=A[row][col];
    return;
}

void input(int sudoku[9][9]) {

    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
            cin>>sudoku[i][j];

    return;
}