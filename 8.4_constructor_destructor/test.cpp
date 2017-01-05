#include "test.h"
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

test::~test()
{
	cout << "Destructor of object with name '" << name << "' called" << endl;
}

void test::simulateCalculations()
{
	cout << "Doing some calculations..." << endl;
	std::this_thread::sleep_for(std::chrono::seconds(3));
}

test::test(const string &text) : name(text)
{
	cout << "Constructor of object with name '" << name << "' called" << endl;
}
