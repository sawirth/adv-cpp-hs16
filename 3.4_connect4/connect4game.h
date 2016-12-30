#ifndef ADV_CPP_HS16_CONNECT4GAME_H
#define ADV_CPP_HS16_CONNECT4GAME_H

#include "player.cpp"
#include "playfield.h"

class connect4game
{
	public:
		void startGame();
		void startGame(player &player1, player &player2);
};


#endif //ADV_CPP_HS16_CONNECT4GAME_H
