
#ifndef ADV_CPP_HS16_COMPUTERPLAYER_H
#define ADV_CPP_HS16_COMPUTERPLAYER_H

#include "player.cpp"
#include <chrono>
#include <thread>
#include <iostream>

using namespace std;

template<typename F>
class computerPlayer : public player<F>
{
	public:
		virtual int play(const F &field) override
		{
			for (int column = 0; column < field.width; column++)
			{
				if (field.stoneat(column, 0) == field.none)
				{
					std::this_thread::sleep_for(std::chrono::milliseconds(250));
					cout << "Computer places stone in " << column + 1 << endl;
					return column;
				}
			}
		}
};


#endif //ADV_CPP_HS16_COMPUTERPLAYER_H