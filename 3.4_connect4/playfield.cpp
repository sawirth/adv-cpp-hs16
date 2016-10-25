#include "playfield.h"
#include <iostream>
#include <rpc.h>

using namespace std;

bool playfield::placeStone(int player, int column)
{
	// If the top element in this column is already occupied by another stone, the stone cannot not be placed.
	if (playfield::rep[0][column] != 0)
	{
		return false;
	}

	// Find empty position in column
	int i = 0;
	while (playfield::rep[i][column] == 0 && i < playfield::height)
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
			int player = playfield::rep[row][column];
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			if (player == 1)
			{
				// 4 = red
				SetConsoleTextAttribute(hConsole, 4);
			}
			else if(player == 2)
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
		if (rep[row][column] == 0)
		{
			return false;
		}
	}

	return true;
}

int playfield::getWinner() const
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
		int currentPlayer = rep[row][column];

		do
		{
			int nextPlayer = playfield::rep[row + 1][column];
			if (nextPlayer == currentPlayer && currentPlayer != 0)
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
		int currentPlayer = rep[row][column];

		do
		{
			int nextPlayer = playfield::rep[row][column + 1];
			if (nextPlayer == currentPlayer && currentPlayer != 0 )
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
		int currentPlayer = rep[tempRow][column];

		do {
			int nextPlayer = rep[tempRow + 1][column + 1];
			if (nextPlayer == currentPlayer && currentPlayer != 0)
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
		} while (length < 4 && column < playfield::width && tempRow < playfield::height);

		if (length == 4)
		{
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
		int currentPlayer = rep[row][tempColumn];

		do {
			int nextPlayer = rep[row + 1][tempColumn + 1];
			if (nextPlayer == currentPlayer && currentPlayer != 0)
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
		} while (length < 4 && tempColumn < playfield::width && row < playfield::height);

		if (length == 4)
		{
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
		int currentPlayer = rep[row][tempColumn];
		do {
			int nextPlayer = rep[row + 1][tempColumn - 1];
			if (nextPlayer == currentPlayer && currentPlayer != 0)
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
		} while (length < 4 && tempColumn > 0 && row < playfield::height);

		if (length == 4)
		{
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
		int currentPlayer = rep[tempRow][column];

		do {
			int nextPlayer = rep[tempRow + 1][column - 1];
			if (nextPlayer == currentPlayer && currentPlayer != 0)
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
		} while (length < 4 && column > 0 && tempRow < playfield::height);

		if (length == 4)
		{
			playfield::winner = currentPlayer;
			playfield::isRunning = false;
			return;
		}
	}
}
