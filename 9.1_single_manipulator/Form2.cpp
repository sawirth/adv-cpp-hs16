#include "Form2.h"

using namespace std;

Form2 &Form2::scientific()
{
	fmt = ios_base::scientific;
	return *this;
}

Form2 &Form2::precision(int p)
{
	prc = p;
	return *this;
}