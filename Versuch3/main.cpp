/**
 * @file main.cpp
 *
 * Provides functions for the game Reversi
 */

/**
* @mainpage Reversi
*
* Dokumentation des Spiels Reversi im Rahmen des Praktikums Informatik 1.
*
*/

/**Defines the type of a player */
#define HUMAN 1
#define COMPUTER 2

#include "test.h"
#include "config.h"
#include "Reversi_KI.h"
#include <iostream>
#include <stdlib.h>
#include <string>

/**
 * @fn	void initialize_field(int field[SIZE_Y][SIZE_X])
 * 		
 * @brief Function providing first initialization of a new field
 *
 * This function fills an existing field with zeros and creates the starting pattern.
 *
 * @param field[SIZE_Y][SIZE_X] The field which will be initialized
 */
void initialize_field(int field[SIZE_Y][SIZE_X])
{
	for (int j = 0; j < SIZE_Y; j++)
	{
		for (int i = 0; i < SIZE_X; i++)
		{
			field[j][i] = 0;
		}
	}
	field[SIZE_Y / 2 - 1][SIZE_X / 2 - 1] = 1;
	field[SIZE_Y / 2][SIZE_X / 2 - 1] = 2;
	field[SIZE_Y / 2 - 1][SIZE_X / 2] = 2;
	field[SIZE_Y / 2][SIZE_X / 2] = 1;
}

/**
* @fn	void show_field(const int field[SIZE_Y][SIZE_X])
* 		
* @brief Prints the playing field to the console.
*
* This function gets the current playing field as parameter (two dimensional array)
* with entries of 0 (field is empty), 1 (field belongs to player 1), 2 (field belongs to player 2).
* <br>The function prints the playing field, grid included, to the console.
* Crosses symbolize player 1 while circles symbolize player 2.
*
*  @param field[SIZE_Y][SIZE_X]  The field to be printed
*/
void show_field(const int field[SIZE_Y][SIZE_X])
{
	std::cout << "  ";

//Start at ASCII 65 = A
	for (int j = 65; j < 65 + SIZE_Y; j++)
		std::cout << ((char) j) << " " ;

	std::cout << std::endl;

	for (int j = 0; j < SIZE_Y; j++)
	{
		std::cout << j + 1;
		for (int i = 0; i < SIZE_X; i++)
		{
			switch (field[j][i])
			{
				case 0:
					std::cout << "  " ;
					break;
				case 1:
					std::cout << " X";
					break;
				case 2:
					std::cout << " O";
					break;
				default:
					std::cout << "Inconsistent data in field!" << std::endl;
					std::cout << "Aborting .... " << std::endl;
					exit(0);
					break;
			}
		};//for i
		std::cout << std::endl;
	}//for j
}

/*!
 * @fn	int winner(const int field[SIZE_Y][SIZE_X])
 *
 * @brief	Determines the winner of a given end-situation.
 *
 * @param	field[SIZE_Y][SIZE_X]	The field.
 *
 * @return	The winner code:
 * 							0:		=>		draw,
 * 							1:		=>		player 1 wins,   
 * 							2:		=>		player 2 wins.  
 */
int winner(const int field[SIZE_Y][SIZE_X])
{
	int count_p1 = 0;
	int count_p2 = 0;

	for (int j = 0; j < SIZE_Y; j++)
	{
		for (int i = 0; i < SIZE_X; i++)
		{
			//loop through all fields + counting of X (1) and O (2)
			if (field[j][i] == 1)
			{
				count_p1++;
			}
			else if (field[j][i] == 2)
			{
				count_p2++;
			}
		}
	}
	if (count_p1 == count_p2)				//draw
	{
		return 0;
	}
	if (count_p2 > count_p1)	//player 2 wins
	{
		return 2;
	}
	else					//player 1 wins
	{
		return 1;
	}
}

/*!
 * @fn	bool turn_valid(const int field[SIZE_Y][SIZE_X], const int player, const int pos_x, const int pos_y)
 *
 * @brief	This function checks the specified turn is valid.
 * 			
 * This function checks if the given position on the field is a valid position to put a tile for the given player.
 *
 * @param	field[SIZE_Y][SIZE_X]		The field.
 * @param	player		 	The player who is on turn.
 * @param	pos_x		 	The x coordinate of the turn needing to be checked.
 * @param	pos_y		 	The y coordinate of the turn needing to be checked.
 *
 * @return	True if the player is able to make a valid move, false if he isn't.
 */
bool turn_valid(const int field[SIZE_Y][SIZE_X], const int player, const int pos_x, const int pos_y)
{
	// Process all possible directions
	int opponent = 3 - player; // the same as: if player = 1 -> opponent = 2 else
							   // if player = 2 -> opponent = 1

	if (field[pos_y][pos_x] != 0) //check if field is currently empty
	{
		return false;
	}

	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			//check if you can find an opponents stone in a neighboring field
			//then check if in this direction all stones are opponent stones until
			//the line is terminated by one of your own stone
			//in that case return true otherwise not
			if(i == 0 &&  j == 0)
				continue;
			if (field[pos_y + i][pos_x + j] == opponent)
			{
				int currentX = pos_x + j, currentY = pos_y + i;
				while (field[currentY][currentX] != 0 && currentX >= 0 && currentX < SIZE_X && currentY < SIZE_Y && currentY >= 0)
				{
					if (field[currentY][currentX] == player)
						return true;
					currentX += j;
					currentY += i;
				}
			}
		}
	}
	return false;
}

/*!
* @fn	void execute_turn(int field[SIZE_Y][SIZE_X], const int player, const int pos_x, const int pos_y)
*
* @brief	Executes the specified turn.
*
* This function executes a valid turn by the specified player on the given field.
* It doesn't return anything but it modifies the passed array.
*
* @param	field[SIZE_Y][SIZE_X]	The field.
* @param	player		 			The player who is on turn. (either 1 or 2)
* @param	pos_x		  			The x-coordinate of the position chosen by the player.
* @param	pos_y					The y-coordinate of the position chosen by the player.
*/
void execute_turn(int field[SIZE_Y][SIZE_X], const int player, const int pos_x, const int pos_y)
{
	// very similar to function "turn_valid" - just take care that all opponent
	// stones are changed to yours
	 
	if (!turn_valid(field, player, pos_x, pos_y)) return;

	// Process all possible directions
	int opponent = 3 - player;	// the same as: if player = 1 -> opponent = 2
								//		   else if player = 2 -> opponent = 1
								
	//loop over all directions going out from current position
	for (int i = -1; i <= 1; i++)									//Y-direction		
	{
		for (int j = -1; j <= 1; j++)								//X-direction
		{
			if (i == 0 && j == 0)									//no direction, ignore case
				continue;
			if (field[pos_y + i][pos_x + j] == opponent)			//check if position is held by opponent
			{
				int currentX = pos_x + j, currentY = pos_y + i;		//initialize cursor: current<Y,X>
				
				//do while cursor is on the field and doesn't point to an empty location
				while (field[currentY][currentX] != 0 && currentX >= 0 && currentX < SIZE_X && currentY < SIZE_Y && currentY >= 0)
				{
					if (field[currentY][currentX] == player)			//if location is held by player
					{
						//replace all opponent's tiles between original turn position and first player's tile in the current direction
						currentX = pos_x + j;
						currentY = pos_y + i;
						while (field[currentY][currentX] == opponent)
						{
							field[currentY][currentX] = player;			//Change captured opponent's tiles to player's tiles  
							currentX += j;
							currentY += i;
						}
						break;
					}
					currentX += j;
					currentY += i;
				}
			}
		}
	}
	field[pos_y][pos_x] = player;
}

/*!
* @fn	int possible_turns(const int field[SIZE_Y][SIZE_X], const int player)
*
* @brief	Calculates the number of possible turns for the specified player on the given field.
*
* @param	field[SIZE_Y][SIZE_X]			The field.
* @param	player							The player who is on turn. (either 1 or 2)
*
* @return	The amount of possible, valid turns.
*/
int possible_turns(const int field[SIZE_Y][SIZE_X], const int player)
{
	int count = 0;
	//Loop over the the whole field
	for (int y = 0; y < SIZE_Y; y++)
	{
		for (int x = 0; x < SIZE_X; x++)
		{	
			//Increase counter if a valid turn is found
			if (turn_valid(field, player, x, y))
				count++;
		}
	}
	return count;
}

/*!
 * @fn	bool human_turn(int field[SIZE_Y][SIZE_X], const int player)
 *
 * @brief	This function lets the player specify his turn
 *
 * @param	field[SIZE_Y][SIZE_X]	The field.
 * @param	player		 			The player who is on turn. (either 1 or 2)
 *
 * @return	True if it succeeds, false if it fails.
 */
bool human_turn(int field[SIZE_Y][SIZE_X], const int player)
{
	if (possible_turns(field, player) == 0)
	{
		return false;
	}
	auto PL_SYMB = [](int player) { return player == 1 ? "X" : "O";  };					//return symbol for given player
	std::cout << std::endl << PL_SYMB(player) << " is on turn!" << std::endl;
	int px;
	int py;
	bool repeat=false;

	while (true)
	{
		std::string input;
		input.reserve(50);
		std::cout << std::endl << "Your move (e.g. A1): " ;
		input.erase(input.begin(), input.end());
		std::cin >> input;
		px = ((int) input.at(0) ) - 65;
		py = ((int) input.at(1) ) - 49;

		if (turn_valid(field, player, px, py))
		{
			//accept turn;
			break;
		}
		else
		{
			std::cout << std::endl << "Invalid input !" << std::endl;
		}
	}

	execute_turn(field, player, px, py);

	return true;
}

/*!
 * @fn	void game(const int player_typ[2])
 *
 * @brief	Runs the main game and prints out the winner.
 *
 * @param	player_typ	Determines the mode in which the game is (HUMAN vs HUMAN, HUMAN vs CPU, etc.).
 */
void game(const int player_typ[2])
{

	#ifdef MISS_TURN_DEMO
	int field[SIZE_Y][SIZE_X] = {	{ 0, 1, 1, 1, 1, 1, 1, 0 },
									{ 1, 2, 1, 1, 1, 1, 2, 1 },
									{ 1, 1, 1, 1, 1, 1, 1, 1 },
									{ 1, 1, 1, 1, 1, 1, 1, 1 },
									{ 1, 1, 1, 1, 1, 1, 1, 1 },
									{ 1, 1, 1, 1, 1, 1, 1, 1 },
									{ 1, 2, 1, 1, 1, 1, 2, 1 },
									{ 0, 1, 1, 1, 1, 1, 1, 0 },
	};
	#else
		int field[SIZE_Y][SIZE_X];
		//Create starting pattern
		initialize_field(field);
	#endif

	int current_player = 1;
	show_field(field);
	//let each player make its moves until no further moves are possible

	auto PL_SYMB = [](int player) { return player == 1 ? "X" : "O";  };					//return symbol for given player

	while (true)
	{
		//when false, the player passed the turn
		bool passed = player_typ[current_player - 1] == HUMAN ? !human_turn(field, current_player) : !computer_turn(field, current_player);
		if (passed)													//<human|computer>_turn returns false if no turn is possible
		{
			if (possible_turns(field, 3 - current_player) == 0)		//if the opponent is also not able to make a turn, the game ends
				break;
			else
			{
				std::cout << std::endl << PL_SYMB(current_player) << " is not able to make a valid turn so it's " << PL_SYMB(3 - current_player) << "'s turn again!" << std::endl << std::endl;
			}
		}
		current_player = 3 - current_player;
		show_field(field);
	}

	switch (winner(field))
	{
	case 1:
		std::cout << std::endl << "Player 1 (X) wins!" << std::endl;
		break;
	case 2:
		std::cout << std::endl << "Player 2 (O) wins!" << std::endl;
		break;
	case 0:
		std::cout << std::endl << "Draw!" << std::endl;
		break;
	default:
		std::cout <<std::endl << "FEHLER IN DER MATRIX!" << std::endl;
		break;
	}
}


/**
* @fn	int main(void)
*
* @brief	The main function and entrypoint for the program
*
*			The main function starts the tests, the initialization and the game 
*
* @return	1 if everything succeeds, something < 0 if an error occurs
*/
int main(void)
{
	if (TEST == 1)
	{
		bool result = run_full_test();
		if (result == true)
		{
			std::cout << "ALL TESTS PASSED!" << std::endl;
		}
		else
		{
			std::cout << "TEST FAILED!" << std::endl;
		}
	}


	//int player_type[2] = { HUMAN, COMPUTER };  //Contains information wether players are HUMAN(=1) or COPMUTER(=2)
	int player_type[2] = {0, 0};
	std::cout << "Enter gamemode: C = Computer & H = Human" << std::endl << "ie. \"H,C\" or \"human - C\" for Human vs Computer" << std::endl;
	
	/*
	 * Parse user input
	 * Just for fun, check many, many possible input patterns
	 * to determine the Game mode
	 */
	while (true)
	{
		char str[32];
		std::cin.getline(str, 32);
		std::string s(str);
		if (s[0] == 'H' || s[0] == 'h')
		{
			player_type[0] = HUMAN;
		} 
		else if(s[0] == 'C' || s[0] == 'c')
		{
			player_type[0] = COMPUTER;
		}
		if (s[s.length()-1] == 'H' || s[s.length() - 1] == 'h')
		{
			player_type[1] = HUMAN;
		}
		else if ((s[s.length() - 1] == 'N' || s[s.length() - 1] == 'n') && (s[s.length() - 5] == 'h' || s[s.length() - 5] == 'H'))
			player_type[1] = HUMAN;
		else if (s[s.length() - 1] == 'C' || s[s.length() - 1] == 'c')
		{
			player_type[1] = COMPUTER;
		}
		else if((s[s.length() - 1] == 'R' || s[s.length() - 1] == 'r') && (s[s.length()-8] == 'c' || s[s.length() - 8] == 'C'))
			player_type[1] = COMPUTER;
		if (player_type[0] * player_type[1] == 0)
			std::cout << "Invalid format! Please choose the gamemode:" << std::endl;
		else break;
	}
	std::string players[] = { "", "HUMAN", "COMPUTER" };
	std::cout << "You chose " << players[player_type[0]] + " vs " + players[player_type[1]] << "!" << std::endl << std::endl;

	int field[SIZE_Y][SIZE_X];

	initialize_field(field);

	show_field(field);
	
	game(player_type);
	
	std::getchar();
	std::getchar();
	return 0;
}
