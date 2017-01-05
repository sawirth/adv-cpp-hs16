#include "demo.h"
#include <iostream>

using namespace std;

struct Foo
{
	void print_message(string message)
	{
		cout << message << endl;
	}
};

void demo::run()
{
	cout << endl;
	cout << "--- std::mem_fun demo ---" << endl;
	cout << "An object of type 'Foo' is created. Foo has a member method 'print' that prints a given string" << endl;
	Foo f;

	cout << "We then use mem_fun to wrap the method in a function object" << endl;
	auto printMsg = mem_fun(&Foo::print_message);

	cout << "Then we invoke the ()-Operator of that object which calls the print_message of Foo" << endl;
	printMsg(&f, "Hello World");
}
