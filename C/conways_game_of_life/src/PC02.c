/**********************************
 * Name: Gabriel Elbling
 * Email: gelbling@nd.edu
 * File Name: PC02.c
 * Date Created: 02/03/2022
 * File Contents: This file contains the main function
 **********************************/

#include "../include/life.h"

int main(const int argc, const char** argv){

    char board[BOARD_HEIGHT][BOARD_WIDTH];

    // check numeber of inputs
    if(argc != 4){
        printf("ERROR : NOT ENOUGH ARGUMENTS \n");
        return 1;
    }

    read_file(board,argv[1]);
    print_board(board);

    int i;
    for(i=0;i<get_num_plays(argv[2]);i++){
        play_generation(board);
    }

    print_to_file(board,argv[3]);

    return 0;
}