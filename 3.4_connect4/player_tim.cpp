#include "player_tim.hpp"

/**
 * Calls the player to make a play. 2 modes, on of them 0 is a bot, 1 is human interaction with the programm
 * @param field field of game played now
 * @return token the next row to set the stone in.
 */
int player_tim::play(const playfield &field)
{
	//Bot checks 2 possibilites and a fallback: can the bot win, can the player win
	//fallback: random number generation.
	int plnum = get_player_nr(field);
	int ennum = plnum == 1 ? 2 : 1;
	int cW = can_win(plnum, field);
	int cL = can_win(ennum, field);

	if (cW != -1)
	{
		if (doPrint)
		{
			std::cout << "4-chan: " << cW << std::endl;
		}

		return cW;
	}
	else if (cL != -1)
	{
		if (doPrint)
		{
			std::cout << "4-chan: " << cL << std::endl;
		}

		return cL;
	}
	//Random number, if there is no case met.
	int rngsus = distribution(generator);

	if (doPrint)
	{
		std::cout << "4-chan: " << rngsus << std::endl;
	}

	return rngsus;
}

/**
 * The bot checks the field, if there is a row, where a single token could win/lose the game.
 * @param player number of the token of the player
 * @param field the field on which the game runs.
 * @return value of next stone to set, if there is a win/loose situation
 */
int player_tim::can_win(int player, const playfield &field)
{
	for (int i = 0; i < playfield::width; i++)
	{
		int j = height_for_row(i, field);
		if (j >= 0 &&
			(recursive_can_win(player, i, j, 1, 1, field) + recursive_can_win(player, i, j, -1, -1, field) >= 3 ||
			 recursive_can_win(player, i, j, 1, 0, field) + recursive_can_win(player, i, j, -1, 0, field) >= 3 ||
			 recursive_can_win(player, i, j, -1, 1, field) + recursive_can_win(player, i, j, 1, -1, field) >= 3 ||
			 recursive_can_win(player, i, j, 0, 1, field) >= 3))
		{
			return i;
		}
	}
	return -1;
}

/**
 * Recursive function which calls itself, if there is the player symbol in a row,
 * it will return 0, as soon as it program hits a zero or another player number.
 * @param player number of the token of the player
 * @param x x-postion on the field from the last call
 * @param y y-postion on the field from the last call
 * @param x_dir direction which the algorithm should take to check next.
 * @param y_dir direction which the algorithm should take to check next.
 * @param field the field on which the game runs.
 * @return 0 if base case is reached, otherwise returns next iteration +1
 */
int player_tim::recursive_can_win(int player, int x, int y, int x_dir, int y_dir, const playfield &field)
{
	if (x + x_dir < playfield::width && y + y_dir < playfield::height &&
		x + x_dir >= 0 && y + y_dir >= 0)
	{
		if (field.stoneat(x + x_dir, y + y_dir) - 48 == player)
		{
			return recursive_can_win(player, x + x_dir, y + y_dir, x_dir, y_dir, field) + 1;
		}
	}
	return 0;
}


/**
 * Function will return the y position of the next empty spot in the given row.
 * @param x row x of the field.
 * @param field the field on which the game runs.
 * @return height of the next position
 */
int player_tim::height_for_row(int x, const playfield &field)
{
	int height = playfield::height - 1;
	int token = field.stoneat(x, height) - 48;
	while (token != 0 && height >= 0)
	{
		height -= 1;
		token = field.stoneat(x, height) - 48;
	}
	return height;
}

/**
 * This function will check which player the bot is. If the sum of numbers != 0 is even,
 * the bot is player 1, if it is odd, the bot is player 2.
 * @param field the field on which the game runs.
 * @return the player number.
 */
int player_tim::get_player_nr(const playfield &field)
{
	int cnt = 0;
	for (int i = 0; i < playfield::width; i++)
	{
		for (int j = 0; j < playfield::height; j++)
		{
			if (field.stoneat(i, j) - 48 != 0)
			{
				cnt++;
			}

		}
	}
	return (cnt % 2) + 1;
}
