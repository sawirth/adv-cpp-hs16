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
				game.placeStone('X', 0);
			}

			game.checkForWinner();
			assert(game.isRunning);

			game.placeStone('X', 0);
			game.checkForWinner();
			assert(!game.isRunning);
		}

		void horizontalWinTest()
		{
			playfield game = playfield();
			game.initField();
			game.isRunning = true;
			game.placeStone(game.player1, 0);
			game.placeStone(game.player1, 1);
			game.placeStone(game.player1, 2);
			game.checkForWinner();
			assert(game.isRunning);
			game.placeStone(game.player1, 3);
			game.checkForWinner();
			assert(!game.isRunning);
		}

		void LeftToBottomRightWinTest()
		{
			playfield game = playfield();
			game.initField();
			game.isRunning = true;

			game.placeStone(game.player1, 0);
			game.placeStone(game.player1, 0);
			game.placeStone(game.player1, 0);
			game.placeStone(game.player2, 0);

			game.placeStone(game.player1, 1);
			game.placeStone(game.player1, 1);
			game.placeStone(game.player2, 1);

			game.placeStone(game.player1, 2);
			game.placeStone(game.player2, 2);
			game.checkForWinner();
			assert(game.isRunning);

			game.placeStone(game.player2, 3);
			game.checkForWinner();
			assert(!game.isRunning);
		}

		void TopToBottomRightWinTest()
		{
			playfield game = playfield();
			game.initField();
			game.isRunning = true;

			game.placeStone(game.player1, 3);
			game.placeStone(game.player1, 3);
			game.placeStone(game.player1, 3);
			game.placeStone(game.player2, 3);

			game.placeStone(game.player1, 4);
			game.placeStone(game.player1, 4);
			game.placeStone(game.player2, 4);

			game.placeStone(game.player1, 5);
			game.placeStone(game.player2, 5);
			game.checkForWinner();
			assert(game.isRunning);

			game.placeStone(game.player2, 6);
			game.checkForWinner();
			assert(!game.isRunning);
		}

		void TopToBottomLeftWinTest()
		{
			playfield game = playfield();
			game.initField();
			game.isRunning = true;

			game.placeStone(game.player1, 3);
			game.placeStone(game.player1, 3);
			game.placeStone(game.player1, 3);
			game.placeStone(game.player2, 3);

			game.placeStone(game.player1, 2);
			game.placeStone(game.player1, 2);
			game.placeStone(game.player2, 2);

			game.placeStone(game.player1, 1);
			game.placeStone(game.player2, 1);
			game.checkForWinner();
			assert(game.isRunning);

			game.placeStone(game.player2, 0);
			game.checkForWinner();
			assert(!game.isRunning);
		}

		void RightToBottomLeftWinTest()
		{
			playfield game = playfield();
			game.initField();
			game.isRunning = true;

			game.placeStone(game.player1, 6);
			game.placeStone(game.player1, 6);
			game.placeStone(game.player1, 6);
			game.placeStone(game.player2, 6);

			game.placeStone(game.player1, 5);
			game.placeStone(game.player1, 5);
			game.placeStone(game.player2, 5);

			game.placeStone(game.player1, 4);
			game.placeStone(game.player2, 4);
			game.checkForWinner();
			assert(game.isRunning);

			game.placeStone(game.player2, 3);
			game.checkForWinner();
			assert(!game.isRunning);
		}

		void TieTest()
		{
			playfield game = playfield();
			game.initField();
			game.isRunning = true;

			game.placeStone(playfield::player1, 0);
			game.placeStone(playfield::player2, 0);
			game.placeStone(playfield::player1, 0);
			game.placeStone(playfield::player2, 0);
			game.placeStone(playfield::player1, 0);
			game.placeStone(playfield::player2, 0);

			game.placeStone(playfield::player2, 1);
			game.placeStone(playfield::player1, 1);
			game.placeStone(playfield::player2, 1);
			game.placeStone(playfield::player1, 1);
			game.placeStone(playfield::player2, 1);
			game.placeStone(playfield::player1, 1);

			game.placeStone(playfield::player1, 2);
			game.placeStone(playfield::player2, 2);
			game.placeStone(playfield::player1, 2);
			game.placeStone(playfield::player2, 2);
			game.placeStone(playfield::player1, 2);
			game.placeStone(playfield::player2, 2);

			game.placeStone(playfield::player1, 3);
			game.placeStone(playfield::player2, 3);
			game.placeStone(playfield::player1, 3);
			game.placeStone(playfield::player2, 3);
			game.placeStone(playfield::player1, 3);
			game.placeStone(playfield::player2, 3);

			game.placeStone(playfield::player1, 4);
			game.placeStone(playfield::player2, 4);
			game.placeStone(playfield::player2, 4);
			game.placeStone(playfield::player1, 4);
			game.placeStone(playfield::player1, 4);
			game.placeStone(playfield::player2, 4);

			game.placeStone(playfield::player1, 4);
			game.placeStone(playfield::player2, 4);
			game.placeStone(playfield::player2, 4);
			game.placeStone(playfield::player1, 4);
			game.placeStone(playfield::player1, 4);
			game.placeStone(playfield::player2, 4);

			game.placeStone(playfield::player2, 5);
			game.placeStone(playfield::player1, 5);
			game.placeStone(playfield::player2, 5);
			game.placeStone(playfield::player1, 5);
			game.placeStone(playfield::player2, 5);
			game.placeStone(playfield::player1, 5);

			game.placeStone(playfield::player1, 6);
			game.placeStone(playfield::player2, 6);
			game.placeStone(playfield::player1, 6);
			game.placeStone(playfield::player2, 6);
			game.placeStone(playfield::player1, 6);
			assert(game.isRunning);

			game.placeStone(playfield::player2, 6);

			assert(game.isTie());
			assert(!game.isRunning);
		}
};


#endif //ADV_CPP_HS16_CONNECT4TESTS_H

