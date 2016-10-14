//
// Created by Sandro on 14.10.2016.
//

#include <iostream>
#include "inputUtils.h"

using namespace std;

int utils::inputUtils::getInt()
{
	while(true)
	{
		string input = "";
		cin.sync();
		getline(cin, input);

		try
		{
			return stoi(input);
		}
		catch (invalid_argument e)
		{
			cout << "Error! Try again: ";
		}
	}
}
