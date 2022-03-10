/**********************************
 * Name: Gabriel Elbling
 * Email: gelbling@nd.edu
 * File Name: PC03.c
 * Date Created: 02/17/2022
 * File Contents: This file contains that main function
 **********************************/

#include "../include/fenwick.h"

int main( const int argc, const char* argv[] ){

    // defining legth variable
    long unsigned int length = (long unsigned int) argc;

    // creating both pointers to arrays that we will use
    int* array = create_array(argv,length);
    int* fenwick_tree = make_fenwick(array,length);

    // menu choice manager variables
    int choice;
    char yesNo;

    // loop that prints menu and calls functions according to user input
    while(true){
        print_menu();
        choice = get_choice();
        switch (choice){
            case 1:
                printf("Array  : ");
                print_array(array,length);
                printf("Fenwick: ");
                print_array(fenwick_tree,length);
                break;
            case 2:
                sum_vals(fenwick_tree,length);
                break;
            case 3:
                update_fenwick(array,fenwick_tree,length);
                break;
        }
        printf("\nDo you wish to continue? (y/n): ");
        scanf(" %c",&yesNo);
        if(yesNo == 'n')
            return 0;
    }

    // freeing pointers
    free(array);
    free(fenwick_tree);
    
    return 0;
}

