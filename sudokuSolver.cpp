#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

/* Constants defined */
const int N = 3;
const int EMPTY = 0;

/* Function declarations */
void inputBoard(int board[][N*N]);
void insertBoard(int board[][N*N], int row, int col, int value);
/* bool checkRow(int board[][N*N], int row, int col, int value); */
/* bool checkCol(int board[][N*N], int row, int col, int value); */
/* bool checkSquare(int board[][N*N], int row, int col, int value); */
/* bool checkBoard(int board[][N*N]); */
void printBoard(const int board[][N*N]);

/* Main function */
int main(){
    int board[N*N][N*N] = { { EMPTY } };
    inputBoard(board);

    printBoard(board);
    return 0;
}
/* Collect input of board */
void inputBoard(int board[][N*N]){
    /* This funtions variables */
    int value;

    /* Start of input of csv file named puzzle */
    cout << "This is Isaac's sudoku solver. This program will pull data from a csv file with the name of \'puzzle.csv\'. The file should be comma delimited with a new line seperating each new row (make sure each row still ends with a comma).\n\n";
    ifstream file("puzzle.csv");

    for (int i = 0; i < 9; i++){
        string line;
        getline(file,line);
        if ( !file.good() )
            break;

        stringstream iss(line);

        for (int j = 0; j < 9; j++){
            string val;
            getline(iss, val, ',');
            if ( !iss.good() )
                break;
            stringstream convertor(val);
            convertor >> board[i][j];
        }
    }
}

/* Insert value into board */
void insertBoard(int board[][N*N], int row, int col, int value){
}

/* Check row is valid */
bool checkRow(int board[][N*N], int row, int col, int value){
}

/* Check col is valid */
bool checkCol(int board[][N*N], int row, int col, int value){
}

/* Check square is valid */
bool checkSquare(int board[][N*N], int row, int col, int value){
}

/* Check entire board */
bool checkBoard(int board[][N*N], int row, int col, int value){
}

/* Print solved board */
void printBoard(const int board[][N*N]){
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}
