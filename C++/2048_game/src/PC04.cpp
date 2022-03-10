/**********************************
 * Name: Gabriel Elbling
 * Email: gelbling@nd.edu
 * File Name: PC04.cpp
 * Date Created: 02/24/2022
 * File Contents: This file contains the main function
 **********************************/

#include "../include/game.h"

int main(){
    
    // create 2D vector
    VECTOR<VECTOR <int> > board(HEIGHT,VECTOR<int>(WIDTH-1,0));

    // create random number
    srand((unsigned int)time(0));

    // define score variable
    int score = 0;

    // initialize first random 2 value in board
    initialize_board(board);
    print_board(board,score);

    // runs the game until the board is completely full
    char usrInput;
    while(check_board(board)){
        // generates new value on board after each move
        generate_new_initial(board);
        print_board(board,score);
        // gets user input
        usrInput = get_move_choice();
        // use user input to run correct functions, update game board, and print the board
        switch(usrInput){
            case 'l':
                move_left(board,score);
                print_board(board,score);
                break;
            case 'r':
                move_right(board,score);
                print_board(board,score);
                break;
            case 'u':
                move_up(board,score);
                print_board(board,score);
                break;
            case 'd':
                move_down(board,score);
                print_board(board,score);
                break;
        }
        
        // check if user wants to continue playing
        COUT << "Do you wish to con continue? (y/n): ";
        char continueGame;
        CIN >> continueGame;
        if (continueGame != 'y'){
            return false;
        }
    }

    return 0;
}