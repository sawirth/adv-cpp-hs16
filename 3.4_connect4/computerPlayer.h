#ifndef ADV_CPP_HS16_COMPUTERPLAYER_H
#define ADV_CPP_HS16_COMPUTERPLAYER_H

#include "player.h"
#include <chrono>
#include <thread>
#include <iostream>
#include <random>
#include <algorithm>
#include "connect4Utils.cpp"

using namespace std;

class computerPlayer : public player
{
	private:
		int myColor = 0;
		int opponentColor = 0;
		int none = playfield::none;
		int localField[playfield::width][playfield::height];
		const int width = playfield::width;
		const int height = playfield::height;
		vector<int> openColumns = vector<int>();
		int sleeptime = 250;
		bool doPrint = true;

		void setStoneColor(const playfield &field);

		void copyFieldToLocal(const playfield &field);

		int findBestColumn(const playfield &field);

		void findOpenColumns();

		//This method simulates a possible move for further calculations
		void tempPlay(int column, int stoneColor);

		//Removes the top most stone in the given column
		void undoMove(int column);

		int hasWinner();

	public:

		//Das wird für den Benchmark benötigt, damit es schnell läuft
		computerPlayer(int sleeptime, bool doPrint) : sleeptime(sleeptime), doPrint(doPrint) {}

		computerPlayer() {}

		virtual int play(const playfield &field) override;

		static player *make(const char *player);
};

#endif //ADV_CPP_HS16_COMPUTERPLAYER_H
