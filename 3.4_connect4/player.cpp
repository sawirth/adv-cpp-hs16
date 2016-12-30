#ifndef ADV_CPP_HS16_PLAYER_H
#define ADV_CPP_HS16_PLAYER_H

#include "playfield.h"

class player
{
	public:
		virtual int play(const playfield &field) = 0;
		virtual ~player() {}
};
#endif //ADV_CPP_HS16_PLAYER_H
