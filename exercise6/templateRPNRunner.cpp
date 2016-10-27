#include <typeinfo>
#include <iostream>
#include "templateRPN.h"
#include "templateRPNRunner.h"

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
        cout << "m2 - gets the minimum from the whole stack (3.3)" << endl;
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
                    string delimiter = "/";
                    if (sub.find(delimiter) != string::npos)
                    {
                        string ctr = sub.substr(0, sub.find(delimiter));
                        string denom = sub.substr(sub.find(delimiter) + 1, sub.length() - 1);
                        try {
                            int counter = stoi(ctr);
                            int denominator = stoi(denom);
                            stack.putOnStack(fraction(counter, denominator));
                        }
                        catch (invalid_argument e)
                        {
                            cout << "invalid_argument exception while parsing: " << ctr << " " << denom << endl;
                            cin.clear();
                        }
                    } else
                    {
                        cout << "No possible Input." << endl << "You need to enter the counter and denominator in the following form: 1/2." << endl;
                    }
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
            } else if (sub == "m2") {
                stack.myMin2();
            /*} else if (sub == "all+"){
                stack.allPlus();
            } else if (sub == "all*"){
                    stack.allMultiplicate();*/
            } else {
                    cout << "No possible input, try again." << endl << "Be careful with whitespaces!" << endl;
            }
            }
        }
    }
