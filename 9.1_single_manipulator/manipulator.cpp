#include <iomanip>
#include "manipulator.h"
#include "Form2.h"

using namespace std;

ostream& curr(ostream& ostrObj)
{
	cout << fixed << setprecision(2);
	return ostrObj;
}

void manipulator::run()
{
	double number = 10.123455;

	Form2 gen4(2);

	Form2 sci8 = gen4;
	sci8.scientific().precision(2);

	cout << number << " - " << sci8 << number << endl;
}
