#include "../exercise3.1/pset.cpp"
#include "../exercise3/pvector.cpp"
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

		static void replace_in_pvector()
		{
			pvector<string> v = pvector<string>("abc");
			v.push_back("test");


		}

	public:
		static void runTests()
		{
			cout << "Starting tests.." << endl;

			find_in_pset();

			cout << "All tests passed" << endl;
		}
};

