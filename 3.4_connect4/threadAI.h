#ifndef ADV_CPP_HS16_THREADAI_H
#define ADV_CPP_HS16_THREADAI_H

#include <mutex>
#include "playfield.h"
#include <vector>
#include <thread>
#include <map>
#include "player.cpp"

class threadAI : public player
{
	private:
		int myColor = 0;
		int opponentColor = 0;
		int none = playfield::none;
		int localField[playfield::width][playfield::height];
		const int width = playfield::width;
		const int height = playfield::height;
		std::vector<int> openColumns = std::vector<int>();
		int sleeptime = 250;
		bool doPrint = true;

		std::vector<std::thread> threads = std::vector<std::thread>();
		std::map<int, int> nextMoves = std::map<int, int>();
		static std::mutex mtx;

		void setStoneColor(const playfield &field);
		void copyFieldToLocal(const playfield &field);
		int findBestColumn();
		void findOpenColumns();
		void tempPlay(int column, int stoneColor);
		void undoMove(int column);
		int hasWinner();
		void calculateBestMoveIfOpponentPlays(int column);
		int findChangedColumn(const playfield &field);

	public:
		virtual int play(const playfield &field);
};

#endif //ADV_CPP_HS16_THREADAI_H
