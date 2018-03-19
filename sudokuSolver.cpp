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
bool checkRow(int board[][N*N], int row, int col, int value);
bool checkCol(int board[][N*N], int row, int col, int value);
bool checkSquare(int board[][N*N], int row, int col, int value);
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
    for (int row = 0; row < (N*N); row++){
        for (int col = 0; col < (N*N); col++){
            if (board[row][col] == EMPTY){
                for (value = 0; value < (N*N); value++){
                    board[row][col] = value;
                    if ((checkCol(board, row, col, value)) && (checkRow(board, row, col, value)) && (checkSquare(board, row, col, value))){
                            /* if (checkBoard(int board[][N*N], int row, int col, int value)){ */
                                printBoard(board);
                            /* } */
                    }
                }
            }
            else{
                continue;
            }
        }
    }
}

/* Check row is valid */
bool checkRow(int board[][N*N], int row, int col, int value){
    for (int i = 0; i < (N*N); i++){
        if ((i != row) && (board[i][col] == value))
                return false;
        return true;
    }
}

/* Check col is valid */
bool checkCol(int board[][N*N], int row, int col, int value){
    for (int i = 0; i < (N*N); i++){
        if ((i != col) && (board[row][i] == value))
            return false;
        return true;
    }
}

/* Check square is valid */
bool checkSquare(int board[][N*N], int row, int col, int value){
    int rowCorner = (row / N) * N;
    int colCorner = (col / N) * N;
    for (int i = rowCorner; i < (rowCorner + N); i++){
        for (int j = colCorner; j < (colCorner + N); j++){
            if (( i != row || j != col) && board[i][j] == value)
                return false;
        }
    }
    return true;
}

/* Check entire board */
/* bool checkBoard(int board[][N*N], int row, int col, int value){ */
/* } */

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
