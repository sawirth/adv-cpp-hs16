#ifndef ADV_CPP_HS16_FORM2_H
#define ADV_CPP_HS16_FORM2_H

#include <iostream>

class Form2
{
	public:
		int prc;
		std::ios_base::fmtflags fmt;

		Form2(int p = 6) : prc(p) {}

		Form2& scientific();

		Form2& precision(int p);

		friend std::ostream& operator<<(std::ostream& os, Form2 &f)
		{
			os.setf(f.fmt, std::ios_base::floatfield);
			os.precision(f.prc);
			return os;
		}
};


#endif //ADV_CPP_HS16_FORM2_H
