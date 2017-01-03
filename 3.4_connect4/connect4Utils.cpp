#ifndef ADV_CPP_HS16_CONNECT4UTILS_H
#define ADV_CPP_HS16_CONNECT4UTILS_H

#include "playfield.h"

class connect4Utils
{
	public:
		static int checkForWin(int field[playfield::width][playfield::height])
		{
			int winner = playfield::none;
			winner = checkForHorizontalWin(field);
			if (winner == playfield::none)
			{
				winner = checkForVerticalWin(field);
			}

			if (winner == playfield::none)
			{
				winner = checkForDiagonalWin(field);
			}

			return winner;
		}

	private:
		static int checkForHorizontalWin(int field[playfield::width][playfield::height])
		{
			//Check each row
			for (int row = 0; row < playfield::height; row++) {
				int length = 1;
				int column = 0;
				int currentPlayer = field[column][row];

				do {
					int nextPlayer = field[column + 1][row];
					if (nextPlayer == currentPlayer && currentPlayer != playfield::none) {
						//If the next stone is from the same
						length++;
					} else {
						//Reset
						length = 1;
						currentPlayer = nextPlayer;
					}

					column++;
				} while (length < 4 && column < playfield::width - 1); //do not go to the last row

				if (length == 4) {
					return currentPlayer;
				}
			}

			return playfield::none;
		}

		static int checkForVerticalWin(int field[playfield::width][playfield::height])
		{
			//Check each column
			for (int column = 0; column < playfield::width; column++)
			{
				int length = 1;
				int row = 0;
				int currentPlayer = field[row][column];

				do
				{
					int nextPlayer = field[column][row + 1];
					if (nextPlayer == currentPlayer && currentPlayer != playfield::none)
					{
						//If the next stone is from the same
						length++;
					}
					else
					{
						//Reset
						length = 1;
						currentPlayer = nextPlayer;
					}

					row++;
				} while(length < 4 && row < playfield::height - 1); //do not go to the last row

				if (length == 4)
				{
					return currentPlayer;
				}
			}

			return playfield::none;
		}

		static int checkForDiagonalWin(int field[playfield::width][playfield::height])
		{
			int winner = checkForLeftToBottomRightWin(field);
			if (winner == playfield::none)
			{
				winner = checkForTopToBottomRightWin(field);
			}

			if (winner == playfield::none)
			{
				winner = checkForTopToBottomLeftWin(field);
			}

			if (winner == playfield::none)
			{
				winner = checkForRightToBottomLeftWin(field);
			}

			return winner;
		}

		static int checkForLeftToBottomRightWin(int field[playfield::width][playfield::height])
		{
			for (int row = 0; row < playfield::height; row++)
			{
				int length = 1;
				int column = 0;
				int tempRow = row;
				int currentPlayer = field[column][tempRow];

				do {
					int nextPlayer = field[column + 1][tempRow + 1];
					if (nextPlayer == currentPlayer && currentPlayer != playfield::none)
					{
						length++;
					}
					else
					{
						length = 1;
						currentPlayer = nextPlayer;
					}

					tempRow++;
					column++;
				} while (length < 4 && column < playfield::width - 1&& tempRow < playfield::height - 1);

				if (length == 4)
				{
					return currentPlayer;
				}
			}

			return playfield::none;
		}

		static int checkForTopToBottomRightWin(int field[playfield::width][playfield::height])
		{
			//Not each column must be checked because not each diagonal has 4 fields but for better understanding each diagonal will be checked
			for (int column = 0; column < playfield::width; column++)
			{
				int length = 1;
				int row = 0;
				int tempColumn = column;
				int currentPlayer = field[tempColumn][row];

				do {
					int nextPlayer = field[tempColumn + 1][row + 1];
					if (nextPlayer == currentPlayer && currentPlayer != playfield::none)
					{
						length++;
					}
					else
					{
						length = 1;
						currentPlayer = nextPlayer;
					}

					row++;
					tempColumn++;
				} while (length < 4 && tempColumn < playfield::width - 1 && row < playfield::height - 1);

				if (length == 4)
				{
					return currentPlayer;
				}
			}

			return playfield::none;
		}

		static int checkForTopToBottomLeftWin(int field[playfield::width][playfield::height])
		{
			//Not each column must be checked because not each diagonal has 4 fields but for better understanding each diagonal will be checked
			for (int column = 1; column < playfield::width; column++)
			{
				int length = 1;
				int row = 0;
				int tempColumn = column;
				int currentPlayer = field[tempColumn][row];
				do {
					int nextPlayer = field[tempColumn - 1][row + 1];
					if (nextPlayer == currentPlayer && currentPlayer != playfield::none)
					{
						length++;
					}
					else
					{
						length = 1;
						currentPlayer = nextPlayer;
					}

					row++;
					tempColumn--;
				} while (length < 4 && tempColumn > 0 && row < playfield::height - 1);

				if (length == 4)
				{
					return currentPlayer;
				}
			}

			return playfield::none;
		}

		static int checkForRightToBottomLeftWin(int field[playfield::width][playfield::height])
		{
			//Not each row must be checked because not each diagonal has 4 fields but for better understanding each diagonal will be checked
			for (int row = 0; row < playfield::height; row++)
			{
				int length = 1;
				int column = playfield::width - 1;
				int tempRow = row;
				int currentPlayer = field[column][tempRow];

				do {
					int nextPlayer = field[column - 1][tempRow + 1];
					if (nextPlayer == currentPlayer && currentPlayer != playfield::none)
					{
						length++;
					}
					else
					{
						length = 1;
						currentPlayer = nextPlayer;
					}

					tempRow++;
					column--;
				} while (length < 4 && column > 0 && tempRow < playfield::height - 1);

				if (length == 4)
				{
					return currentPlayer;
				}
			}

			return playfield::none;
		}

};


#endif //ADV_CPP_HS16_CONNECT4UTILS_H

