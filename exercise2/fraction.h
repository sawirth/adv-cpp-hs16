#ifndef ADV_CPP_HS16_FRACTION_H
#define ADV_CPP_HS16_FRACTION_H

#include <ostream>
#include <istream>
#include "complex.h"
#include "complex"
#include "../6.4_RPN_complex/templateRPNcomplex.h"




class fraction
{
private:
    int counter;
    int denominator;

public:
    fraction(int counter = 0, int denominator = 1) : counter(counter), denominator(denominator) {}

    void shorten();

    int getCounter() const;

    void setCounter(int counter);

    int getDenominator() const;

    void setDenominator(int denominator);

    fraction operator+(fraction otherFraction);

    fraction operator-(fraction otherFraction);

    fraction operator*(fraction otherFraction);

    fraction operator/(fraction otherFraction);

    friend std::ostream &operator<<(std::ostream &os, const fraction &fraction);

    friend std::istream &operator>>(std::istream &is, fraction &fraction);

    //for exercise 6
    bool operator<(fraction otherFraction);

    operator double(){return (double)counter/denominator;}
    operator std::complex<float>()
    {
        return std::complex<float>((double)counter,(double)denominator);
    }

    //fraction operator+(double otherDouble);
    //fraction operator*(double otherDouble);
};


#endif //ADV_CPP_HS16_FRACTION_H
