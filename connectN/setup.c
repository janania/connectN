#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "board.h"

/**
 * setup.c sets up the game by building the board and deciding which player goes first 
 * it has 3 functions that help with the setup
*/

/**
 * returns the appropriate char either an X or an O depending on the player number
 * @param player: a pointer to the player (int)
 * @return the appropriate char for the playe
*/
char which_piece(int* player){
    if (*player == 1){
        return 'X';
    }
    return 'O';
}

/**
 * returns the plyer that goes first which is always player 1
*/
int who_goes_first(){
    return 1; //player 1 always goes first
}


/**
 * setups up the game by buildingn the board and setting player == 1
 * @param r: the row of the board
 * @param c: the column of the board
 * @param num_needed: the num of verticals, horizontals, diagonals needed to win 
 * @param player: the pointer to the player 
 * @return the board that has been set up;
*/
char** setup_game(int r, int c, int num_needed, int* player){
    char** board = build_board(r, c,'*');
    *player = who_goes_first();
   
    return board;

}





//check if given dimensions are valid 
    //usage and input validation
//make board based on given dimensions
//print out board
//set player one as X
//set player two as O
//ask player to pick piece 
//check if entered value is valid (input validation)
//update board 