/**********************************
 * Name: Gabriel Elbling
 * Email: gelbling@nd.edu
 * File Name: sudoku.h
 * Date Created: 03/03/2022
 * File Contents: This file contains the function declarations
 **********************************/

#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>

#define ROWS 9
#define COLS 9
#define COUT std::cout
#define CIN std::cin
#define ENDL std::endl
#define VECTOR std::vector
#define IFSTREAM std::ifstream
#define OFSTREAM std::ofstream

// Function Declarations will go here

void print_greeting( void );
void populate_puzzle( IFSTREAM& sudoku_infile, VECTOR< VECTOR<int> >& sudoku );
void update_puzzle( VECTOR< VECTOR<int> >& sudoku, int value, long unsigned int row,  long unsigned int col );
bool check_puzzle( const VECTOR< VECTOR<int> >& sudoku );
bool check_guess( const VECTOR< VECTOR<int> >& sudoku, int value, long unsigned int row, long unsigned int col );
void print_puzzle( const VECTOR< VECTOR<int> >& sudoku );
bool recursive_solver( VECTOR< VECTOR<int> >& sudoku, long unsigned int row, long unsigned int col );
void print_puzzle_to_file( OFSTREAM& sudoku_outfile, const VECTOR< VECTOR<int> >& sudoku );

#endif