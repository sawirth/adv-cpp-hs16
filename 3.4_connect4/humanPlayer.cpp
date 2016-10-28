#ifndef ADV_CPP_HS16_HUMANPLAYER_H
#define ADV_CPP_HS16_HUMANPLAYER_H

#include <iostream>
#include "player.cpp"
#include "../utils/inputUtils.h"

using namespace std;

template<typename F>
class humanPlayer: public player<F>
{
	public:
		virtual int play(const F &field) override
		{
			//For better understanding we ask for 1 to 7 instead of 0 to 6 and then subtract 1 to get the proper value
			cout << "Player " << field.getCurrentPlayerChar() << ": In which column you want to place your stone? 1 to 7: ";
			return utils::inputUtils::getInt() - 1;
		}
};


#endif //ADV_CPP_HS16_HUMANPLAYER_H