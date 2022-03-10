/**********************************
 * Name: Gabriel Elbling
 * Email: gelbling@nd.edu
 * File Name: game.cpp
 * Date Created: 02/24/2022
 * File Contents: This file contains the function definitions
 **********************************/

#include "../include/game.h"

// initialize board with random value
void initialize_board( VECTOR< VECTOR<int> >& game_board ){

    // generate random num
    int randNum = rand() % 16;
    int heightIndex = randNum / 4;
    int widthIndex = randNum % 4;

    // print out random location
    COUT<<"Initial Location: (" << heightIndex << ", " << widthIndex << ")\n";

    // populate random location with 2
    game_board[heightIndex][widthIndex] = 2;

}

// print the game board
void print_board( const VECTOR< VECTOR<int> >& game_board, const int score ){
    
    COUT << "SCORE: " << score << ENDL;

    COUT << "---------\n";
    for (int i=0; i<WIDTH; i++){
        for(int ii=0; ii<HEIGHT; ii++){
            COUT<<"|";
            if (game_board[i][ii]==0){
                COUT << " ";
            }
            else{
                COUT << game_board[i][ii];
            }
        }
        COUT << "|";
        COUT << "\n---------\n";
    }

}

// check if there is a zero on the board, if there is return true if not false
bool check_board( const VECTOR< VECTOR<int> >& game_board ){

    for (int i=0; i<WIDTH; i++){
        for(int ii=0; ii<HEIGHT; ii++){
            if(game_board[i][ii] == 0){
                COUT << "ELIGIBLE TO MAKE A MOVE" << ENDL;
                return true;
            }
        }
    }
    return false;
}

// generate new random 2 on board after each move
void generate_new_initial( VECTOR< VECTOR<int> >& game_board ){
    
    int heightIndex;
    int widthIndex;

    while (true){
        // generate random num
        int randNum = rand() % 16;
        heightIndex = randNum / 4;
        widthIndex = randNum % 4;

        // populate random location with 2
        if (game_board[heightIndex][widthIndex] == 0){
            game_board[heightIndex][widthIndex] = 2;
            break;
        }
    }

    // print out random location
    COUT<<"New 2 place at: (" << heightIndex << ", " << widthIndex << ")\n";
}

// get users move choic from stdin
char get_move_choice(){
    char choice;
    COUT << "MAKE A MOVE CHOICE" << ENDL;
    COUT << "l for left, r for right, u for up, d for down: ";
    CIN >> choice;
    return choice;
}

// execute a move left
void move_left( VECTOR< VECTOR<int> >& game_board, int& score ){
    int i,ii,iii;
    for(i=0;i<HEIGHT;i++){
        // checks board for move possibility
        for(ii=WIDTH-1;ii>=1;ii--){
            if(game_board[i][ii-1]==0){
                game_board[i][ii-1] = game_board[i][ii];
                game_board[i][ii] = 0;

                for(iii=ii;iii<=WIDTH-2;iii++){
                    game_board[i][iii] = game_board[i][iii+1];
                }
                game_board[i][WIDTH-1] = 0;
            }
        }
        // makes multiplication and changes values in board
        for(ii=0;ii<=WIDTH-2;ii++){
            if(game_board[i][ii] == game_board[i][ii+1]){
                game_board[i][ii] = game_board[i][ii] * 2;
                score = score + game_board[i][ii];
                for (iii=ii+1; iii<=WIDTH-2; iii++){
                    game_board[i][iii] = game_board[i][iii+1];
                }
                game_board[i][WIDTH-1] = 0;
            }
        }
    }
}

// execute a move right
void move_right( VECTOR< VECTOR<int> >& game_board, int& score ){
    int i,ii,iii;
    for(i=0;i<HEIGHT;i++){
        // checks board for move possibility
        for(ii=0;ii<=WIDTH-2;ii++){
            if(game_board[i][ii+1]==0){
                game_board[i][ii+1] = game_board[i][ii];
                game_board[i][ii] = 0;

                for(iii=ii;iii>=1;iii--){
                    game_board[i][iii] = game_board[i][iii-1];
                }

                game_board[i][0] = 0;
            }
        }
        // makes multiplication and changes values in board
        for(ii=WIDTH-1;ii>=1;ii--){
            if(game_board[i][ii] == game_board[i][ii-1]){
                game_board[i][ii] = game_board[i][ii] * 2;
                score = score + game_board[i][ii];
                for (iii=ii-1; iii>=1; iii--){
                    game_board[i][iii] = game_board[i][iii-1];
                }

                game_board[i][0] = 0;
            }
        }
    }
}

// execute a move down
void move_down( VECTOR< VECTOR<int> >& game_board, int& score ){
    int i,ii,iii;
    for(i=0;i<WIDTH;i++){
        // checks board for move possibility
        for(ii=0;ii<=HEIGHT-2;ii++){
            if(game_board[ii+1][i]==0){
                game_board[ii+1][i] = game_board[ii][i];
                game_board[ii][i] = 0;
                for(iii=ii;iii>=1;iii--){
                    game_board[iii][i] = game_board[iii-1][i];
                }
                game_board[0][i] = 0;
            }
        }
        // makes multiplication and changes values in board
        for(ii=HEIGHT-1;ii>=1;ii--){
            if(game_board[ii][i] == game_board[ii-1][i]){
                game_board[ii][i] = game_board[ii][i] * 2;
                score = score + game_board[ii][i];
                for(iii=ii-1;iii>=1;iii--){
                    game_board[iii][i] = game_board[iii-1][i];
                }
                game_board[0][i] = 0;
            }
        }
    }
}

// exeute a move up
void move_up( VECTOR< VECTOR<int> >& game_board, int& score ){
    int i,ii,iii;
    for(i=0;i<WIDTH;i++){
        // checks board for move possibility
        for(ii=HEIGHT-1;ii>=1;ii--){
            if(game_board[ii-1][i]==0){
                game_board[ii-1][i] = game_board[ii][i];
                game_board[ii][i] = 0;
                for(iii=ii;iii<=HEIGHT-2;iii++){
                    game_board[iii][i] = game_board[iii+1][i];
                }
                game_board[HEIGHT-1][i] = 0;
            }
        }
        // makes multiplication and changes values in board
        for(ii=0;ii<=HEIGHT-2;ii++){
            if(game_board[ii][i] == game_board[ii+1][i]){
                game_board[ii][i] = game_board[ii][i] * 2;
                score = score + game_board[ii][i];
                for(iii=ii+1;iii<=HEIGHT-2;iii++){
                    game_board[iii][i] = game_board[iii+1][i];
                }
                game_board[HEIGHT-1][i] = 0;
            }
        }
    }
}

