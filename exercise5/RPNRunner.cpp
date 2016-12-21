#include <vector>
#include <iostream>
#include "RPN.h"
#include "RPNRunner.h"

using namespace std;

void RPNRunner::run()
{
    while(true) {
        cout << "What do you want to do?" << endl;
        cout << "q - quit the program" << endl;
        cout << "n - puts a number you chose afterwards on the stack"<< endl;
        cout << "d - removes last number from the stack" << endl;
        cout << "Or just simply do some operations on the last two numbers from the stack: '+', '-', '*', '/'" << endl;
        cout << "Whitespace is essential between the different operations." << endl;
        cout << "Stack:" << endl;
        stack.printStack();
        string typedLine;
        getline(cin, typedLine);
        istringstream iss(typedLine);
        string sub;
        while (iss >> sub) {
            if (sub == "q")          //better with switch
            {
                return;
            } else if (sub == "n") {
                iss >> sub;
                stack.putOnStack(stoi(sub));
            } else if (sub == "d") {
                stack.popFromStack();
            } else if (sub == "+") {
                stack.addition();
            } else if (sub == "-") {
                stack.subtraction();
            } else if (sub == "*") {
                stack.multiplication();
            } else if (sub == "/") {
                stack.division();
            } else {
                cout << "No possible input, try again." << endl << "Possibly you forgot some whitespace." << endl;
            }
        }
    }
}

