/**********************************
 * Name: Gabriel Elbling
 * Email: gelbling@nd.edu
 * File Name: fenwick.c
 * Date Created: 02/17/2022
 * File Contents: This file contains the function definitions
 **********************************/

#include "../include/fenwick.h"

// this function created the main 'array' that is used and populates it with the values entered by the user
int* create_array( const char* argv[], long unsigned int num_inputs ){
    long unsigned int i;
    int* array = (int*) malloc(sizeof(int) * num_inputs);
    array[0] = 0;
    for (i=1;i<num_inputs;i++){
       array[i] = atoi(argv[i]);
    }
    return array;
}

// prints the menu options
void print_menu(){
    printf("------------------------------\n");
    printf("1: Print array and fenwick tree \n2: Calculate range sum \n3: Update array and Fenwick Tree\nENTER YOUR SELECTION: ");
}

// gets the users menu choice and returns it
int get_choice(){
    int choice;
    scanf("%d",&choice);
    return choice;
}

// print array, works for both fenwick and the original array
void print_array( int* the_array, long unsigned int array_len ){
    long unsigned int i;
    for (i=0;i<array_len;i++){
        printf("%d ", the_array[i]);
    }
    printf("\n");
}

// make fenwick creates the fenwick array from the user inputter array and its values
int* make_fenwick( int* array, long unsigned int length ){
    // create array itself
    int* fenwick_tree = (int*) malloc(sizeof(int) * length);

    // populate fenwick array with original array values
    long unsigned int i;
    for(i=0;i<length;i++){
        fenwick_tree[i] = array[i];
    }

    // populate first fenwick array spot with a zero
    int parentVal = array[0];

    // populate all other array entries using binary operations to find indexing
    for (i=0;i<length;i++){
        parentVal = (int) i;
        parentVal = parentVal + (int)(i&-i);
        if ((long unsigned int)parentVal < length)
            fenwick_tree[parentVal] = fenwick_tree[i] + fenwick_tree[parentVal];
    }

    return fenwick_tree;

}

// sums the values in the range and prints out the sum
void sum_vals( int* fenwick, long unsigned int array_len ){
    // get user range inputs
    printf("\nEnter the range to calculate, between 1 and %d: ", (int)array_len);
    int left, right, sum;
    scanf("%d %d", &left, &right);
    int inputtedLeft = left;
    int inputtedRight = right;
    left -= 1;

    // get right side sum
    int sum_right = 0;
    while( right > 0){
        sum_right += fenwick[right];
        right -= right & -right;
    }

    // get left side sum
    int sum_left = 0;
    while( left > 0){
        sum_left += fenwick[left];
        left -= left & -left;
    }

    // calculate difference (total sum) and print it
    sum = sum_right - sum_left;
    printf("\nThe sum from %d to %d: %d\n",inputtedLeft,inputtedRight,sum);
}

// update fenwick array with inputted value and desired index
void update_fenwick( int* array, int* fenwick, long unsigned int array_len ){
    // get user inputs
    printf("\nEnter the location and value to update the initial array: ");
    long unsigned int locationIndex;
    int indexValue;
    scanf("%lu %d", &locationIndex, &indexValue);

    // update all values after the desired replacement index
    long unsigned int i = locationIndex;
    int offset = array[locationIndex] - indexValue;
    array[locationIndex] = indexValue;
    while(i<array_len){
        fenwick[i] -= offset;
        i = i+(i&-i);
    }
}