/**********************************
 * Name: Gabriel Elbling
 * Email: gelbling@nd.edu
 * File Name: sudoku.cpp
 * Date Created: 03/03/2022
 * File Contents: This file contains functions
 **********************************/

#include "../include/sudoku.h"


// populate puzzle board with inputted gameboard
void populate_puzzle( IFSTREAM& sudoku_infile, VECTOR< VECTOR<int> >& sudoku ){

    int temp_int;
    
    for (int i=0; i<ROWS; i++){
        for (int ii=0; ii<COLS; ii++){
            //reads from file
            sudoku_infile >> temp_int;
            //inserts values into 2D vector
            sudoku[i][ii] = temp_int;
        }
    }
    
}

// print greeting message
void print_greeting( void ){
    COUT << "Welcome to our Sudoku Game!" << ENDL;
}

// update puzzle board with desired value
void update_puzzle( VECTOR< VECTOR<int> >& sudoku, int value, long unsigned int row,  long unsigned int col ){
    sudoku[row][col] = value;
}

// checks the puzzle and returns false if a zero is found, else return true
bool check_puzzle( const VECTOR< VECTOR<int> >& sudoku ){
    for (int i=0; i<ROWS; i++){
        for (int ii=0; ii<COLS; ii++){
            if(sudoku[i][ii] == 0){
                return false;
            }
        }
    }
    return true;
}


// check if the guess is valid, return true if so and false otherwise
bool check_guess( const VECTOR< VECTOR<int> >& sudoku, int value, long unsigned int row, long unsigned int col ){

    // CHECK IF THERE IS A VALUE AT LOCATION
    if (sudoku[row][col] != 0){
        return false;
    }

    // check if value exists in row
    for (int i=0; i<ROWS; i++){
        if(i == int(row)){
            continue;
        }
        else{
            if(sudoku[i][col] == value){
                return false;
            }
        }
    }

    // check if value exists in col
    for (int i=0; i<COLS; i++){
        if(i == int(col)){
            continue;
        }
        else{
            if(sudoku[row][i] == value){
                return false;
            }
        }
    }

    // get top left starting point of 3x3 quare
    int rowStart = 3 * (int(row) / 3);
    int colStart = 3 * (int(col) / 3);

    // check if value is in square
    for (int i = rowStart; i<(rowStart+3); i++){
        for (int ii = colStart; ii<(colStart + 3); ii++){
            if (sudoku[i][ii] == value){
                return false;
            }
        }
    }

    return true;
}


// print puzzle board
void print_puzzle( const VECTOR< VECTOR<int> >& sudoku ){
    for (int i=0; i<ROWS; i++){
        for (int ii=0; ii<COLS; ii++){
            // print each value with space
            COUT << sudoku[i][ii] << " ";
        }
        // print new line
        COUT << "" << ENDL;
    }
}

// recursive solver of the sudoku puzzle
bool recursive_solver( VECTOR< VECTOR<int> >& sudoku, long unsigned int row, long unsigned int col ){

    for (int i=0; i<ROWS; i++){
        for(int ii=0; ii<COLS; ii++){
            // find zero location
            if (sudoku[i][ii] == 0){
                row = i;
                col = ii;
                
                bool check_input;

                // test sentinel and execute recursive call
                for (int sentinel = 1; sentinel <= 9; sentinel++){

                    check_input = check_guess(sudoku,sentinel,row,col);

                    update_puzzle(sudoku,sentinel,row,col);

                    if ((check_input == true) && (recursive_solver(sudoku,row,col) == true)){
                        return true;
                    }

                    update_puzzle(sudoku,0,row,col);
                }
                return false;
            }
        }
    }

    return true;

}

// this function prints the solved puzzle to a output
void print_puzzle_to_file( OFSTREAM& sudoku_outfile, const VECTOR< VECTOR<int> >& sudoku ){

    for (int i=0; i<ROWS; i++){
        for (int ii=0; ii<COLS; ii++){
            sudoku_outfile << sudoku[i][ii] << " ";
        }
        sudoku_outfile << "" << ENDL;
    }

}