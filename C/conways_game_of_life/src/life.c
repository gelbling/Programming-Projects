/**********************************
 * Name: Gabriel Elbling
 * Email: gelbling@nd.edu
 * File Name: life.c
 * Date Created: 02/03/2022
 * File Contents: This file contains the function declarations 
 **********************************/

#include "../include/life.h"

// read file data into array
void read_file (char board[][BOARD_WIDTH], const char *name){
    FILE *f;
    f = fopen(name,"r");
    int i,ii;
    char x;
    for(i=0;i<BOARD_HEIGHT;i++){
        for(ii=0;ii<BOARD_WIDTH;ii++){
            fscanf(f," %c",&x);
            if(x!='\n')
                board[i][ii] = x;
        }
    }
    fclose(f);
}

// print gameboard onto standard output
void print_board (char board[][BOARD_WIDTH]){
    int i,ii;
    for(i=0;i<BOARD_HEIGHT;i++){
        for(ii=0;ii<BOARD_WIDTH;ii++){
            printf("%c",board[i][ii]);
        }
        printf("\n");
    }
}

// check and return number of neighbors
int adjacent_to (char board[][BOARD_WIDTH], int x_index, int y_index){
    int count = 0;
    int x_verify, y_verify;
    int i,ii;

    if(board[x_index][y_index]=='X')
        count--;

    for (i=-1;i<=1;i++){
        for(ii=-1;ii<=1;ii++){
            x_verify = x_index + i;
            y_verify = y_index +ii;
            if(y_verify>=BOARD_WIDTH || y_verify<0){
                y_verify = width_add(y_verify,BOARD_WIDTH);
            }
            if(x_verify>=BOARD_HEIGHT || x_verify<0){
                x_verify = height_add(x_verify,BOARD_HEIGHT);
            }
            if(board[x_verify][y_verify]=='X'){
                count++;
            }
        }
    }
    return count;
}

// adds width if cell is out of bounds on the y axis
int width_add (int width_index, int width_offset){
    if(width_index < 0){
        return width_index + width_offset;
    }
    else if(width_index >= width_offset){
        return width_index - width_offset;
    }
    else{
        return width_index;
    }
}

// adds height if cell is out of bounds on the x axis
int height_add (int height_index, int x_offset){
    if(height_index < 0){
        return height_index + x_offset;
    }
    else if(height_index >= x_offset){
        return height_index - x_offset;
    }
    else{
        return height_index;
    }
}

// runs a generation of the game of life
void play_generation (char board[][BOARD_WIDTH]){

    char temp_board[BOARD_HEIGHT][BOARD_WIDTH];
    int neighbors_count;
    int i,ii;

    for(i=0;i<BOARD_HEIGHT;i++){
        for(ii=0;ii<BOARD_WIDTH;ii++){
            neighbors_count = adjacent_to(board,i,ii);
            if(board[i][ii]=='X' && (neighbors_count==2 || neighbors_count==3)){
                temp_board[i][ii] = 'X';
            }
            else if(board[i][ii]=='.' && neighbors_count==3){
                temp_board[i][ii] = 'X';
            }
            else{
                temp_board[i][ii] = '.';
            }
        }
    }

    for(i=0;i<BOARD_HEIGHT;i++){
        for(ii=0;ii<BOARD_WIDTH;ii++){
            board[i][ii] = temp_board[i][ii];
        }
    }
}

// prints final output to file
void print_to_file (char board[][BOARD_WIDTH], const char *name ){
    FILE *f;
    f = fopen(name,"w");
    int i,ii;
    for(i=0;i<BOARD_HEIGHT;i++){
        for(ii=0;ii<BOARD_WIDTH;ii++){
            fprintf(f,"%c",board[i][ii]);
        }
        fprintf(f,"\n");
    }
    fclose(f);
}

// converts number of plays from inputter char to int
int get_num_plays ( const char *num_plays ){
    return atoi(num_plays);
}
