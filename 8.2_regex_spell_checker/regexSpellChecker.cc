#include "regexSpellChecker.h"

using namespace std;

void regexSpellChecker::run()
{
	cout << "Enter the path for the dictionary file:" << endl;
	string dictionaryFilepath;
	cin >> dictionaryFilepath;

	cout << "Enter the path for the file you want to spell check:" << endl;
	string contentFilepath;
	cin >> contentFilepath;

	//Content öffnen
	ifstream file;
	file.open(contentFilepath);
	string line;

	//Regex zum finden der Wörter
	regex words_regex("\\w+");

	//Dictionary öffnen
	vector<string> dictionaryRegexes = utils::inputUtils::readWordByWordFromText(dictionaryFilepath);

	while(file >> line)
	{
		auto words_begin = sregex_iterator(line.begin(), line.end(), words_regex);
		auto words_end = sregex_iterator();

		for (sregex_iterator i = words_begin; i != words_end; ++i)
		{
			auto match = *i;
			auto word = match.str();
			bool matched = false;

			//Prüft für jeden regex im dictionary ob das Wort ein match ist und printet das Wort falls es kein Match gab
			for (auto regexString : dictionaryRegexes)
			{
				regex test(regexString);
				if (regex_match(word, test))
				{
					matched = true;
					break;
				}
			}

			if (!matched)
			{
				cout << "'" << word << "' has not been matched" << endl;
			}
		}
	}

	cout << "Spell checking finished" << endl;
}