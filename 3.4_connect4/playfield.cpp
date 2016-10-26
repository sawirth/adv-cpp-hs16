#include "playfield.h"
#include <iostream>
#include <rpc.h>
#include <vector>

using namespace std;

bool playfield::placeStone(char player, int column)
{
	// If the top element in this column is already occupied by another stone, the stone cannot not be placed.
	if (playfield::rep[0][column] != playfield::none)
	{
		return false;
	}

	// Find empty position in column
	int i = 0;
	while (playfield::rep[i][column] == playfield::none && i < playfield::height)
	{
		i++;
	}

	playfield::rep[i - 1][column] = player;
	return true;
}

void playfield::printField()
{
	cout << endl;
	cout << "\t";
	for (int i = 1; i <= playfield::width; i++)
	{
		cout << i << "   ";
	}

	cout << endl;
	cout << "\t";
	for (int i = 1; i <= playfield::width ; i++)
	{
		cout << "- - ";
	}

	cout << endl;

	for (int row = 0; row < playfield::height; row++)
	{
		cout << "\t";
		for (int column = 0; column < playfield::width; column++)
		{
			char player = playfield::rep[row][column];
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			if (player == playfield::player1)
			{
				// 4 = red
				SetConsoleTextAttribute(hConsole, 4);
			}
			else if(player == playfield::player2)
			{
				// 6 = yellow
				SetConsoleTextAttribute(hConsole, 6);
			}
			cout << player;

			// Set back to white
			SetConsoleTextAttribute(hConsole, 15);

			if (column < playfield::width - 1)
			{
				cout << " | ";
			}
		}

		cout << endl;
	}

	cout << endl;
}

bool playfield::isColumnFull(int column)
{
	for (int row = 0; row < playfield::height; row++)
	{
		if (rep[row][column] == playfield::none)
		{
			return false;
		}
	}

	return true;
}

char playfield::getWinner() const
{
	return winner;
}

void playfield::checkForWinner()
{
	checkVertical();

	if(playfield::isRunning)
	{
		checkHorizontal();
	}

	if(playfield::isRunning)
	{
		checkLeftToBottomRight();
	}

	if(playfield::isRunning)
	{
		checkTopToBottomRight();
	}

	if(playfield::isRunning)
	{
		checkTopToBottomLeft();
	}

	if(playfield::isRunning)
	{
		checkRightToBottomLeft();
	}
}

void playfield::checkVertical()
{
	//Check each column
	for (int column = 0; column < playfield::width; column++)
	{
		int length = 1;
		int row = 0;
		char currentPlayer = rep[row][column];

		do
		{
			char nextPlayer = playfield::rep[row + 1][column];
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
			cout << "Vertical win" << endl;
			playfield::winner = currentPlayer;
			playfield::isRunning = false;
			return;
		}
	}
}

void playfield::checkHorizontal()
{
	//Check each row
	for (int row = 0; row < playfield::height; row++)
	{
		int length = 1;
		int column = 0;
		char currentPlayer = rep[row][column];

		do
		{
			char nextPlayer = playfield::rep[row][column + 1];
			if (nextPlayer == currentPlayer && currentPlayer != playfield::none )
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

			column++;
		} while(length < 4 && column < playfield::width - 1); //do not go to the last row

		if (length == 4)
		{
			cout << "Horizontal win" << endl;
			playfield::winner = currentPlayer;
			playfield::isRunning = false;
			return;
		}
	}
}

void playfield::checkLeftToBottomRight()
{
	//Not each row must be checked because not each diagonal has 4 fields but for better understanding each diagonal will be checked
	for (int row = 0; row < playfield::height; row++)
	{
		int length = 1;
		int column = 0;
		int tempRow = row;
		char currentPlayer = rep[tempRow][column];

		do {
			char nextPlayer = rep[tempRow + 1][column + 1];
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
			cout << "LeftToBottomRight win" << endl;
			playfield::winner = currentPlayer;
			playfield::isRunning = false;
			return;
		}
	}
}

void playfield::checkTopToBottomRight()
{
	//Not each column must be checked because not each diagonal has 4 fields but for better understanding each diagonal will be checked
	for (int column = 0; column < playfield::height; column++)
	{
		int length = 1;
		int row = 0;
		int tempColumn = column;
		char currentPlayer = rep[row][tempColumn];

		do {
			char nextPlayer = rep[row + 1][tempColumn + 1];
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
			cout << "TopToBottomRight win" << endl;
			playfield::winner = currentPlayer;
			playfield::isRunning = false;
			return;
		}
	}
}

void playfield::checkTopToBottomLeft()
{
	//Not each column must be checked because not each diagonal has 4 fields but for better understanding each diagonal will be checked
	for (int column = 1; column < playfield::width; column++)
	{
		int length = 1;
		int row = 0;
		int tempColumn = column;
		char currentPlayer = rep[row][tempColumn];
		do {
			char nextPlayer = rep[row + 1][tempColumn - 1];
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
			cout << "TopToBottomLeft win" << endl;
			playfield::winner = currentPlayer;
			playfield::isRunning = false;
			return;
		}
	}
}

void playfield::checkRightToBottomLeft()
{
	//Not each row must be checked because not each diagonal has 4 fields but for better understanding each diagonal will be checked
	for (int row = 0; row < playfield::height; row++)
	{
		int length = 1;
		int column = playfield::width - 1;
		int tempRow = row;
		char currentPlayer = rep[tempRow][column];

		do {
			char nextPlayer = rep[tempRow + 1][column - 1];
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
			cout << "RightToBottomLeft win" << endl;
			playfield::winner = currentPlayer;
			playfield::isRunning = false;
			return;
		}
	}
}

void playfield::initField()
{
	for (int row = 0; row < playfield::height; row++)
	{
		for (int column = 0; column < playfield::width; column++)
		{
			playfield::rep[row][column] = playfield::none;
		}
	}
}

bool playfield::isTie()
{
	for (int column = 0; column < playfield::width; column++)
	{
		if (!isColumnFull(column))
		{
			return false;
		}
	}

	playfield::winner = playfield::none;
	playfield::isRunning = false;
	return true;
}
