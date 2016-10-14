//
// Created by Sandro on 14.10.2016.
//

#include <iostream>
#include "inputUtils.h"

using namespace std;

string readLine()
{
	string input;
	cin.sync();
	cin >> input;
	return input;
}

int utils::inputUtils::getInt()
{
	while(true)
	{
		string input = readLine();
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

double utils::inputUtils::getDouble()
{
	while(true)
	{
		string input = readLine();
		try
		{
			return stod(input);
		}
		catch (invalid_argument e)
		{
			cout << "Error! Try again: ";
		}
	}
}

