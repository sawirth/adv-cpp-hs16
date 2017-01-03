#ifndef ADV_CPP_HS16_PLAYFIELD_H
#define ADV_CPP_HS16_PLAYFIELD_H

class playfield
{
	public:
		const static int width = 7;
		const static int height = 6;
		const static int none = 0;
		const static int player1 = 1;
		const static int player2 = 2;
		bool isRunning;

	private:
		int winner;
		int currentPlayerChar = player1;

	public:
		int rep[playfield::width][playfield::height];

	public:
		int stoneat(int x, int y) const
		{
			return rep[x][y];
		}

		//The player can choose in which column he wants to place the stone
		//Returns: true if successful, else false
		bool placeStone(int column);

		void printField();

		//Checks if a certain column is full. Only in non-full columns can stones be placed
		bool isColumnFull(int column);

		int getWinner() const;

		void checkForWinner();

		void initField();

		bool isTie();

		int getCurrentPlayerChar() const;
};

#endif //ADV_CPP_HS16_PLAYFIELD_H
