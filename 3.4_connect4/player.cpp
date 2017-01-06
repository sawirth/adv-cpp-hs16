#include "player.h"
#include <iostream>
#include "computerPlayer.h"
#include "humanPlayer.h"
#include "player_nico.h"

std::list<makeType*> PlayerFactory::cl;
static PlayerFH<computerPlayer> registerComputerPlayer;
static PlayerFH<humanPlayer> registerHumanPlayer;
static PlayerFH<player_nico> registerNicoAi;

void PlayerFactory::add(makeType *m)
{
	cl.push_back(m);
}

player *PlayerFactory::make(const char * plr)
{
	player *p = NULL;
	std::list<makeType*>::const_iterator b = cl.begin(), e = cl.end();
	while (b != e && (p = (*b)(plr)) == NULL)
	{
		++b;
	}

	return p;
}
