#include "sudoku.h"
using namespace std;

bool inverseSolveSudoku(int grid[N][N]) {
    int row, col;

    // If there is no unassigned location,
    // we are done
    if (!FindUnassignedLocation(grid, row, col))
        return true; // success!

    // consider digits 1 to 9
    for (int num = 9; num >= 1; num--) {
        // if looks promising
        if (isSafe(grid, row, col, num)) {
            // make tentative assignment
            grid[row][col] = num;

            // return, if success, yay!
            if (inverseSolveSudoku(grid))
                return true;

            // failure, unmake & try again
            grid[row][col] = UNASSIGNED;
        }
    }
    return false; // this triggers backtracking
}

bool compare(int A[N][N], int B[N][N]) {
    for (int row = 0; row < N; row++)
        for (int col = 0; col < N; col++)
            if( A[row][col] != B[row][col] )
                return false;//differ
    return true;//same
}

int main() {
    // 0 means unassigned cells
    int grid[N][N],grid_compare[N][N]  ;

    input(grid);
    copy(grid,grid_compare);
    inverseSolveSudoku(grid_compare);

    if (SolveSudoku(grid) == true) {
        if(compare(grid,grid_compare)) {
            cout <<"1" <<endl;//unique solution
            printsudoku(grid);
        } else
            cout <<"2" <<endl;// multiple solution
    } else
        cout <<"0"<<endl;  //no solution




    return 0;
}


