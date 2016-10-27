//
// Created by Sandro on 25.10.2016.
//

#ifndef ADV_CPP_HS16_CONNECT4GAME_H
#define ADV_CPP_HS16_CONNECT4GAME_H

#include "player.cpp"
#include "playfield.h"

class connect4game
{
	public:
		void startGame();
		void startGame(player<playfield> &player1, player<playfield> &player2);
};


#endif //ADV_CPP_HS16_CONNECT4GAME_H
