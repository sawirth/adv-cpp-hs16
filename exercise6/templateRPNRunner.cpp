#include <iostream>
#include "templateRPN.h"
#include "templateRPNRunner.h"
#include "../utils/inputUtils.h"
#include "../exercise2/fraction.h"
using namespace std;

void templateRPNRunner::run()
{
    // need to change type of stack here
    templateRNP<fraction> stack;

    while(true) {
        cout << "What do you want to do?" << endl;
        cout << "q - quit the program" << endl;
        cout << "n - puts a type you chose"<< endl;
        cout << "d - removes last number from the stack" << endl;
        cout << "m - gets the minimum from the last two operations" << endl;
        cout << "Or just simply do some operations on the last two numbers from the stack: '+', '-', '*', '/'" << endl;
        cout << "Whitespace is essential between the different operations." << endl;
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
                if(typeid(stack.getNumberStack())== typeid(int))
                {
                    stack.putOnStack(stoi(sub));
                }
                else if(typeid(stack.getNumberStack())== typeid(double))
                {
                    stack.putOnStack(stod(sub));
                }
                else if(typeid(stack.getNumberStack())== typeid(fraction))
                {
                int nominator = (stoi(sub));
                iss >> sub;
                fraction fraction1 = fraction(nominator, stoi(sub));
                stack.putOnStack(fraction1);
                }
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
            } else if (sub == "m") {
                stack.myMin();
            /*} else if (sub == "all+"){
                stack.allPlus();
            } else if (sub == "all*"){
                    stack.allMultiplicate();*/
            } else {
                    cout << "No possible input, try again." << endl << "Possibly you forgot some whitespace." << endl;
            }
            }
        }
    }
