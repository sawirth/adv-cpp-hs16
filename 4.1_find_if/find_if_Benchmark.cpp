#include <iostream>
#include <random>
#include <chrono>
#include "find_if_Benchmark.h"
#include "../utils/inputUtils.h"

using namespace std;

vector<int> numberOfIterations = vector<int>();

template<typename Iter, typename Pred>
Iter find_if(Iter begin, Iter beyond, Pred pred)
{
	int counter = 1;
	while(begin != beyond)
	{
		if (pred(*begin))
		{
			break;
		}

		++begin;
		++counter;
	}

	//We only measure it if we found the element
	if (begin != beyond)
	{
		numberOfIterations.push_back(counter);
	}

	return begin;
};

void find_if_Benchmark::run()
{
	cout << endl;
	cout << "--------- FIND_IF BENCHMARKING ---------" << endl;
	//Ask user for benchmark parameters
	cout << "How many runs do you want to perform? ";
	int numOfRuns = utils::inputUtils::getInt();

	cout << "How many numbers should the vector contain? ";
	int size = utils::inputUtils::getInt();

	cout << "Between 0 and which value should the random numbers be distributed? ";
	int range = utils::inputUtils::getInt();

	cout << "Start benchmark..." << endl;
	//Create vector with values
	vector<int> list = vector<int>();
	random_device rd;
	mt19937 eng(rd());
	uniform_int_distribution<> distr(0, range);

	for (int i = 0; i < size; i++)
	{
		list.push_back(distr(eng));
	}

	//Run benchmark
	vector<double> elapsedTimes = vector<double>();
	for (int i = 0; i < numOfRuns; i++)
	{
		int numberToFound = distr(eng);
		auto pred = [numberToFound] (const int &value) { return numberToFound == value; };
		auto start = chrono::high_resolution_clock::now();

		auto iter = find_if(list.begin(), list.end(), pred);

		auto finish = chrono::high_resolution_clock::now();
		auto elapsedTime = chrono::duration_cast<chrono::nanoseconds>(finish - start).count();

		//We only measure when we actually found the element
		if (iter != list.end())
		{
			elapsedTimes.push_back(elapsedTime);
		}
	}

	//Cacluate averages
	double avgElapsedTimeInNanoseconds = 0;
	double avgIterations = 0;
	for (unsigned int i = 0; i < elapsedTimes.size(); i++)
	{
		avgElapsedTimeInNanoseconds += elapsedTimes.at(i);
		avgIterations += numberOfIterations.at(i);
	}

	avgElapsedTimeInNanoseconds = avgElapsedTimeInNanoseconds / elapsedTimes.size();
	double avgElapsedTimeInMilliseconds = avgElapsedTimeInNanoseconds / 1000000;
	avgIterations = avgIterations / numberOfIterations.size();

	cout << "\nRESULTS" << endl;
	cout << "Average time: " << avgElapsedTimeInNanoseconds << "ns / " << avgElapsedTimeInMilliseconds << "ms" << endl;
	cout << "Average iterations: " << avgIterations << endl;
	double matching = elapsedTimes.size() / (double)numOfRuns * 100;
	cout << "Matching: " << matching << "% (" << elapsedTimes.size() << " of " << numOfRuns << ")" << endl;
}
