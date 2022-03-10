/**********************************
 * Name: Gabriel Elbling
 * Email: gelbling@nd.edu
 * File Name: PC01.c
 * Date Created: 01/27/2022
 * File Contents: This file contains the main function
 **********************************/

#include "../include/rotations.h"

int main(void){

    long unsigned int rotation_amount, size_arr;
    char orientation;
    char run = 'y';

    while(run=='y'){

        //clearBuffer();

        // get user specification inputs
        fprintf(stdout,"Enter the size, num rotations, and direction: ");
        fscanf(stdin, "%lu %lu %c", &size_arr, &rotation_amount, &orientation);

        // create aray
        int* main_array = (int*)malloc(size_arr * sizeof(int));

        // get  array input values from user
        fprintf(stdout, "Input the %lu values now: ", size_arr);
        long unsigned int i;
        for(i=0;i<size_arr;++i){
            fscanf(stdin,"%d",&main_array[i]);
        }

        // print before rotation array
        fprintf(stdout, "Before rotation: \n");
        for(i=0;i<size_arr;++i){
            fprintf(stdout, "%d at %p \n", main_array[i], main_array+i);
        }

        fprintf(stdout, "\nAfter rotation: \n");

        // run function according to user desired shift orientation
        if(orientation=='L')
            left_shift(main_array,size_arr,rotation_amount);
        else if (orientation=='R')
            right_shift(main_array,size_arr,rotation_amount);

        // check if user wants to continue
        fprintf(stdout, "Would you like to continue? (y/n) ");
        fscanf(stdin," %c",&run);

        free(main_array);

    }
}
