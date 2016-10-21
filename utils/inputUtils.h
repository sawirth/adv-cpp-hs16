#ifndef ADV_CPP_HS16_INPUTUTILS_H
#define ADV_CPP_HS16_INPUTUTILS_H

#include <vector>
#include <string>

using namespace std;

namespace utils
{
	class inputUtils
	{
		public:
			static int getInt();
			static double getDouble();
			static vector<string> readWordByWordFromText(const string &filepath);
	};
}

#endif //ADV_CPP_HS16_INPUTUTILS_H
