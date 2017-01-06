#ifndef ADV_CPP_HS16_PLAYER_H
#define ADV_CPP_HS16_PLAYER_H

#include "playfield.h"
#include <list>

class player
{
	public:
		virtual int play(const playfield &field) = 0;

		virtual ~player()
		{}
};

typedef player *makeType(const char *);

class PlayerFactory
{
	private:
		static std::list<makeType *> cl;

	public:
		static void add(makeType *m);

		static player *make(const char *plr);
};

template<class T>
struct PlayerFH
{
	PlayerFH(makeType *m = (makeType *) &T::make)
	{
		PlayerFactory::add(m);
	}
};

#endif //ADV_CPP_HS16_PLAYER_H
