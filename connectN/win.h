#ifndef WIN_H
  #define WIN_H
	
    bool is_vertical_win(char** board, int r, int c, int num_needed, int* Player, int pos, int row_of_piece);
    bool is_horizotal_win(char** board, int r, int c, int num_needed, int* Player, int pos, int row_of_piece);
    bool is_board_full(char** board, int r, int c);
    bool is_Rdiagonal_win(char** board, int r, int c, int num_needed, int* Player, int pos, int row_of_piece);
    bool is_Ldiagonal_win(char** board, int r, int c, int num_needed, int* Player, int pos, int row_of_piece);
    int has_someone_won(char**board, int r, int c, int num_needed, int *player, int pos, int row_of_piece);


#endif