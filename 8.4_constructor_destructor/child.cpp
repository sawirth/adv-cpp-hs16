#include "child.h"
#include <iostream>
#include <thread>

using namespace std;

child::child() : parent()
{
	cout << "Child constructor called" << endl;
}

child::~child()
{
	cout << "Child destructor called" << endl;
}

void child::simulateCalculations()
{
	cout << "Child doing some calculations..." << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));
}
