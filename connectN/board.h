#ifndef BOARD_H
  #define BOARD_H
	char** build_board(int r, int c, char blank_char);
	void print_board(char** board, int r, int c);
	void delete_board(char*** board, int r , int c);
#endif