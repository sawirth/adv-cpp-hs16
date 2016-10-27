#ifndef ADV_CPP_HS16_PLAYFIELD_H
#define ADV_CPP_HS16_PLAYFIELD_H

class playfield
{
	public:
		const static int width = 7;
		const static int height = 6;
		const static char none = ' ';
		const static char player1 = 'O';
		const static char player2 = 'X';
		bool isRunning;

	private:
		char winner;
		char currentPlayerChar = player1;
		void checkVertical();
		void checkHorizontal();
		void checkLeftToBottomRight();
		void checkTopToBottomRight();
		void checkTopToBottomLeft();
		void checkRightToBottomLeft();

	public:
		char rep[playfield::width][playfield::height];

	public:
		char stoneat(int x, int y) const
		{
			return rep[x][y];
		}

		//The player can choose in which column he wants to place the stone
		//Returns: true if successful, else false
		bool placeStone(int column);

		void printField();

		//Checks if a certain column is full. Only in non-full columns can stones be placed
		bool isColumnFull(int column);

		char getWinner() const;

		void checkForWinner();

		void initField();

		bool isTie();

		char getCurrentPlayerChar() const;
};

#endif //ADV_CPP_HS16_PLAYFIELD_H
