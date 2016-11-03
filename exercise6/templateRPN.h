#ifndef ADV_CPP_HS16_TEMPLATERNP_H
#define ADV_CPP_HS16_TEMPLATERNP_H

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "../exercise2/fraction.h"
#include <numeric>
#include <algorithm>


using namespace std;

template<typename T>
class templateRNP
{
private:
    vector <T> numberStack;
public:
    void printStack()
    {

    }

    const vector<T> &getNumberStack() const
    {
        return numberStack;
    }

        void popFromStack()
    {
        if (!numberStack.empty()) {
            T numb = numberStack[numberStack.size() - 1];
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

    T myMin(){
        T *a = nullptr;
        T *b = nullptr;
        if (numberStack.size()>1) {
            a = new T;
            *a = numberStack[numberStack.size() - 1];
            b = new T;
            *b = numberStack[numberStack.size() - 2];
        }
        else
        {
            cout << "Stack doesn't have 2 numbers to get the minimum." << endl;
            return 0;
        }
        if(*a < *b)
        {
            cout << "The smaller one of " << *a << " and " << *b << " is " << *a << "." << endl;
            return *a;
        }else
        {
            cout << "The smaller one of " << *a << " and " << *b << " is " << *b << "." << endl;
            return *b;
        }
    }

    T myMin2() {
        if(numberStack.empty()){
            cout << "No numbers in the stack." << endl;
            return 0;
        }
        T min1 = numberStack.back();
        for_each(numberStack.begin(), numberStack.end(), [&](T &cur){
            if(cur < min1){min1 = cur;}});
        cout << "The minimum of the whole stack is: " << min1 << "." << endl;
        return min1;
    }

    T allPlus ()
    {
        T sumOfElements = accumulate(numberStack.begin(), numberStack.end(), 0.0);
        cout << "The sum of all elements is " << sumOfElements << "." << endl;
        return sumOfElements;
    }

    T allMultiplicate ()
    {
        T productOfElements = accumulate(numberStack.begin(), numberStack.end(), 1.0, multiplies<double>());
        cout << "The product of all elements is " << productOfElements << "." << endl;
        return productOfElements;
    }
};

#endif //ADV_CPP_HS16_TEMPLATERNP_H
