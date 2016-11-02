//
// Created by Sandro on 14.10.2016.
//

#include "fraction.h"

int fraction::getCounter() const
{
    return counter;
}

void fraction::setCounter(int counter)
{
    fraction::counter = counter;
}

int fraction::getDenominator() const
{
    return denominator;
}

void fraction::setDenominator(int denominator)
{
    fraction::denominator = denominator;
}

fraction fraction::operator+(fraction otherFraction)
{
    int denominator = otherFraction.denominator * getDenominator();
    int counter = getCounter() * otherFraction.denominator + otherFraction.counter * getDenominator();

    fraction f = fraction(counter, denominator);
    f.shorten();
    return f;
}

fraction fraction::operator-(fraction otherFraction)
{
    int denominator = otherFraction.denominator * getDenominator();
    int counter = getCounter() * otherFraction.denominator - otherFraction.counter * getDenominator();

    fraction f = fraction(counter, denominator);
    f.shorten();
    return f;
}

fraction fraction::operator*(fraction otherFraction)
{
    fraction f = fraction(getCounter() * otherFraction.getCounter(), getDenominator() * otherFraction.getDenominator());
    f.shorten();
    return f;
}

fraction fraction::operator/(fraction otherFraction)
{
    return *this * fraction(otherFraction.getDenominator(), otherFraction.getCounter());
}

std::ostream &operator<<(std::ostream &os, const fraction &fraction)
{
    os << fraction.getCounter() << "/" << fraction.getDenominator();
    return os;
}

std::istream &operator>>(std::istream &is, fraction &fraction)
{
	is >> fraction.counter >> fraction.denominator;
	return is;
}

void fraction::shorten()
{
    int c = getCounter();
    int d = getDenominator();

    while (d != 0) {
        int h = c % d;
        c = d;
        d = h;
    }

    setCounter(getCounter() / c);
    setDenominator(getDenominator() / c);
}

// for exercise 6

bool fraction::operator<(fraction otherFraction){
    double frac1 = (double) getCounter() / (double)getDenominator();
    double frac2 = (double) otherFraction.getCounter() / (double) otherFraction.getDenominator();
    if (frac1 < frac2) {
        return true;
    }
    else{
        return false;
    }
}

/*fraction fraction::operator*(double otherDouble)
{
    fraction f = fraction((int)(getCounter() * otherDouble), getDenominator());
    f.shorten();
    return f;
}

fraction fraction::operator+(double otherDouble)
{
    fraction f = fraction((int)(getCounter() + getDenominator()* otherDouble), getDenominator());
    f.shorten();
    return f;
}
*/



