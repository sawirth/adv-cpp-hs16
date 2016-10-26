#include "connect4game.h"
#include "playfield.h"
#include "../utils/inputUtils.h"
#include <iostream>

using namespace std;

void connect4game::startGame()
{
	cout << endl;
	cout << "Welcome to most advanced CONNECT4 game ever built!" << endl;

	playfield field = playfield();
	field.initField();
	field.isRunning = true;

	char currentPlayer = field.player1;
	while(field.isRunning)
	{
		field.printField();

		bool succesfulMove = false;
		while(!succesfulMove && !field.isTie())
		{
			//For better understanding we ask for 1 to 7 instead of 0 to 6 and then subtract 1 to get the proper value
			cout << "Player " << currentPlayer << ": In which column you want to place your stone? 1 to 7: ";
			int column = utils::inputUtils::getInt() - 1;

			if (column < 0 || column > 6)
			{
				cout << "Column " << column << " is not a possible choice!" << endl;
				continue;
			}

			if (field.isColumnFull(column))
			{
				cout << "Column is full please choose another" << endl;
				continue;
			}

			succesfulMove = field.placeStone(currentPlayer, column);

			//Check for winner
			field.checkForWinner();

			if (currentPlayer == field.player1)
			{
				currentPlayer = field.player2;
			}
			else
			{
				currentPlayer = field.player1;
			}
		}
	}

	field.printField();
	char winner = field.getWinner();

	if (winner == field.none)
	{
		cout << "The game ended with a tie" << endl;
	}
	else
	{
		cout << "Player " << winner << " has won!" << endl;
	}
}
