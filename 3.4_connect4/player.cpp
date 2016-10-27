#ifndef ADV_CPP_HS16_PLAYER_H
#define ADV_CPP_HS16_PLAYER_H

template<typename F>
class player
{
	public:
		virtual int play(const F &field) = 0;
};

#endif //ADV_CPP_HS16_PLAYER_H
