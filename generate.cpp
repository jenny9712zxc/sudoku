#include "sudoku.h"

void output(int sudoku[9][9]) {
    fstream  file ;
    file.open("gen.txt",ios::out) ;
    if(!file) {   //檢查檔案是否成功開啟
        cerr << "Can't open file!\n";
        exit(1);
    }

    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++) {
            file<<sudoku[i][j];

            if(j==8)    file<<endl;
            else  file<<" ";
        }
    file.close();
    return;
}


bool is_safe(int i,int j,int val,int grid[9][9]) { //check and fill
    int r,c;

    //col
    //cout<<"(i,j,val,grid(i,j))="<<i<<j<<val<<grid[i][j]<<endl;
    for(r=0; r<9; r++) {
        if(grid[i][j]!=0) return false;
        if( (grid[r][j]==val) && r!=i ) {
            //cout<<"col--"<<i<<j<<val<<grid[i][j]<<endl;
            return false;
        }
    }

    //row
    for(c=0; c<9; c++) {
        if(grid[i][j]!=0) return false;
        if( (grid[i][c]==val) && c!=j ) {
            //cout<<"row--"<<i<<j<<val<<grid[i][j]<<endl;
            return false;
        }
    }

    //box
    if(i%3==0)  r=0;
    else if(i%3==1)  r=3;
    else    r=6;
    if(j%3==0)  c=0;
    else if(i%3==1)  c=3;
    else    c=6;
    for(int a=r; a<r+3; a++)
        for(int b=c; b<r+3; b++) {
            if(i==a && j==b)    continue;
            if(grid[i][j]==grid[a][b] && (grid[i][j]!=0)   ) {
                //cout<<"box--"<<a<<b<<val<<grid[a][b]<<endl;
                return false;
            }
        }
    grid[i][j]=val;
    return true;
}

void generate_puzzle(int sudoku[9][9]) {
    int i,j,t;
    //initialize
    for(i=0; i<9; i++)
        for(j=0; j<9; j++)
            sudoku[i][j]=0;


    for(i=0; i<N; i++) {
        srand( time(NULL) );
        j=rand()%9;
        //sudoku[i][j]=rand()%9;

        while(is_safe(i,j,rand()%9+1,sudoku)) j=rand()%9;
        //cout<<"generate_puzzle()___i="<<i<<endl;
    }
    return;
}

void remove_cell(int sudoku[9][9]) {
    int i,j,t;
    for(i=0; i<N; i++) {
        t= rand()%6+3;
        //cout<<t<<endl;
        while(t>0) {
            j=rand()%9;
            sudoku[i][j]=0;
            t--;
        }
    }
    return;
}

int main() {
    int puzzle[N][N];
    //input(puzzle);
    generate_puzzle(puzzle);
    //cout<<"generate"<<endl;
    //printsudoku(puzzle);

    //cout<<"SolveSudoku"<<endl;
    SolveSudoku(puzzle);
    /*
    if (SolveSudoku(puzzle) == true)
        printsudoku(puzzle);
    else
    {
        cout<<"fail"<<endl;
        return 0;
    }*/
    remove_cell(puzzle);
    //cout<<"remove_cell"<<endl;
    printsudoku(puzzle);
    /*
    output(puzzle);
     if (SolveSudoku(puzzle) == true)
        cout<<"ok"<<endl;
    */

    return 0;
}