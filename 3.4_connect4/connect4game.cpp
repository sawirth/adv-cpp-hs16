#include "connect4game.h"
#include "playfield.h"
#include "../utils/inputUtils.h"
#include <iostream>
#include "humanPlayer.cpp"
#include "computerPlayer.cpp"

using namespace std;

void connect4game::startGame()
{
	cout << endl;
	cout << "Welcome to most advanced CONNECT4 game ever built!" << endl;
	cout << "The following game modes are available:" << endl;
	cout << "1 - Human vs. Human" << endl;
	cout << "2 - Human vs. Computer" << endl;
	cout << "3 - Computer vs. Computer" << endl;

	int mode = 0;
	do
	{
		cout << "Which mode do you want to play? ";
		mode = utils::inputUtils::getInt();
		if (mode < 1 || mode > 3)
		{
			cout << "Wrong number!" << endl;
		}
	} while (mode < 1 || mode > 3);

	switch(mode)
	{
		case 1:
			{
				humanPlayer<playfield> p1 = humanPlayer<playfield>();
				humanPlayer<playfield> p2 = humanPlayer<playfield>();
				startGame(p1, p2);
			}
			break;

		case 2:
			{
				humanPlayer<playfield> p1 = humanPlayer<playfield>();
				computerPlayer<playfield> p2 = computerPlayer<playfield>();
				startGame(p1, p2);
			}
			break;

		case 3:
			{
				computerPlayer<playfield> p1 = computerPlayer<playfield>();
				computerPlayer<playfield> p2 = computerPlayer<playfield>();
				startGame(p1, p2);
			}
			break;

		default:
			cout << "Something went wrong.. :S" << endl;
			break;
	}

	cout << "Thanks for playing :)" << endl;
}

void connect4game::startGame(player<playfield> &player1, player<playfield> &player2)
{
	playfield field = playfield();
	field.initField();
	field.isRunning = true;

	int currentPlayer = 1;
	while(field.isRunning)
	{
		field.printField();

		bool succesfulMove = false;
		while(!succesfulMove && !field.isTie())
		{
			int column;
			if (currentPlayer == 1)
			{
				column = player1.play(field);
			}
			else
			{
				column = player2.play(field);
			}

			if (column < 0 || column > 6)
			{
				cout << "Column " << column + 1 << " is not a possible choice!" << endl;
				continue;
			}

			if (field.isColumnFull(column))
			{
				cout << "Column is full please choose another" << endl;
				continue;
			}

			succesfulMove = field.placeStone(column);

			//Check for winner
			field.checkForWinner();

			if (currentPlayer == 1)
			{
				currentPlayer = 2;
			}
			else
			{
				currentPlayer = 1;
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
