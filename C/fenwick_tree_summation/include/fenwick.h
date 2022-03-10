/**********************************
 * Name: Gabriel Elbling
 * Email: gelbling@nd.edu
 * File Name: fenwick.h
 * Date Created: 02/17/2022
 * File Contents: This file contains the function declarations
 **********************************/

// included libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// function headers
int* create_array( const char* argv[], long unsigned int num_inputs );
void print_menu();
int get_choice();
void print_array( int* the_array, long unsigned int array_len );
int* make_fenwick( int* array, long unsigned int length );
void sum_vals( int* fenwick, long unsigned int array_len );
void update_fenwick( int* array, int* fenwick, long unsigned int array_len );