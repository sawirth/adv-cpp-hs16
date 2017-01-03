#include "playfield.h"
#include <iostream>
//#include <rpc.h>
#include <vector>
#include "connect4Utils.cpp"

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
			int player = playfield::rep[column][row];
			cout << player;

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

int playfield::getWinner() const
{
	return winner;
}

void playfield::checkForWinner()
{
	winner = connect4Utils::checkForWin(rep);
	if (winner != none)
	{
		playfield::isRunning = false;
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

int playfield::getCurrentPlayerChar() const
{
	return currentPlayerChar;
}
