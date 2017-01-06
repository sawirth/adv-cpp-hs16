#include <cstring>
#include "playfield.h"
#include "humanPlayer.h"

int humanPlayer::play(const playfield &field)
{
	//For better understanding we ask for 1 to 7 instead of 0 to 6 and then subtract 1 to get the proper value
	cout << "Player " << field.getCurrentPlayerChar() << ": In which column you want to place your stone? 1 to 7: ";
	return utils::inputUtils::getInt() - 1;
}

player *humanPlayer::make(const char *player)
{
	int rc = strcmp(player, "human");
	if (rc != 0)
	{
		return NULL;
	}

	return new humanPlayer();
}
