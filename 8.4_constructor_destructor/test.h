#ifndef ADV_CPP_HS16_TEST_H
#define ADV_CPP_HS16_TEST_H

#include <string>

class test
{
	private:
		std::string name;

	public:
		virtual ~test();
		void simulateCalculations();
		test(const std::string &text);
};


#endif //ADV_CPP_HS16_TEST_H
