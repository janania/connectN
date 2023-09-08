#ifndef PLAY_GAME_H
  #define PLAY_GAME_H
	
    void play_game(int r, int c, char** board, int* player);
    void place_piece_on_board(char** board, char piece, int pos, int r, int c);
    int get_valid_position(int c, int r, char** board, char piece, int* row_of_piece);
    void play_connectn();

#endif