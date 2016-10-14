//
// Created by Sandro on 14.10.2016.
//

#include "fractionTestDriver.h"
#include "fraction.h"
#include <assert.h>
#include <iostream>

using namespace std;

void fractionTestDriver::run() {
    //First test
    fraction f1 = fraction(3, 4);
    fraction f2 = fraction(4, 7);
    fraction test1 = f1 + f2;
    assert(test1.getCounter() == 37);
    assert(test1.getDenominator() == 28);
    cout << "First test passed: " << f1 << " + " << f2 << " = " << test1 << endl;

    //Second test
    fraction f3 = fraction(4, 9);
    fraction f4 = fraction(1, 18);
    fraction test2 = f3 + f4;
    assert(test2.getCounter() == 1);
    assert(test2.getDenominator() == 2);
    cout << "Second test passed: " << f3 << " + " << f4 << " = " << test2 << endl;

    //Third test
    fraction f5 = fraction(15, 24);
    fraction f6 = fraction(3, 6);
    fraction test3 = f5 - f6;
    assert(test3.getCounter() == 1);
    assert(test3.getDenominator() == 8);
    cout << "Third test passed: " << f5 << " - " << f6 << " = " << test3 << endl;
}
