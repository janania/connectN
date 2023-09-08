#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "play_game.h"
#include "board.h"
#include "setup.h"


/**
 * checks if a player has a vertical win after a move (traverses the array vertically starting
 * from the row the piece was placed)
 * a player wins if there are atleast n number of consecutive pieces (n = numneeded)
 * @param board: the board with the pieces
 * @param r: the row of the board
 * @param c: the column of the board
 * @param num_needed: the number needed to win
 * @param player: the pointer to the player number (int)
 * @param pos: the column the piece was placed
 * @param row_of_piece; the row the piece was placed 
 * @return the boolean value of if there was a vertical win or not
*/
bool is_vertical_win(char** board, int r, int c, int num_needed, int* Player, int pos, int row_of_piece){
    bool win = false;
    char piece = which_piece(Player);
    int num = 0;
    for(int i = row_of_piece; i < r; i++){
        //print_board(board, r, c);
        //printf("i = %d, pos = %d, the piece = %c\n", i, pos, board[i][pos]);
        if(board[i][pos] != piece){
            //printf("vertical win?: %d", win);
            return win;
        } 
        else if (board[i][pos] == piece){
            //printf("piece= %c, i = %d\n", board[i][pos], i);
            num += 1;
            if(num == num_needed){
                break;
            }

        }
    }
    //printf("final num = %d\n", num);
    if(num == num_needed){
        win = true;
    }

    return win;
}

/**
 * checks if a player has a vertical win after a move (traverses the array horizontally starting
 * from the 0th column of the row the piece was placed)
 * a player wins if there are atleast n number of consecutive pieces (n = numneeded)
 * @param board: the board with the pieces
 * @param r: the row of the board
 * @param c: the column of the board
 * @param num_needed: the number needed to win
 * @param player: the pointer to the player number (int)
 * @param pos: the column the piece was placed
 * @param row_of_piece; the row the piece was placed 
 * @return the boolean value of if there was a horizontal win or not
*/
bool is_horizontal_win(char** board, int r, int c, int num_needed, int* Player, int pos, int row_of_piece){
    bool win = false;
    char piece = which_piece(Player);
    int num = 0;
    //printf("Hello\n");
    //printf("c = %d", c);

    for(int i = 0; i < c; i++){
        //printf("num: %d\n", num);
        if(board[row_of_piece][i] == piece){
            //printf(" piece = %c i = %d\n", board[row_of_piece][i], i);
            num++;
        } 
        else {
            num = 0;
        }

        if(num == num_needed){
            win = true;
            return win;
        }
        
    }
    //printf("horizontal win?: %d", win);
    return win;




}

/**
 * checks if a player has a right diagonal win after a move (traverses the array right diagonally
 *  starting from the position the piece was placed and traverses top right and bottom left)
 * a player wins if there are atleast n number of consecutive pieces (n = numneeded)
 * @param board: the board with the pieces
 * @param r: the row of the board
 * @param c: the column of the board
 * @param num_needed: the number needed to win
 * @param player: the pointer to the player number (int)
 * @param pos: the column the piece was placed
 * @param row_of_piece; the row the piece was placed 
 * @return the boolean value of if there was a right diagonal win or not
*/
bool is_Rdiagonal_win(char** board, int r, int c, int num_needed, int* Player, int pos, int row_of_piece){
    bool win = false;
    
    int consec = 1;
    char piece = which_piece(Player);
    //top right
    int rtr = row_of_piece - 1;
    int ctr = pos + 1;
    
    //bottom left
    int rbl = row_of_piece + 1;
    int cbl = pos - 1;

    //printf("rtr: %d\n", rtr);
    //printf("ctr: %d\n", ctr);
    while( rtr >= 0 && ctr < c && consec != num_needed){
        //printf("enters top right");
        if(board[rtr][ctr] == piece){
            consec += 1;
        } else {
            consec = 0;
        }
        rtr--;
        ctr++;
    }

    if(consec == 0){
        consec = 1;
    }
    //printf("rbl: %d\n", rbl);
    //printf("cbl: %d\n", cbl);
    while( rbl < r && cbl >= 0 && consec != num_needed){
        
        //printf("enters bottom left = %c\n", board[rbl][cbl]);
        if(board[rbl][cbl] == piece){
            //printf("enters correct if:\n");
            consec += 1;
            //printf("consec correct = %d", consec);
        } else {
            consec = 0;
        }
        rbl++;
        cbl--;
        //printf("consec = %d\n", consec);
    }

    if(consec  == num_needed){
        win = true;
    }
    return win;

}

/**
 * checks if a player has a right diagonal win after a move (traverses the array left diagonally
 *  starting from the position the piece was placed and traverses top left and bottom right)
 * a player wins if there are atleast n number of consecutive pieces (n = numneeded)
 * @param board: the board with the pieces
 * @param r: the row of the board
 * @param c: the column of the board
 * @param num_needed: the number needed to win
 * @param player: the pointer to the player number (int)
 * @param pos: the column the piece was placed
 * @param row_of_piece; the row the piece was placed 
 * @return the boolean value of if there was a left diagonal win or not
*/
bool is_Ldiagonal_win(char** board, int r, int c, int num_needed, int* Player, int pos, int row_of_piece){
    bool win = false;
    
    int consec = 1;
    char piece = which_piece(Player);
    //top left
    int rtl = row_of_piece - 1;
    int ctl = pos - 1;
    
    //bottom right
    int rbr = row_of_piece + 1;
    int cbr = pos + 1;

    //traverse top left
    while( rtl >= 0 && ctl >= 0 && consec != num_needed){
        //printf("enters top right");
        if(board[rtl][ctl] == piece){
            consec += 1;
        } else {
            consec = 0;
        }
        rtl--;
        ctl--;
    }

    if(consec == 0){
        consec = 1;
    }
    //travels bottom right
    while( rbr < r && cbr < c && consec != num_needed){
        
        //printf("enters bottom left = %c\n", board[rbl][cbl]);
        if(board[rbr][cbr] == piece){
            //printf("enters correct if:\n");
            consec += 1;
            //printf("consec correct = %d", consec);
        } else {
            consec = 0;
        }
        rbr++;
        cbr++;
        //printf("consec = %d\n", consec);
    }

    if(consec  == num_needed){
        win = true;
    }
    return win;
}

/**
 * checks if the board is full which means there are not blank characters left 
 * returns the boolean value based on if the board is full
*/
bool is_board_full(char** board, int r, int c){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            //printf("board piece = %c", board[i][j]);
            if(board[i][j] == '*'){
                return false;
            }
        }
    }

    return true;
}

/**
 * checks if a character has won after a move by callign the verticalwin, horizontalwin, rdiagonalwin,
 * and ldiagonal win functions 
 * @param board: the board with the pieces
 * @param r: the row of the board
 * @param c: the column of the board
 * @param num_needed: the number needed to win
 * @param player: the pointer to the player number (int)
 * @param pos: the column the piece was placed
 * @param row_of_piece; the row the piece was placed 
 * returns the number of the player that has won, 0 if there was a tie and -1 if no one won
*/
int has_someone_won(char**board, int r, int c, int num_needed, int* player, int pos, int row_of_piece){
    //printf("horizontal win?: %d\n", is_horizontal_win(board, r, c, num_needed, player, pos, row_of_piece));
   // printf("vertical win?: %d\n", is_vertical_win(board, r, c, num_needed, player, pos, row_of_piece));
    //printf("Rdiagonal_win?: %d\n", is_Rdiagonal_win(board, r, c, num_needed, player, pos, row_of_piece));
    //printf("Ldiagonal_win?: %d\n", is_Ldiagonal_win(board, r, c, num_needed, player, pos, row_of_piece));
    if(is_vertical_win(board, r, c, num_needed, player, pos, row_of_piece)  
        || is_horizontal_win(board, r, c, num_needed, player, pos, row_of_piece)
        || is_Rdiagonal_win(board, r, c, num_needed, player, pos, row_of_piece)
        || is_Ldiagonal_win(board, r, c, num_needed, player, pos, row_of_piece)){
        //printf("%d\n", *player);
        return *player;
    }
    else if (is_board_full(board, r, c)){
        //printf("0\n");
        return 0;
    }
    //printf("-1\n");
    return -1;

}

