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
    pvectorRNP <T> numberStack = pvectorRNP <T>(filename);

public:
    pRNP(string filename): filename(filename) {
    }

    void printStack() {
        for (int i = 0; i < getSize(); i++) {
            cout << numberStack.getVector()[i] << endl;
        }
    }

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
        if(*numb2 == 0){
            cout << "Division by zero is not allowed, try something other." << endl;
            numberStack.push_back(*numb2);
            numberStack.push_back(*numb1);
            return;
        }
        cout << *numb1 << " / " << *numb2 << " = " << *numb1 / *numb2 << endl;
        numberStack.push_back(*numb1 / *numb2);
    }

    void putOnStack(T i){
        numberStack.push_back(i);
        cout << "You added the number " << i << " to the stack." << endl;
    }

    T myMin() {
        T *a = nullptr;
        T *b = nullptr;
        if (getSize() > 1) {
            a = new T;
            *a = getNumberStack()[getSize() - 1];
            b = new T;
            *b = getNumberStack()[getSize() - 2];
        } else {
            cout << "Stack doesn't have 2 numbers to get the minimum." << endl;
            return 0;
        }
        if (*a < *b) {
            cout << "The smaller one of " << *a << " and " << *b << " is " << *a << "." << endl;
            return *a;
        } else {
            cout << "The smaller one of " << *a << " and " << *b << " is " << *b << "." << endl;
            return *b;
        }
    }

   /* T myMin2() {
        if(getNumberStack().empty()){
            cout << "No numbers in the stack." << endl;
            return 0;
        }
        T min1 = getNumberStack().back();
        for_each(getNumberStack().begin(), getNumberStack().end(), [&](T &cur){
            if(cur < min1){min1 = cur;}});
        cout << "The minimum of the whole stack is: " << min1 << "." << endl;
        return min1;
    }*/

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
