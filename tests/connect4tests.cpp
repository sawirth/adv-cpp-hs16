#ifndef ADV_CPP_HS16_CONNECT4TESTS_H
#define ADV_CPP_HS16_CONNECT4TESTS_H

#include <assert.h>
#include "../3.4_connect4/playfield.h"

class connect4tests
{
	public:
		void runTests()
		{
			verticalWinTest();
			horizontalWinTest();
			LeftToBottomRightWinTest();
			TopToBottomRightWinTest();
			TopToBottomLeftWinTest();
			RightToBottomLeftWinTest();
			TieTest();
		}

	private:
		void verticalWinTest()
		{
			playfield game = playfield();
			game.initField();
			game.isRunning = true;

			for (int i = 0; i < 3; i++)
			{
				game.placeStone(0);
				game.placeStone(1);
			}

			game.checkForWinner();
			assert(game.isRunning);

			game.placeStone(0);
			game.checkForWinner();
			assert(!game.isRunning);
		}

		void horizontalWinTest()
		{
			playfield game = playfield();
			game.initField();
			game.isRunning = true;
			game.placeStone(0);
			game.placeStone(0);
			game.placeStone(1);
			game.placeStone(1);
			game.placeStone(2);
			game.placeStone(2);
			game.checkForWinner();
			assert(game.isRunning);
			game.placeStone(3);
			game.checkForWinner();
			assert(!game.isRunning);
		}

		void LeftToBottomRightWinTest()
		{
			playfield game = playfield();
			game.initField();
			game.isRunning = true;

			game.placeStone(0);
			game.placeStone(0);
			game.placeStone(0);
			game.placeStone(0);

			game.placeStone(1);
			game.placeStone(1);
			game.placeStone(6);
			game.placeStone(1);

			game.placeStone(2);
			game.placeStone(2);
			game.checkForWinner();
			assert(game.isRunning);

			game.placeStone(6);
			game.placeStone(3);
			game.checkForWinner();
			assert(!game.isRunning);
		}

		void TopToBottomRightWinTest()
		{
			playfield game = playfield();
			game.initField();
			game.isRunning = true;

			game.placeStone(3);
			game.placeStone(3);
			game.placeStone(3);
			game.placeStone(3);

			game.placeStone(4);
			game.placeStone(4);
			game.placeStone(1);
			game.placeStone(4);

			game.placeStone(5);
			game.placeStone(5);
			game.checkForWinner();
			assert(game.isRunning);

			game.placeStone(1);
			game.placeStone(6);
			game.checkForWinner();
			assert(!game.isRunning);
		}

		void TopToBottomLeftWinTest()
		{
			playfield game = playfield();
			game.initField();
			game.isRunning = true;

			game.placeStone(3);
			game.placeStone(3);
			game.placeStone(3);
			game.placeStone(3);

			game.placeStone(2);
			game.placeStone(2);
			game.placeStone(3);
			game.placeStone(2);

			game.placeStone(1);
			game.placeStone(1);
			game.checkForWinner();
			assert(game.isRunning);

			game.placeStone(3);
			game.placeStone(0);
			game.checkForWinner();
			assert(!game.isRunning);
		}

		void RightToBottomLeftWinTest()
		{
			playfield game = playfield();
			game.initField();
			game.isRunning = true;

			game.placeStone(6);
			game.placeStone(6);
			game.placeStone(6);
			game.placeStone(6);

			game.placeStone(5);
			game.placeStone(5);
			game.placeStone(0);
			game.placeStone(5);

			game.placeStone(4);
			game.placeStone(4);
			game.checkForWinner();
			assert(game.isRunning);

			game.placeStone(0);
			game.placeStone(3);
			game.checkForWinner();
			assert(!game.isRunning);
		}

		void TieTest()
		{
			playfield game = playfield();
			game.initField();
			game.isRunning = true;

			game.placeStone(0);
			game.placeStone(0);
			game.placeStone(0);
			game.placeStone(0);
			game.placeStone(0);
			game.placeStone(0);

			game.placeStone(1);
			game.placeStone(1);
			game.placeStone(1);
			game.placeStone(1);
			game.placeStone(1);
			game.placeStone(1);

			game.placeStone(2);
			game.placeStone(2);
			game.placeStone(2);
			game.placeStone(2);
			game.placeStone(2);
			game.placeStone(2);

			game.placeStone(3);
			game.placeStone(3);
			game.placeStone(3);
			game.placeStone(3);
			game.placeStone(3);
			game.placeStone(3);

			game.placeStone(4);
			game.placeStone(4);
			game.placeStone(4);
			game.placeStone(4);
			game.placeStone(4);
			game.placeStone(4);

			game.placeStone(4);
			game.placeStone(4);
			game.placeStone(4);
			game.placeStone(4);
			game.placeStone(4);
			game.placeStone(4);

			game.placeStone(5);
			game.placeStone(5);
			game.placeStone(5);
			game.placeStone(5);
			game.placeStone(5);
			game.placeStone(5);

			game.placeStone(6);
			game.placeStone(6);
			game.placeStone(6);
			game.placeStone(6);
			game.placeStone(6);
			assert(game.isRunning);

			game.placeStone(6);

			assert(game.isTie());
			assert(!game.isRunning);
		}
};


#endif //ADV_CPP_HS16_CONNECT4TESTS_H

