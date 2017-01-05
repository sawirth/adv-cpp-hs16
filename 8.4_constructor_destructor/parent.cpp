#include "parent.h"
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

parent::parent()
{
	cout << "Parent constructor called" << endl;
}

parent::~parent()
{
	cout << "Parent destructor called" << endl;
}

void parent::simulateCalculations()
{
	cout << "Parent doing some calculations..." << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));
}
