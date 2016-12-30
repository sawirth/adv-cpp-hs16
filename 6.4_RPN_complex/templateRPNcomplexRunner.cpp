#include <typeinfo>
#include <iostream>
#include "templateRPNcomplex.h"
#include "templateRPNcomplexRunner.h"
#include "complex.h"
#include "complex"


using namespace std;

void templateRPNcomplexRunner::run()
{
    // need to change type of stack here
    templateRPNcomplex<fraction> stack;

    //typeid didn't work anymore so for every type a vector to compare need to be declared
    vector <int> intv;
    vector <fraction> fractionv;
    vector <double> doublev;
    //vector<complex> complexv;


    while(true) {
        cout << "What do you want to do?" << endl;
        cout << "q - quit the program" << endl;
        cout << "n - puts a type you chose on the stack"<< endl;
        cout << "d - removes last number from the stack" << endl;
        cout << "m - gets the minimum from the last two operations" << endl;
        cout << "m2 - gets the minimum from the whole stack (3.3)" << endl;
        cout << "all+ - gets the sum of the whole stack, doesn't really work with fractions (they always get rounded)" << endl;
        cout << "all* - gets the product of the whole stack, doesn't really work with fractions (they always get rounded)" << endl;
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

                //getting the type of our Vector
                if(typeid(stack.getNumberStack())== typeid(intv))
                {
                    stack.putOnStack(stoi(sub));
                }
                /*else if(typeid(stack.getNumberStack())== typeid(complexv)) {
                    stack.putOnStack(sub);
                }*/
                else if(typeid(stack.getNumberStack())== typeid(doublev))
                {
                    stack.putOnStack(stod(sub));
                }
                else if(typeid(stack.getNumberStack())== typeid(fractionv)) {
                    string delimiter = "/";
                    if (sub.find(delimiter) != string::npos) {
                        string ctr = sub.substr(0, sub.find(delimiter));
                        string denom = sub.substr(sub.find(delimiter) + 1, sub.length() - 1);
                        try {
                            int counter = stoi(ctr);
                            int denominator = stoi(denom);
                            if (denominator == 0) {
                                cout << "The denominator can't be zero. Try some other input." << endl;
                            } else {
                                stack.putOnStack(fraction(counter, denominator));
                            }
                        }
                        catch (invalid_argument e) {
                            cout << "invalid_argument exception while parsing: " << ctr << " " << denom << endl;
                            cin.clear();
                        }
                    } else {
                        cout << "No possible Input." << endl
                             << "You need to enter the counter and denominator in the following form: 1/2." << endl;
                    }
                }
                else{
                    cout << "This template-type is not implemented." << endl;
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
            } else if (sub == "all+"){
                stack.allPlus();
            } else if (sub == "all*"){
                stack.allMultiplicate();
            } else {
                cout << "No possible input, try again." << endl << "Be careful with whitespaces!" << endl;
            }
        }
    }
}
