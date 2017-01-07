#include "threadAI.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <cstring>
#include "connect4Utils.cpp"

using namespace std;

void threadAI::setStoneColor(const playfield &field)
{
	//Since this method is called in the first round, its enough if we check the bottom row
	for (int column = 0; column < field.width; column++)
	{
		//If we found a stone in the bottom row, the computer is player 2
		if (field.stoneat(column, field.height - 1) != field.none)
		{
			myColor = field.player2;
			opponentColor = field.player1;
			return;
		}
	}

	//Otherwise he is player 1
	myColor = field.player1;
	opponentColor = field.player2;
}

void threadAI::copyFieldToLocal(const playfield &field)
{
	for (int column = 0; column < field.width; column++)
	{
		for (int row = 0; row < field.height; row++)
		{
			localField[column][row] = field.stoneat(column, row);
		}
	}
}

int threadAI::findBestColumn()
{
	vector<int> possibleColumns = vector<int>();

	for (unsigned int i = 0; i < openColumns.size(); i++)
	{
		//Play a temporary move in this column
		int column = openColumns.at(i);
		tempPlay(column, myColor);

		//Check if we can win with that move
		if (hasWinner() == myColor)
		{
			return column;
		}

		//If we cannot win we have to check if the opponent is then able to win because if he can win after our
		//move, the column is not a good choice
		findOpenColumns();
		bool opponentCanWin = false;
		for (unsigned int j = 0; j < openColumns.size(); j++)
		{
			int opponentColumn = openColumns.at(j);
			tempPlay(opponentColumn, opponentColor);
			if (hasWinner() == opponentColor)
			{
				opponentCanWin = true;
			}

			//We have to undo the move so we can make the next temporary move
			undoMove(opponentColumn);
		}

		//If the opponent cannot win after our move we can add the column to the possible choices
		if (!opponentCanWin && find(possibleColumns.begin(), possibleColumns.end(), column) == possibleColumns.end())
		{
			possibleColumns.push_back(column);
		}

		//We have to undo the move so we can make the next temporary move
		undoMove(column);
	}

	random_shuffle(possibleColumns.begin(), possibleColumns.end());

	if (possibleColumns.empty())
	{
		//If we have no opportunity left we lost and just play the first open column
		return openColumns.at(0);
	}
	else if (possibleColumns.size() > 4)
	{
		for (auto column : possibleColumns)
		{
			if (column > 1 && column < 5)
			{
				return column;
			}
		}

		for (auto column : possibleColumns)
		{
			if (column > 0 && column < 6)
			{
				return column;
			}
		}
	}
	else
	{
		return possibleColumns.at(0);
	}
	return 0;
}

void threadAI::findOpenColumns()
{
	openColumns.clear();
	for (int column = 0; column < width; column++)
	{
		if (localField[column][0] == none)
		{
			openColumns.push_back(column);
		}
	}
}

void threadAI::tempPlay(int column, int stoneColor)
{
	int row = 0;
	while(row < height && localField[column][row] == none)
	{
		row++;
	}

	localField[column][row - 1] = stoneColor;
}

void threadAI::undoMove(int column)
{
	int row = 0;
	while (row < height && localField[column][row] == none)
	{
		row++;
	}

	localField[column][row] = none;
}

int threadAI::hasWinner()
{
	return connect4Utils::checkForWin(localField);
}

void threadAI::calculateBestMoveIfOpponentPlays(int column)
{
	threadAI::mtx.lock();
	tempPlay(column, opponentColor);
	findOpenColumns();
	int myColumn = findBestColumn();

	nextMoves.insert(pair<int, int>(column, myColumn));
	undoMove(myColumn);
	undoMove(column);
	threadAI::mtx.unlock();
}

int threadAI::play(const playfield &field)
{
	//At the beginning the computer has to found out which color he is
	if (myColor == 0)
	{
		setStoneColor(field);
	}

	//Wait for all threads to finish
	for (unsigned int i = 0; i < threads.size(); ++i)
	{
		threads.at(i).join();
	}

	//Find column where opponent has placed stone
	int opponentPlayedColumn = findChangedColumn(field);

	//Make temp copy of field so we can manipulate it to found out which is the best move
	copyFieldToLocal(field);

	//find open columns
	findOpenColumns();

	//Start finding the best column to place the stone
	int column = 0;
	if (nextMoves.empty())
	{
		//In the first round there aren't any precalculated moves so we have to calculate it
		column = findBestColumn();
	}
	else
	{
		column = nextMoves.at(opponentPlayedColumn);
	}

	std::this_thread::sleep_for(std::chrono::milliseconds(sleeptime));

	if (doPrint)
	{
		cout << "Computer places stone in " << column + 1 << endl;
	}

	tempPlay(column, myColor);
	findOpenColumns();

	//Start threads for calculating best moves
	threads.clear();
	nextMoves.clear();
	for (auto openCol : openColumns)
	{
		thread t(calculateBestMoveIfOpponentPlays, this, openCol);
		threads.push_back(move(t));
	}

	return column;
}

int threadAI::findChangedColumn(const playfield &field)
{
	for (int column = 0; column < field.width; column++)
	{
		for (int row = 0; row < field.height; row++)
		{
			if (localField[column][row] != field.stoneat(column, row))
			{
				return column;
			}
		}
	}
}

player *threadAI::make(const char *player)
{
	int rc = strcmp(player, "thread");
	if (rc == 0)
	{
		return new threadAI();
	}

	return nullptr;
}

threadAI::~threadAI()
{
	for (unsigned int i = 0; i < threads.size(); i++)
	{
		threads.at(i).join();
	}
}

std::mutex threadAI::mtx;
