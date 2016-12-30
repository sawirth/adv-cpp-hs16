#ifndef PLAYER_FACTORY_H
#define PLAYER_FACTORY_H

#include "player.cpp"
#include <list>
#include <cstddef>

using namespace std;

typedef player* makeType(const char *);

namespace
{
	class PlayerFactory
	{
		private:
			static list<makeType *> cl;

		public:
			static void add(makeType *m)
			{
				cl.push_back(m);
			}

			static player *make(const char *p)
			{
				//TODO Das läuft nicht :(
//				player *p1 = NULL;
//				list<makeType*>::const_iterator b = cl.begin(), e = cl.end();
//				while (b != e && (p = (*b)(p)) == NULL) ++b;
//				return p1;
			}
	};
}

list<makeType*> PlayerFactory::cl = list<makeType*>();

template<class T> struct PlayerFH
{
	PlayerFH(makeType *m = (makeType*) &T::make)
	{
		PlayerFactory::add(m);
	}
};

#endif