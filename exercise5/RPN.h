#ifndef ADV_CPP_HS16_RPN_H
#define ADV_CPP_HS16_RPN_H

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class RPN
{
private:
    vector <int> numberStack;
public:
    void addition();
    void subtraction();
    void multiplication();
    void division();
    void putOnStack(int i);
    void popFromStack();
    void printStack();
    const vector<int> &getVector() const
    {
        return numberStack;
    }
};

#endif //ADV_CPP_HS16_RPN_H
