#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "board.h"
#include "setup.h"
#include "win.h"
#include "input_validation.h"


/**
 * uses functions from the other files to offically play the game where the board is built
 * the user is asked for the dimensions of the board and the number needed to win
 * the input is validated and the piece is placed on the right position and the board is checked
 * if there is a win or a tie and an appropriate message is printed accordingly
*/

/**
 * places the piece on the board if the given the column isn't already full
 * @param board: the board to place the piece in
 * @param piece: the piece to be placed
 * @param pos: the column the piece is supposed to be placed
 * @param r: thr row dimensions of the board
 * @param c: the column dimension of the board
 * @return the row in which the piece was placed or return -1 if piece couldn't be placed 
*/
int place_piece_on_board(char** board, char piece, int pos, int r, int c){
    for(int i = r-1; i >= 0; i--){
        //printf("%d", r);
        if(board[i][pos] == '*'){
            board[i][pos] = piece;
            //printf("i inside place = %d/n", i);
            return i;
        }
    }
    return -1;
}

/**
 * gets a valid position for the piece to be placed from the player and keeps asking until 
 * valid position is entered (fits the range of 0  and the column size) and the column isn't full
 * @param c: the column of the board
 * @param r: the row of the board
 * @param board: the board the piece is trying to be placed
 * @param piece: the piece that is trying to be placed
 * @param row_of_piece: the row that the piece is being placed
 * @return the valid position 
*/
int get_valid_position(int c, int r, char** board, char piece, int* row_of_piece){
    int pos = getValidIntInRange(0, c-1);
    *row_of_piece = place_piece_on_board(board, piece, pos, r, c);
    while( *row_of_piece == -1){
        pos = getValidIntInRange(0, c-1);
        *row_of_piece = place_piece_on_board(board, piece, pos, r, c);
        

    }
    return pos;
}


/**
 * Plays the game by creating the board based on the right dimensions and checking if the position is vaid
 * it prints the board accordingly and checks if someone has won after every move 
 * if someone has won or if there is a tie, it prints a message accordingly
 * @param r: the row of the board
 * @param c: the column of the board
 * @param board: the board that is used for the game
 * @param player: an pointer to the player 
 * @param num_needed, the number needed to win the game
 * it doesn't return anything
*/
void play_game(int r, int c, char** board, int* player, int num_needed){
    print_board(board, r, c);
    int pos;
    char piece = which_piece(player);
    int row_of_piece = 0;
    pos = get_valid_position(c, r, board, piece, &row_of_piece);
    print_board(board, r, c);

    //printf("row of piece: %d", row_of_piece);
    
    //int win = has_someone_won(board, r, c, num_needed, player, pos, row_of_piece);
    //printf(" win number: %d\n", win);
    while((has_someone_won(board, r, c, num_needed, player, pos, row_of_piece) < 0)){
        if(*player == 2){
            *player = 1;
        } else {
            *player = 2;
        }

        piece = which_piece(player);
        pos = get_valid_position(c, r, board, piece, &row_of_piece);
        print_board(board, r, c);
        
    }
    if (has_someone_won(board, r, c, num_needed, player, pos, row_of_piece) > 0){
        printf("Player %d Won!", *player);
    } else {
        printf("Tie game!");
    }
    
}



/**
 * combines the above functions to play the game using setup, play_game, and delete board 
 * @param r: the row of the board
 * @param c: the column of the board
 * @param num_needed: the number needed to win
 * return nothing 
*/
void play_connectn(int r, int c, int num_needed){
    int player = 1;
    //scanf(" %d %d %d", &r, &c, &num_needed);
    char** board = setup_game(r, c, num_needed, &player);
	play_game(r, c, board, &player, num_needed);
	delete_board(&board, r, c);

}



