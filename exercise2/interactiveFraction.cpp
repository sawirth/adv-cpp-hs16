#include "interactiveFraction.h"
#include "fraction.h"
#include "../utils/inputUtils.h"
#include <iostream>

using namespace std;

fraction readFractionFromInput();

void interactiveFraction::run()
{
	cout << "In this interactive test you can enter two fraction and make a basic operation on them to test the correctness "
			"of the implementation" << endl;

	fraction f1 = readFractionFromInput();
	cout << "Fraction " << f1 << " read. Now the second one" << endl;
	fraction f2 = readFractionFromInput();
	cout << "Second fraction " << f2 << " also read" << endl;

	cout << "Which operation do you want to perform? Enter the number" << endl;
	cout << "1 = Addition (+)" << endl;
	cout << "2 = Subtraction (-)" << endl;
	cout << "3 = Multiplication (*)" << endl;
	cout << "4 = Division (/)" << endl;

	int choice = utils::inputUtils::getInt();

	switch (choice)
	{
		case 1:
			cout << f1 << " + " << f2 << " = " << f1 + f2 << endl;
			break;

		case 2:
			cout << f1 << " - " << f2 << " = " << f1 - f2 << endl;
			break;

		case 3:
			cout << f1 << " * " << f2 << " = " << f1 * f2 << endl;
			break;

		case 4:
			cout << f1 << " / " << f2 << " = " << f1 / f2 << endl;
			break;

		default:
			cout << "No operation found for " << choice << endl;
	}
}

fraction readFractionFromInput()
{
	while (true) {
		string delimiter = "/";
		string input = "";

		cout << "Enter the counter and denominator in the following form: 1/2 -- ";
		cin.sync();
		getline(cin, input);

		if (input.find(delimiter) != string::npos)
		{
			string ctr = input.substr(0, input.find(delimiter));
			string denom = input.substr(input.find(delimiter) + 1, input.length() - 1);
			try {
				int counter = stoi(ctr);
				int denominator = stoi(denom);
				return fraction(counter, denominator);
			}
			catch (invalid_argument e)
			{
				cout << "invalid_argument exception while parsing: " << ctr << " " << denom << endl;
				cin.clear();
			}
		}
		else
		{
			cout << "No / found. Please enter the fraction in the correct form" << endl;
		}
	}
}