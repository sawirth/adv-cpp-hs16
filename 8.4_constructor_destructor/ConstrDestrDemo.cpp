#include "ConstrDestrDemo.h"
#include "parent.h"
#include "child.h"
#include "test.h"
#include <iostream>

using namespace std;

void ConstrDestrDemo::run()
{
	cout << endl;
	normal();
	cout << endl;
	inheritance();
	cout << endl;
	special();
}

void ConstrDestrDemo::inheritance()
{
	cout << "--- Example with inheritance ---" << endl;
	cout << "We create a parent and a child object. Both simulate some calculations" << endl;
	cout << "As soon as both finished their calculations the scope ends and their destructors will be called" << endl;
	parent parent1 = parent();
	child child1 = child();
	parent1.simulateCalculations();
	child1.simulateCalculations();
	cout << "Scope ends" << endl;
}

void ConstrDestrDemo::normal()
{
	cout << "--- Example without inheritance ---" << endl;
	cout << "We create an object that simulates some calculations" << endl;
	cout << "As soon as the calculations ended the method will end and the destructor will be called" << endl;
	test test1 = test("test");
	test1.simulateCalculations();
	cout << "Scope ends" << endl;
}

void ConstrDestrDemo::special()
{
	cout << "--- Example with multiple scopes" << endl;

	try {
		cout << "We create an object inside a try block and then throw an exception:" << endl;
		test inTry = test("inside try-block");
		throw invalid_argument("invalid argument");
	}
	catch (invalid_argument e)
	{
		test inCatch = test("inside catch-block");
	}

	test first = test("first");
	test second = test("second");
	test third = test("third");

	cout << "Scope ends" << endl;
}
