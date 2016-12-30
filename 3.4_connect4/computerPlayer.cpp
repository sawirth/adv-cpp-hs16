#ifndef ADV_CPP_HS16_COMPUTERPLAYER_H
#define ADV_CPP_HS16_COMPUTERPLAYER_H

#include "player.cpp"
#include <chrono>
#include <thread>
#include <iostream>
#include <random>
#include <algorithm>
#include "connect4Utils.cpp"
#include "PlayerFactory.cpp"

using namespace std;

class computerPlayer : public player
{
	private:
		char myColor = ' ';
		char opponentColor = ' ';
		char none = playfield::none;
		char localField[playfield::width][playfield::height];
		const int width = playfield::width;
		const int height = playfield::height;
		vector<int> openColumns = vector<int>();

		void setStoneColor(const playfield &field)
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

	public:
		virtual int play(const playfield &field) override
		{
			//At the beginning the computer has to found out which color he is
			if (myColor == ' ')
			{
				setStoneColor(field);
			}

			//Make temp copy of field so we can manipulate it to found out which is the best move
			copyFieldToLocal(field);

			//find open columns
			findOpenColumns();

			//Start finding the best column to place the stone
			int column = findBestColumn(field);
			std::this_thread::sleep_for(std::chrono::milliseconds(250));
			cout << "Computer places stone in " << column + 1 << endl;
			return column;
		}

		static player *make()
		{
			return new computerPlayer();
		}

	private:
		void copyFieldToLocal(const playfield &field)
		{
			for (int column = 0; column < field.width; column++)
			{
				for (int row = 0; row < field.height; row++)
				{
					localField[column][row] = field.stoneat(column, row);
				}
			}
		}

		int findBestColumn(const playfield &field)
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
				//If we more than 4 possibilities we prefer not an edge column
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

		void findOpenColumns()
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

		//This method simulates a possible move for further calculations
		void tempPlay(int column, char stoneColor)
		{
			int row = 0;
			while(row < height && localField[column][row] == none)
			{
				row++;
			}

			localField[column][row - 1] = stoneColor;
		}

		//Removes the top most stone in the given column
		void undoMove(int column)
		{
			int row = 0;
			while (row < height && localField[column][row] == none)
			{
				row++;
			}

			localField[column][row] = none;
		}

		char hasWinner()
		{
			return connect4Utils<playfield>::checkForWin(localField);
		}
};

static PlayerFH<computerPlayer> registerComputerPlayer;

#endif //ADV_CPP_HS16_COMPUTERPLAYER_H