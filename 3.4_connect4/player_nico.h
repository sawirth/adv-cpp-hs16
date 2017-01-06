#ifndef PLAYER_NICO__H
#define PLAYER_NICO__H

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream> 
#include "player.h"

class player_nico : public player {
public:
	int player_id;
 	player_nico(int id) : player_id(id){ srand (time(NULL));}
	virtual ~player_nico() {}
 	virtual int play(const playfield &field);
 	static player *make(const char*);
private:
	int check(int x, int y, int player, int offset_x, int offset_y, const playfield &field);
 	int getFreeHeight(int col, const playfield &field);
};
#endif