#ifndef ADV_CPP_HS16_PRNP_H
#define ADV_CPP_HS16_PRNP_H

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "../exercise2/fraction.h"
#include <numeric>
#include "../exercise2.5/pvectorRNP.h"


using namespace std;

template<typename T>
class pRNP
{
private:
    string filename;
    string type;
    pvectorRNP <T> numberStack = pvectorRNP <T>(filename, type);

public:
    pRNP(string filename, string type): filename(filename), type(type) {}

    const vector <T> getNumberStack()
    {
        return numberStack.getVector();
    }
    pvectorRNP <T> getRNP()
    {
        return numberStack;
    }

    int getSize()
    {
        return getNumberStack().size();
    }
    void popFromStack()
    {
        if (!getNumberStack().empty()) {
            T numb = getNumberStack()[getSize() - 1];
            cout << "Removed message: " << numb << endl;
            numberStack.pop_back();
        } else {
            cout << "Stack is empty." << endl;
        }
    }
    void addition()
    {
        T *numb1 = nullptr;
        T *numb2 = nullptr;
        if (!getNumberStack().empty()) {
            numb1 = new T;
            *numb1 = getNumberStack()[getSize() - 1];
            numberStack.pop_back();
        }
        if (!getNumberStack().empty()) {
            numb2 = new T;
            *numb2 = getNumberStack()[getSize() - 1];
            numberStack.pop_back();
        } else {
            if(numb1 != nullptr)
            {
                numberStack.push_back(*numb1);
            }
            cout << "Stack doesn't have 2 numbers to sum up" << endl;
            return;
        }
        cout << *numb1 << " + " << *numb2 << " = " << *numb1 + *numb2 << endl;
        numberStack.push_back(*numb1 + *numb2);
    }

    void subtraction()
    {
        T *numb1 = nullptr;
        T *numb2 = nullptr;
        if (!getNumberStack().empty()) {
            numb1 = new T;
            *numb1 = getNumberStack()[getSize() - 1];
            numberStack.pop_back();
        }
        if (!getNumberStack().empty()) {
            numb2 = new T;
            *numb2 = getNumberStack()[getSize() - 1];
            numberStack.pop_back();
        } else {
            if(numb1 != nullptr)
            {
                numberStack.push_back(*numb1);
            }
            cout << "Stack doesn't have 2 numbers to subtract" << endl;
            return;
        }
        cout << *numb1 << " - " << *numb2 << " = " << *numb1 - *numb2 << endl;
        numberStack.push_back(*numb1 - *numb2);
    }
    void multiplication()
    {
        T *numb1 = nullptr;
        T *numb2 = nullptr;
        if (!getNumberStack().empty()) {
            numb1 = new T;
            *numb1 = getNumberStack()[getSize() - 1];
            numberStack.pop_back();
        }
        if (!getNumberStack().empty()) {
            numb2 = new T;
            *numb2 = getNumberStack()[getSize() - 1];
            numberStack.pop_back();
        } else {
            if(numb1 != nullptr)
            {
                numberStack.push_back(*numb1);
            }
            cout << "Stack doesn't have 2 numbers to multiply" << endl;
            return;
        }
        cout << *numb1 << " * " << *numb2 << " = " << *numb1 * *numb2 << endl;
        numberStack.push_back(*numb1 * *numb2);
    }

    void division()
    {
        T *numb1 = nullptr;
        T *numb2 = nullptr;
        if (!getNumberStack().empty()) {
            numb1 = new T;
            *numb1 = getNumberStack()[getSize() - 1];
            numberStack.pop_back();
        }
        if (!getNumberStack().empty()) {
            numb2 = new T;
            *numb2 = getNumberStack()[getSize() - 1];
            numberStack.pop_back();
        } else {
            if(numb1 != 0)
            {
                numberStack.push_back(*numb1);
            }
            cout << "Stack doesn't have 2 numbers to divide" << endl;
            return;
        }
        cout << *numb1 << " / " << *numb2 << " = " << *numb1 / *numb2 << endl;
        numberStack.push_back(*numb1 / *numb2);
    }

    void putOnStack(T i){
        numberStack.push_back(i);
        cout << "You added the number " << i << " to the stack." << endl;
    }

    void mymin() {
        T *a = nullptr;
        T *b = nullptr;
        if (!getNumberStack().empty()) {
            a = new T;
            *a = getNumberStack()[getSize() - 1];
            numberStack.pop_back();
        }
        if (!getNumberStack().empty()) {
            b = new T;
            *b = getNumberStack()[getSize() - 1];
            numberStack.pop_back();
        } else {
            if (a != nullptr) {
                numberStack.push_back(*a);
            }
            cout << "Stack doesn't have 2 numbers to get the minimum." << endl;
        }
        if (*a < *b) {
            numberStack.push_back(*a);
            cout << "The smaller one of " << *a << " and " << *b << " is " << *a << "." << endl;
        } else {
            cout << "The smaller one of " << *a << " and " << *b << " is " << *b << "." << endl;
        }
    }

    /*T allPlus ()
    {
        T sumOfElements = accumulate(numberStack.begin(), numberStack.end(), 0.0);
    }

    T allMultiplicate ()
    {
        T productOfElements = accumulate(numberStack.begin(), numberStack.end(), 1.0, multiplies<double>());
    }*/
};

#endif //ADV_CPP_HS16_PRNP_H
