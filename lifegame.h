//lifegame.h
//Header file for lifegame.c and life.c.
//Author:  Christopher Ray		//Date:  29 October 2013

#define BOARD_SIZE 40

// printf("\033[2J\033[H");

void setup_board(char board[BOARD_SIZE][BOARD_SIZE]);

void print_board(char board[BOARD_SIZE][BOARD_SIZE]);  

void add_cell(char board[BOARD_SIZE][BOARD_SIZE], int row, int column);

void delete_cell(char board[BOARD_SIZE][BOARD_SIZE], int row, int column);

void change_board(char current_board[BOARD_SIZE][BOARD_SIZE], char future_board[BOARD_SIZE][BOARD_SIZE]);

int check_neighbors(char board[BOARD_SIZE][BOARD_SIZE], int row, int column);

void life_or_death(char current_board[BOARD_SIZE][BOARD_SIZE], char future_board[BOARD_SIZE][BOARD_SIZE], int row, int column, int cells);

void player_choice(char current_board[BOARD_SIZE][BOARD_SIZE], char future_board[BOARD_SIZE][BOARD_SIZE], char player);
