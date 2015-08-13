//lifegame.c
//This will house the functions necessary for playing Conway's Game of Life.
//Author:  Christopher Ray		//Date:  29 October 2013

#include <stdio.h>
#include "lifegame.h"

void setup_board(char board[BOARD_SIZE][BOARD_SIZE]) //function for setting up board
{
	int i = 0;
	int j = 0;
	
	for(i = 0; i < BOARD_SIZE; i++) //as the loops run, the array is filled with blank spaces
	{
		for(j = 0; j < BOARD_SIZE; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void print_board(char board[BOARD_SIZE][BOARD_SIZE]) //function for printing the board
{
	int i = 0;
	int j = 0;
	
	for (i = 0; i < BOARD_SIZE; i++) //each iteration of the out for loop prints a new row
	{
		for (j = 0; j < BOARD_SIZE; j++) //each iteration of the inner for loop prints the next column for the row
		{
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
	return;
}

void add_cell(char board[BOARD_SIZE][BOARD_SIZE], int row, int column) //function for adding a cell to the board
{
	if(board[row][column] == 'X') //does not add a cell if a cell is already present
	{
		return;
	}
	else
	{
		board[row][column] = 'X';
		return;
	}
}

void delete_cell(char board[BOARD_SIZE][BOARD_SIZE], int row, int column) //function for deleting a cell on the board
{
	if(board[row][column] == ' ') //does nothing if there is no cell to delete
	{
		return;
	}
	else
	{
		board[row][column] = ' ';
		return;
	}
}

void change_board(char current_board[BOARD_SIZE][BOARD_SIZE], char future_board[BOARD_SIZE][BOARD_SIZE]) //function for changing between the current board and the future board
{
	int i = 0;
	int j = 0;
	for(i = 0; i < BOARD_SIZE; i++) //as the for loop run, each element of the current board is replaced with the corresponding element in the future board
	{
		for(j = 0; j < BOARD_SIZE; j++)
		{
			current_board[i][j] = future_board[i][j];
		}
	}
}

int check_neighbors(char board[BOARD_SIZE][BOARD_SIZE], int row, int column) //function for determining how many live cells surround the current cell
{
	int cells = 0; //iterated every time a live cell is detected

	if(((column == 0) && (row == 0))) //checking the upper left corner 
	{
		if(board[0][1] == 'X') cells++;
		
		else if(board[1][0] == 'X') cells++;
                
		else if(board[1][1] == 'X') cells++;
         	return cells;       
	}
	else if(((column == 39) && (row == 0))) //checkking upper right corner                
        {
                if(board[0][38] == 'X') cells++;
                
                else if(board[1][39] == 'X') cells++;
                
                else if(board[1][38] == 'X') cells++;
		return cells;
        }
	
	else if(((column == 0) && (row == 39))) //checking lower left corner
        {
                if(board[38][0] == 'X') cells++;
                
                else if(board[39][1] == 'X') cells++;
                
                else if(board[38][1] == 'X') cells++;
                return cells;
        }
	else if(((column == 39) && (row == 39))) //checking lower right corner
        {
                if(board[39][38] == 'X') cells++;
                
                else if(board[38][38] == 'X') cells++;
                
                else if(board[38][39] == 'X') cells++;
                return cells;
        }
	else if(row == 0) //checking first row
	{
		int x = 0;
		if(board[row][column - 1] == 'X') cells++;
		
		else if(board[row][column + 1] == 'X') cells++;
                
		for(x = -1; x < 2; x++)
		{
			if(board[row + 1][column + x] == 'X') cells++;
		}
		return cells;
	}
	else if(row == 39) //checking last row
        {
                int x = 0;
                if(board[row][column - 1] == 'X') cells++;
                
                else if(board[row][column + 1] == 'X') cells++;
                
                for(x =	-1; x <	2; x++)
                {
                        if(board[row - 1][column + x] == 'X') cells++;
                }
		return cells;
        }
	else if(column == 0) //checking first column
        {
                int x = 0;
                if(board[row - 1][column] == 'X') cells++;
               
                else if(board[row + 1][column] == 'X') cells++;
                
                for(x =	-1; x <	2; x++)
                {
                        if(board[row + x][column + 1] == 'X') cells++;
                }
		return cells;
        }
	else if(column == 39) //checking last column
        {
                int x = 0;
                if(board[row - 1][column] == 'X') cells++;
            
                else if(board[row + 1][column] == 'X') cells++;
                
                for(x = -1; x < 2; x++)
                {
                        if(board[row + x][column - 1] == 'X') cells++;
                }
		return cells;
        }
	else //checking any cells that do not meet the above criteria
	{
		int x = 0;
		if(board[row][column - 1] == 'X') cells++;
		if(board[row][column + 1] == 'X') cells++;
		for(x = -1; x < 2; x++)
		{
			if(board[row - 1][column + x] == 'X') cells++;
			if(board[row + 1][column + x] == 'X') cells++;
		}
		return cells;
	}
}

void life_or_death(char current_board[BOARD_SIZE][BOARD_SIZE], char future_board[BOARD_SIZE][BOARD_SIZE], int row, int column, int cells) //function for applying rules of the Game of Life
{
	if ((current_board[row][column] == ' ') && (cells == 3)) future_board[row][column] = 'X';
	else if ((current_board[row][column] == 'X') && ((cells == 2) || (cells == 3))) return;
	else future_board[row][column] = ' ';
	return;
}

void player_choice(char current_board[BOARD_SIZE][BOARD_SIZE], char future_board[BOARD_SIZE][BOARD_SIZE], char player) //function used to interpret the player's choice
{
	int row = 0;
	int column = 0;
	int i = 0;
	int j = 0;

	switch(player)
	{
		case 'a': //adding a cell
		case 'A':
		printf("Inserting a cell.\n");
		printf("Enter a row (any positive int < 40):  ");
		scanf("%d", &row);
		if((row < 0) || (row > 40))
		{
			printf("Invalid input.\n");
			return;
		}	
		printf("Enter a column (any positive int < 40):  ");
		scanf("%d", &column);
		if((column < 0) || (column > 40))
		{
			printf("Invalid input.\n");
			return;
		}
		add_cell(future_board, row, column); //all edits are made to the future board
		change_board(current_board, future_board); //the boards a switched (current board is updated)
		printf("\033[2J\033[H");
		print_board(current_board); //current board is printed		
		break;

		case 'r': //removing a cell
		case 'R':
		printf("Removing a cell.\n");
		printf("Enter a row (any positive int < 40):  ");
		scanf("%d", &row);
		if((row < 0) || (row > 40))
		{
			printf("Invalid input.\n");
			return;
		}	
		printf("Enter a column (any positive int < 40):  ");
		scanf("%d", &column);
		if((column < 0) || (column > 40))
		{
			printf("Invalid input.\n");
			return;
		}
		delete_cell(future_board, row, column);
		change_board(current_board, future_board);
		printf("\033[2J\033[H");
		print_board(current_board);				
		break;

		case 'n': //applying the rules of the game
		case 'N':
		for(i = 0; i < BOARD_SIZE; i++) //the functions will read the current board but will apply the changes to the future board
		{
			for(j = 0; j < BOARD_SIZE; j++)
			{
				life_or_death(current_board, future_board, i, j, check_neighbors(current_board, i, j)); 
			}
		}
		change_board(current_board, future_board); //boards are switched
		printf("\033[2J\033[H");
		print_board(current_board);
		break;

		default:
		return;
		break;
	}
	return;
}
