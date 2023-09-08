#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

/**
 *  Board.c has 3 functions that builds the board, prints the board, and deletes the board
*/


/**
 * builds a 2d array to represent the board allocating the memory dynammically
 * @param r: the size of the row of the board
 * @param c: the size of the column of the board
 * @param blank_char: the character to place in each position of the board 
 * @return a 2d array representing the board filled with the given blank_char
*/
char** build_board(int r, int c, char blank_char){
    char** board = (char**)malloc(sizeof(char*) * r);
    for(int i = 0; i < r; i++){
        board[i] = (char*)malloc(sizeof(char) * c);
        for(int j = 0; j < c; j++){
            //printf("i= %d, j= %d\n", i, j);
            board[i][j] = blank_char;  
            //printf("board[%d][%d] = %c\n", i, j, board[i][j]);
            //printf("first index: %c here\n", board[0][0]); 
        }
        
    }
    
    return board;
}


/**
 * prints the board 
 * @param board: the 2d array representing the board
 * @param r: row of the board
 * @param c: the column of the board
 * doesnt return anything
*/
void print_board(char** board, int r, int c){
    //printf("first: %c", board[0][1]);
    for(int i = 0; i < r; i++){
        printf("%d ", r - (i+1));
        for(int j = 0; j < c; j++){
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    printf("  ");
    for(int k = 0; k < c; k++){
        printf("%d ", k);
    }

    printf("\n");
}

/**
 * deletes the board using free given the address to the board
 * @param board: the address of the board
 * @param r: the row of the board 
 * @param c: the column of the board 
 * doesn't return anything
*/
void delete_board(char*** board, int r, int c){
    for(int i = 0; i < r; i++){
            free((*board)[i]);
    }

    free(*board);    
    *board = NULL;


}