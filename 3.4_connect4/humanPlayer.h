#ifndef ADV_CPP_HS16_HUMANPLAYER_H
#define ADV_CPP_HS16_HUMANPLAYER_H

#include <iostream>
#include "player.h"
#include "../utils/inputUtils.h"

using namespace std;

class humanPlayer: public player
{
	public:
		virtual int play(const playfield &field) override;

		static player *make(const char *player);
};

//static PlayerFH<humanPlayer> registerHumanPlayer;

#endif //ADV_CPP_HS16_HUMANPLAYER_H