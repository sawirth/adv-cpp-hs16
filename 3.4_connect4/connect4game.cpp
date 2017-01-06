#include "connect4game.h"
#include "../utils/inputUtils.h"
#include "player_tim.hpp"

using namespace std;

void connect4game::startGame()
{
	cout << endl;
	cout << "Welcome to most advanced CONNECT4 game ever built!" << endl;
	cout << "The following game modes are available:" << endl;
	cout << "1 - Human vs. Human" << endl;
	cout << "2 - Human vs. Computer" << endl;
	cout << "3 - Computer vs. Computer" << endl;
	cout << "4 - Human vs. Nico AI" << endl;
	cout << "5 - Computer vs Nico AI" << endl;
	cout << "6 - AI Benchmarking Nico" << endl;
	cout << "7 - Human vs. Computer with threads" << endl;
	cout << "8 - Human vs. Tim AI" << endl;
	cout << "9 - Computer vs. Tim AI" << endl;
	cout << "10 - AI Benchmarking Tim" << endl;

	int mode = 0;
	do
	{
		cout << "Which mode do you want to play? ";
		mode = utils::inputUtils::getInt();
		if (mode < 1 || mode > 10)
		{
			cout << "Wrong number!" << endl;
		}
	} while (mode < 1 || mode > 10);

	player *p1;
	player *p2;

	switch (mode)
	{
		case 1:
			p1 = PlayerFactory::make("human");
			p2 = PlayerFactory::make("human");
			startGame(p1, p2);
			break;

		case 2:
			p1 = PlayerFactory::make("human");
			p2 = PlayerFactory::make("ai");
			startGame(p1, p2);
			break;

		case 3:
			p1 = PlayerFactory::make("ai");
			p2 = PlayerFactory::make("ai");
			startGame(p1, p2);
			break;

		case 4:
			p1 = PlayerFactory::make("human");
			p2 = PlayerFactory::make("N(2)");
			startGame(p1, p2);
			break;

		case 5:
			p1 = PlayerFactory::make("ai");
			p2 = PlayerFactory::make("N(2)");
			startGame(p1, p2);
			break;

		case 6:
			p1 = PlayerFactory::make("ai_np");
			p2 = PlayerFactory::make("N(2)");
			runBenchmarking(p1, p2);
			break;

		case 7:
			p1 = PlayerFactory::make("ai");
			p2 = PlayerFactory::make("thread");
			startGame(p1, p2);
			break;

		case 8:
			p1 = PlayerFactory::make("human");
			p2 = new player_tim();
			startGame(p1, p2);
			break;

		case 9:
			p1 = PlayerFactory::make("ai");
			p2 = new player_tim();
			startGame(p1, p2);
			break;

		case 10:
			p1 = PlayerFactory::make("ai_np");
			p2 = new player_tim(false);
			runBenchmarking(p1, p2);
			break;

		default:
			cout << "Something went wrong.. :S" << endl;
			break;
	}

	cout << "Thanks for playing :)" << endl;
	delete p1;
	delete p2;
}

int connect4game::startGame(player *player1, player *player2, bool doPrintField)
{
	playfield field = playfield();
	field.initField();
	field.isRunning = true;

	int currentPlayer = 1;
	while (field.isRunning)
	{
		if (doPrintField)
		{
			field.printField();
		}

		bool succesfulMove = false;
		while (!succesfulMove && !field.isTie())
		{
			int column;
			if (currentPlayer == 1)
			{
				column = player1->play(field);
			}
			else
			{
				column = player2->play(field);
			}

			if ((column < 0 || column > 6) && doPrintField)
			{
				cout << "Column " << column + 1 << " is not a possible choice!" << endl;
				continue;
			}

			if (field.isColumnFull(column) && doPrintField)
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

	if (doPrintField)
	{
		field.printField();
	}

	int winner = field.getWinner();

	if (winner == field.none && doPrintField)
	{
		cout << "The game ended with a tie" << endl;
	}
	else if (doPrintField)
	{
		cout << "Player " << winner << " has won!" << endl;
	}

	return winner;
}

void connect4game::runBenchmarking(player *p1, player *p2)
{
	cout << "P1 = Our AI" << endl;
	cout << "P2 = Other AI" << endl;

	int remainingGames = 5000;
	double totalGames = (double) remainingGames;
	cout << "Simulating " << remainingGames << " games" << endl;

	int p1Wins = 0;
	int p2Wins = 0;
	int ties = 0;
	int errors = 0;

	while (remainingGames > 0)
	{
		auto winner = startGame(p1, p2, false);

		switch (winner)
		{
			case 0:
				ties++;
				break;

			case 1:
				p1Wins++;
				break;

			case 2:
				p2Wins++;
				break;

			default:
				errors++;
				break;
		}

		remainingGames--;
	}

	double p1WinPercentage = p1Wins / totalGames * 100;
	double p2WinPercentage = p2Wins / totalGames * 100;
	double tiePercentage = ties / totalGames * 100;

	cout << "== RESULTS ==" << endl;
	cout << "P1 has won " << p1WinPercentage << "% of the games " << "(" << p1Wins << " out of " << totalGames << ")"
		 << endl;
	cout << "P2 has won " << p2WinPercentage << "% of the games " << "(" << p2Wins << " out of " << totalGames << ")"
		 << endl;
	cout << tiePercentage << "% ended with a tie (" << ties << " out of " << totalGames << ")" << endl;
}
