#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>


// UNASSIGNED is used for empty cells in sudoku grid
#define UNASSIGNED 0

// N is used for the size of Sudoku grid.
#define N 9

using namespace std;



//var
//static int Sudoku[N][N];


//func-----------
bool SolveSudoku(int grid[N][N]) ;

void copy(int A[N][N],int B[N][N]);//copy A to B

void printsudoku(int sudoku[9][9]);

// This function finds an entry in grid that is still unassigned
bool FindUnassignedLocation(int grid[N][N],int &row, int &col);

// Checks whether it will be legal
bool isSafe(int grid[N][N], int row,int col, int num);

void input(int sudoku[9][9]);