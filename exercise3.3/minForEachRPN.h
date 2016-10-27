#ifndef ADV_CPP_HS16_MINFOREACHPRN_H
#define ADV_CPP_HS16_MINFOREACHPRN_H

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "../exercise2/fraction.h"
#include <numeric>


using namespace std;

template<typename T>
class minForEachRPN {
private:
    vector<T> numberStack;
public:
    T getNumberStack() {
        return numberStack;
    }

    void popFromStack() {
        if (!numberStack.empty()) {
            T numb = numberStack[numberStack.size() - 1];
            cout << "Removed message: " << numb << endl;
            numberStack.pop_back();
        } else {
            cout << "Stack is empty." << endl;
        }
    }

    void addition() {
        T *numb1 = nullptr;
        T *numb2 = nullptr;
        if (!numberStack.empty()) {
            numb1 = new T;
            *numb1 = numberStack[numberStack.size() - 1];
            numberStack.pop_back();
        }
        if (!numberStack.empty()) {
            numb2 = new T;
            *numb2 = numberStack[numberStack.size() - 1];
            numberStack.pop_back();
        } else {
            if (numb1 != nullptr) {
                numberStack.push_back(*numb1);
            }
            cout << "Stack doesn't have 2 numbers to sum up" << endl;
            return;
        }
        cout << *numb1 << " + " << *numb2 << " = " << *numb1 + *numb2 << endl;
        numberStack.push_back(*numb1 + *numb2);
    }

    void subtraction() {
        T *numb1 = nullptr;
        T *numb2 = nullptr;
        if (!numberStack.empty()) {
            numb1 = new T;
            *numb1 = numberStack[numberStack.size() - 1];
            numberStack.pop_back();
        }
        if (!numberStack.empty()) {
            numb2 = new T;
            *numb2 = numberStack[numberStack.size() - 1];
            numberStack.pop_back();
        } else {
            if (numb1 != nullptr) {
                numberStack.push_back(*numb1);
            }
            cout << "Stack doesn't have 2 numbers to subtract" << endl;
            return;
        }
        cout << *numb1 << " - " << *numb2 << " = " << *numb1 - *numb2 << endl;
        numberStack.push_back(*numb1 - *numb2);
    }

    void multiplication() {
        T *numb1 = nullptr;
        T *numb2 = nullptr;
        if (!numberStack.empty()) {
            numb1 = new T;
            *numb1 = numberStack[numberStack.size() - 1];
            numberStack.pop_back();
        }
        if (!numberStack.empty()) {
            numb2 = new T;
            *numb2 = numberStack[numberStack.size() - 1];
            numberStack.pop_back();
        } else {
            if (numb1 != nullptr) {
                numberStack.push_back(*numb1);
            }
            cout << "Stack doesn't have 2 numbers to multiply" << endl;
            return;
        }
        cout << *numb1 << " * " << *numb2 << " = " << *numb1 * *numb2 << endl;
        numberStack.push_back(*numb1 * *numb2);
    }

    void division() {
        T *numb1 = nullptr;
        T *numb2 = nullptr;
        if (!numberStack.empty()) {
            numb1 = new T;
            *numb1 = numberStack[numberStack.size() - 1];
            numberStack.pop_back();
        }
        if (!numberStack.empty()) {
            numb2 = new T;
            *numb2 = numberStack[numberStack.size() - 1];
            numberStack.pop_back();
        } else {
            if (numb1 != 0) {
                numberStack.push_back(*numb1);
            }
            cout << "Stack doesn't have 2 numbers to divide" << endl;
            return;
        }
        cout << *numb1 << " / " << *numb2 << " = " << *numb1 / *numb2 << endl;
        numberStack.push_back(*numb1 / *numb2);
    }

    void putOnStack(T i) {
        numberStack.push_back(i);
        cout << "You added the number " << i << " to the stack." << endl;
    }

    void putOnStack(double d, int i) {
        if (typeid(T) == typeid(int)) {
            numberStack.push_back((int) d);
            cout << "You added the number " << d << " to the stack." << endl;
        } else if (typeid(T) == typeid(double)) {
            numberStack.push_back(d);
            cout << "You added the number " << d << " to the stack." << endl;
        } else if (typeid(T) == typeid(fraction)) {
            fraction fraction1 = fraction((int) d, i);
            numberStack.push_back(fraction1);
            //  cout << "You added the number " << fraction1 << " to the stack." << endl;
        }
    }

    T myMin() {
        T *a = nullptr;
        T *b = nullptr;
        if (numberStack.size() > 1) {
            a = new T;
            *a = numberStack[numberStack.size() - 1];
            b = new T;
            *b = numberStack[numberStack.size() - 2];
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
private:

    T *min = nullptr;

    void minHelper(const T &a) {
        if(min == nullptr)
        {
            *min = a;
        }
        else if (a < *min)
        {
            *min = a;
        }
    }
public:
    T myMin2() {
        if(!numberStack.empty()){
            cout << "No numbers in the stack." << endl;
            return 0;
        }
        *min = numberStack.begin();
        for_each(numberStack.begin(), numberStack.end(),&minForEachRPN::minHelper);
        cout << "The minimum of the whole stack is: " << *min << "." << endl;
        return *min;
    }
};

#endif //ADV_CPP_HS16_MINFOREACHPRN_H
