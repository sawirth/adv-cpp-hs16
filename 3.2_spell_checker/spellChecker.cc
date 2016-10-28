#include "spellChecker.h"
#include "../utils/inputUtils.h"

using namespace std;

spellChecker::spellChecker(const string &dictionary_filename) : dictionary_filename(
		dictionary_filename), dictionarySet(pset<string, persistence_traits<string>>(dictionary_filename))
{
}

void spellChecker::run()
{
	cout << "Enter the path for the dictionary file:" << endl;
	string dictionaryFilepath;
	cin >> dictionaryFilepath;
	spellChecker checker = spellChecker(dictionaryFilepath);

	cout << "Enter the path for the file you want to spell check:" << endl;
	string contentFilepath;
	cin >> contentFilepath;
	const string correctedContentFilepath = contentFilepath + ".corrected";
	pvector<string> content = pvector<string>(correctedContentFilepath);
	content.setVector(utils::inputUtils::readWordByWordFromText(contentFilepath));

	for (auto it = content.getVector().begin(); it != content.getVector().end(); ++it)
	{
		auto pos = it - content.getVector().begin();
		auto word = content.getVector().at(pos);
		if(!checker.isCorrectlySpelled(word))
		{
			cout << word << endl;
			cout << "(a)dd - (i)gnore - (r)eplace? ";
			string answer;
			cin >> answer;

			if (answer == "a")
			{
				checker.addWord(word);
			}
			else if (answer == "r")
			{
				cout << "Enter the new word: ";
				string newWord;
				cin >> newWord;
				content.erase(it);
				content.insert(it, newWord);
				--it;
			}
		}
	}

	cout << "Spell checking finished" << endl;
	cout << "Corrected content written to " << correctedContentFilepath << endl;
}

bool spellChecker::isCorrectlySpelled(const string &word)
{
	return dictionarySet.contains(word);
}

void spellChecker::addWord(const string &word)
{
	dictionarySet.insert(word);
}