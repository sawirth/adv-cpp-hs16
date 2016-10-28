#ifndef ADV_CPP_HS16_SPELLCHECKER_H
#define ADV_CPP_HS16_SPELLCHECKER_H

#include <iostream>
#include "../exercise3.1/pset.cpp"
#include "../exercise3/pvector.cpp"

using namespace std;

class spellChecker
{
	private:
		string dictionary_filename;
		pset<string, persistence_traits<string>> dictionarySet;

	public:
		static void run();
		spellChecker(const string &dictionary_filename);
		bool isCorrectlySpelled(const string &word);
		void addWord(const string &word);
};


#endif //ADV_CPP_HS16_SPELLCHECKER_H
