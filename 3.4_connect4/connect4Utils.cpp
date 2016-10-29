#ifndef ADV_CPP_HS16_CONNECT4UTILS_H
#define ADV_CPP_HS16_CONNECT4UTILS_H

template<typename F>
class connect4Utils
{
	public:
		static char checkForWin(char field[F::width][F::height])
		{
			char winner = F::none;
			winner = checkForHorizontalWin(field);
			if (winner == F::none)
			{
				winner = checkForVerticalWin(field);
			}

			if (winner == F::none)
			{
				winner = checkForDiagonalWin(field);
			}

			return winner;
		}

	private:
		static char checkForHorizontalWin(char field[F::width][F::height])
		{
			//Check each row
			for (int row = 0; row < F::height; row++) {
				int length = 1;
				int column = 0;
				char currentPlayer = field[column][row];

				do {
					char nextPlayer = field[column + 1][row];
					if (nextPlayer == currentPlayer && currentPlayer != F::none) {
						//If the next stone is from the same
						length++;
					} else {
						//Reset
						length = 1;
						currentPlayer = nextPlayer;
					}

					column++;
				} while (length < 4 && column < F::width - 1); //do not go to the last row

				if (length == 4) {
					return currentPlayer;
				}
			}

			return F::none;
		}

		static char checkForVerticalWin(char field[F::width][F::height])
		{
			//Check each column
			for (int column = 0; column < F::width; column++)
			{
				int length = 1;
				int row = 0;
				char currentPlayer = field[row][column];

				do
				{
					char nextPlayer = field[column][row + 1];
					if (nextPlayer == currentPlayer && currentPlayer != F::none)
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
				} while(length < 4 && row < F::height - 1); //do not go to the last row

				if (length == 4)
				{
					return currentPlayer;
				}
			}

			return F::none;
		}

		static char checkForDiagonalWin(char field[F::width][F::height])
		{
			char winner = checkForLeftToBottomRightWin(field);
			if (winner == F::none)
			{
				winner = checkForTopToBottomRightWin(field);
			}

			if (winner == F::none)
			{
				winner = checkForTopToBottomLeftWin(field);
			}

			if (winner == F::none)
			{
				winner = checkForRightToBottomLeftWin(field);
			}

			return winner;
		}

		static char checkForLeftToBottomRightWin(char field[F::width][F::height])
		{
			for (int row = 0; row < F::height; row++)
			{
				int length = 1;
				int column = 0;
				int tempRow = row;
				char currentPlayer = field[column][tempRow];

				do {
					char nextPlayer = field[column + 1][tempRow + 1];
					if (nextPlayer == currentPlayer && currentPlayer != F::none)
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
				} while (length < 4 && column < F::width - 1&& tempRow < F::height - 1);

				if (length == 4)
				{
					return currentPlayer;
				}
			}

			return F::none;
		}

		static char checkForTopToBottomRightWin(char field[F::width][F::height])
		{
			//Not each column must be checked because not each diagonal has 4 fields but for better understanding each diagonal will be checked
			for (int column = 0; column < F::width; column++)
			{
				int length = 1;
				int row = 0;
				int tempColumn = column;
				char currentPlayer = field[tempColumn][row];

				do {
					char nextPlayer = field[tempColumn + 1][row + 1];
					if (nextPlayer == currentPlayer && currentPlayer != F::none)
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
				} while (length < 4 && tempColumn < F::width - 1 && row < F::height - 1);

				if (length == 4)
				{
					return currentPlayer;
				}
			}

			return F::none;
		}

		static char checkForTopToBottomLeftWin(char field[F::width][F::height])
		{
			//Not each column must be checked because not each diagonal has 4 fields but for better understanding each diagonal will be checked
			for (int column = 1; column < F::width; column++)
			{
				int length = 1;
				int row = 0;
				int tempColumn = column;
				char currentPlayer = field[tempColumn][row];
				do {
					char nextPlayer = field[tempColumn - 1][row + 1];
					if (nextPlayer == currentPlayer && currentPlayer != F::none)
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
				} while (length < 4 && tempColumn > 0 && row < F::height - 1);

				if (length == 4)
				{
					return currentPlayer;
				}
			}

			return F::none;
		}

		static char checkForRightToBottomLeftWin(char field[F::width][F::height])
		{
			//Not each row must be checked because not each diagonal has 4 fields but for better understanding each diagonal will be checked
			for (int row = 0; row < F::height; row++)
			{
				int length = 1;
				int column = F::width - 1;
				int tempRow = row;
				char currentPlayer = field[column][tempRow];

				do {
					char nextPlayer = field[column - 1][tempRow + 1];
					if (nextPlayer == currentPlayer && currentPlayer != F::none)
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
				} while (length < 4 && column > 0 && tempRow < F::height - 1);

				if (length == 4)
				{
					return currentPlayer;
				}
			}

			return F::none;
		}

};


#endif //ADV_CPP_HS16_CONNECT4UTILS_H

