#include "sudoku.h"
using namespace std;

void changeNum(int grid[N][N],int x,int y);
void changeRow(int grid[N][N],int x,int y);
void changeCol(int grid[N][N],int x,int y);
void clockwise(int grid[N][N],int x);
void flip(int grid[N][N],int x);

int main(void) {
    int grid[N][N];
    int choice,x,y;
    input(grid);
    cin >> choice;
    while( choice !=0 ) {
        if (choice >3 )     cin >> x;
        else    cin >> x >> y;

        switch(choice) {
        case 1:
            changeNum(grid,x,y);
            break;
        case 2:
            changeRow(grid,x,y);
            break;
        case 3:
            changeCol(grid,x,y);
            break;
        case 4:
            clockwise(grid,x);
            break;
        case 5:
            flip(grid,x);
            break;
        default:
            cout << "no such choice:" << choice<< endl;
            break;
        }
        cin >> choice;
    }
    printsudoku(grid);
    return 0;
}

void changeNum(int grid[N][N],int x,int y) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            if( grid[i][j] == x ) {
                grid[i][j] = y;
                continue;
            }
            if( grid[i][j] == y ) {
                grid[i][j] = x;
                continue;
            }
        }
    return;
}

void swap(int* a,int* b) {
    int t=*a;
    *a=*b;
    *b=t;
    return;
}

void changeRow(int grid[N][N],int x,int y) {
    if(x==y)    return;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 9; j++)
            swap(&grid[i+3*x][j],&grid[i+3*y][j]);
    return;

}

void changeCol(int grid[N][N],int x,int y) {
    if(x==y)    return;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 3; j++)
            swap(&grid[i][j+3*x],&grid[i][j+3*y]);
    return;

}

void rotate( int matrix[][9]) {
    int length = N-1;
    for (int i = 0; i <= (length)/2; i++) {
        for (int j = i; j < length-i; j++) {

            //Coordinate 1
            int p1 = matrix[i][j];

            //Coordinate 2
            int p2 = matrix[j][length-i];

            //Coordinate 3
            int p3 = matrix[length-i][length-j];

            //Coordinate 4
            int p4 = matrix[length-j][i];

            //Swap values of 4 coordinates.
            matrix[j][length-i] = p1;
            matrix[length-i][length-j] = p2;
            matrix[length-j][i] = p3;
            matrix[i][j] = p4;
        }
    }
    /*
      head:i,j
      tail:len-i,len-j
      p1(i,j)             ->      p2(j,len-i)
          ^                            V
      p4(len-j,len-i)     c-      p3(len-i,len-j)

    */

    return ;
}

void clockwise(int grid[N][N],int x) { //順時針
    x=x%4;
    while(x>0) {
        //retate 90'c
        rotate(grid);
        x--;
    }
    return;

}


void flip(int grid[N][N],int x) {
    if(x==0) { //up-down flip
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < N; j++) {
                swap(&grid[i][j],&grid[8-i][j]);
            }
    } else { //left-right flip
        for (int i = 0; i < N; i++)
            for (int j = 0; j < 4; j++) {
                swap(&grid[i][j],&grid[i][8-j]);
            }
    }
    return;
}