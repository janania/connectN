#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "board.h"
#include "setup.h"
#include "play_game.h"
#include <stdlib.h>
#include "input_validation.h"



int main(int argc, char* argv[]){
    if(argc < 4){
        printf("Not enough arguments entered\nUsage connectn.out num_rows num_columns\nnumber_of_pieces_in_a_row_needed_to_win");
        exit(0);
    }else if(argc > 4){
        printf("Too many arguments entered\nUsage connectn.out num_rows num_columns\nnumber_of_pieces_in_a_row_needed_to_win");
        exit(0);
    }else{
        for(int i = 1; i < argc; i++){
            int num = atoi(argv[i]);
            if(num == 0){
                printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win");
                exit(0);
            }
        }
    }


    play_connectn(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
    return 0;
}