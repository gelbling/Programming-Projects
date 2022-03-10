/**********************************
 * Name: Gabriel Elbling
 * Email: gelbling@nd.edu
 * File Name: rotations.c
 * Date Created: 01/27/2022
 * File Contents: This file contains the function declarations
 **********************************/

#include "../include/rotations.h"

void left_shift(int* main_array, long unsigned int size_arr, long unsigned int rotation_amount){
    
    // print values and addresses rotated to left
    long unsigned int i;
    for (i=rotation_amount;i<size_arr;++i){
        fprintf(stdout, "%d at %p \n", main_array[i],&main_array[i]);
    }

    for(i=0;i<rotation_amount;++i){
        fprintf(stdout,"%d at %p \n", main_array[i], &main_array[i]);
    }
}

void right_shift(int* main_array, long unsigned int size_arr, long unsigned int rotation_amount){
    
    // print values and addresses rotated to right
    long unsigned int i;
    for(i=size_arr-rotation_amount;i<size_arr;++i){
        fprintf(stdout,"%d at %p \n", main_array[i], &main_array[i]);
    }
    for(i=0;i<size_arr-rotation_amount;++i){
        fprintf(stdout,"%d at %p \n", main_array[i], &main_array[i]);
    }

}





