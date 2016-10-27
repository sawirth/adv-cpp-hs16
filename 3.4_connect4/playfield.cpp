#include "playfield.h"
#include <iostream>
//#include <rpc.h>
#include <vector>

using namespace std;

bool playfield::placeStone(int column)
{
	// If the top element in this column is already occupied by another stone, the stone cannot not be placed.
	if (playfield::rep[column][0] != playfield::none)
	{
		return false;
	}

	// Find empty position in column
	int i = 0;
	while (playfield::rep[column][i] == playfield::none && i < playfield::height)
	{
		i++;
	}

	playfield::rep[column][i - 1] = currentPlayerChar;

	//Switch the symbol of the current player so the player doesn't have to worry about this
	if (currentPlayerChar == player1)
	{
		currentPlayerChar = player2;
	}
	else
	{
		currentPlayerChar = player1;
	}

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
			char player = playfield::rep[column][row];
			//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			/*if (player == playfield::player1)
			{
				// 4 = red
				SetConsoleTextAttribute(hConsole, 4);
			}
			else if(player == playfield::player2)
			{
				// 6 = yellow
				SetConsoleTextAttribute(hConsole, 6);
			}*/
			cout << player;

			// Set back to white
			//SetConsoleTextAttribute(hConsole, 15);

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
		if (rep[column][row] == playfield::none)
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
			char nextPlayer = playfield::rep[column][row + 1];
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
		char currentPlayer = rep[column][row];

		do
		{
			char nextPlayer = playfield::rep[column + 1][row];
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
		char currentPlayer = rep[column][tempRow];

		do {
			char nextPlayer = rep[column + 1][tempRow + 1];
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
	for (int column = 0; column < playfield::width; column++)
	{
		int length = 1;
		int row = 0;
		int tempColumn = column;
		char currentPlayer = rep[tempColumn][row];

		do {
			char nextPlayer = rep[tempColumn + 1][row + 1];
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
		char currentPlayer = rep[tempColumn][row];
		do {
			char nextPlayer = rep[tempColumn - 1][row + 1];
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
		char currentPlayer = rep[column][tempRow];

		do {
			char nextPlayer = rep[column - 1][tempRow + 1];
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
			playfield::rep[column][row] = playfield::none;
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

char playfield::getCurrentPlayerChar() const
{
	return currentPlayerChar;
}
