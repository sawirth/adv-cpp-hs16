#include "../exercise3.1/pset.cpp"
#include "../exercise3/pvector.cpp"
#include "connect4tests.cpp"
#include <assert.h>

using namespace std;

class TestRunner {
	private:
		static void find_in_pset()
		{
			pset<string> s = pset<string>("abc");
			s.insert("hello");
			s.insert("world");

			assert(s.contains("hello"));
			assert(!s.contains("some word"));

			cout << "Find in pvector passed" << endl;


			string a = "hello";

		}

	public:
		static void runTests()
		{
			cout << "Starting tests.." << endl;

			find_in_pset();

			connect4tests tests = connect4tests();
			tests.runTests();

			cout << "All tests passed" << endl;
		}
};

