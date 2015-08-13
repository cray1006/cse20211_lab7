//life.c
//This program of Conway's Game of Life.
//Author:  Christopher Ray		//Date:  29 October 2013

#include <stdio.h>
#include <unistd.h>
#include "lifegame.h"

int main(void)
{
	//declaring variables
	char current_board[BOARD_SIZE][BOARD_SIZE];
	char future_board[BOARD_SIZE][BOARD_SIZE];
	char player;

	int i = 0;
	int j = 0;

	//setting up the two boards and the screen
	setup_board(current_board);
	setup_board(future_board);
	printf("\033[2J\033[H");
	print_board(current_board);

	while(1)
	{	
		//asking for user input
		printf("Press A to add a cell.\nPress R to remove a cell.\nPress N to advance the simulation.\nPress P to run the simulation forever.\nPress Q to quit the program.\n");
		printf("Input:  ");
		scanf(" %c", &player);	
		
		//interpreting user input
		switch(player)
		{
			case 'q': //allows the player to quit
			case 'Q':
			return 0;
			break;
	
			case 'p': //leads to an infinite game
			case 'P':
			while(1)
			{
				for(i = 0; i < BOARD_SIZE; i++) //see comments in void player_choice for how this section of code works
				{
					for(j = 0; j < BOARD_SIZE; j++)
					{
						life_or_death(current_board, future_board, i, j, check_neighbors(current_board, i, j)); 
					}
				}
				change_board(current_board, future_board);
				usleep(200000); //pausing so that the game doesn't run too quickly
				printf("\033[2J\033[H");
				print_board(current_board);	
			}
			break;	

			case 'a': //editing the board
			case 'A':
			case 'r':
			case 'R':
			case 'n':
			case 'N':
			player_choice(current_board, future_board, player);
			break;		
			
			default:
			printf("Invalid input.\n");
			break;
		}
	}
	return 0;
}
