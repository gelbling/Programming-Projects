/**********************************
 * Name: Gabriel Elbling
 * Email: gelbling@nd.edu
 * File Name: PC05.cpp
 * Date Created: 03/03/2022
 * File Contents: This file contains the main function
 **********************************/

#include "../include/sudoku.h"

//const int argc, const char* argv []
int main(const int argc, const char* argv []){

    // check if there are enough arguments
    if(argc != 3){
        COUT << "-- NOT ENOUGH ARGUMENTS --" << ENDL;
        exit(1);
    }

    // create sudoku board vector
    VECTOR< VECTOR <int> > sudoku(ROWS,VECTOR<int>(COLS-1,0));

    // read populate gameboard from file
    //open file to read from
    IFSTREAM sudoku_infile( argv[1] );

    //open file to output
    OFSTREAM sudoku_outfile( argv[2] );

    // populate board vector
    populate_puzzle(sudoku_infile,sudoku);

    // print game greeting
    print_greeting();

    COUT << "INITIAL PUZZLE: " << ENDL;
    
    // print initial puzzle
    print_puzzle(sudoku);

    COUT << "Attempting to solve the puzzle..." << ENDL;

    recursive_solver(sudoku,0,0);

    // check if puzzle has been solved
    if (check_puzzle(sudoku))
        COUT << "Puzzle has been solved!" << ENDL;
    else
        COUT << "Puzzle is not solvable..." << ENDL;

    // print solved puzzle
    print_puzzle(sudoku);

    // print solved puzzle to output file
    print_puzzle_to_file(sudoku_outfile,sudoku);

    // close file (free file pointer)
    sudoku_infile.close();
    sudoku_outfile.close();

    return 0;
}