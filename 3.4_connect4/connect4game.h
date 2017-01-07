#ifndef ADV_CPP_HS16_CONNECT4GAME_H
#define ADV_CPP_HS16_CONNECT4GAME_H

#include "player.h"
#include "playfield.h"
#include <iostream>


struct winnerResult
{
	int playerColor, amountOfMoves;
	winnerResult(int playerColor, int amountOfMoves) : playerColor(playerColor), amountOfMoves(amountOfMoves)	{}
};

class connect4game
{
	public:
		void startGame();
		winnerResult startGame(player *player1, player *player2, bool doPrintField = true);

	private:
		void runBenchmarking(player *p1, player *p2);
};



#endif //ADV_CPP_HS16_CONNECT4GAME_H
