#include <iostream>
#include <limits>
#include "pRNP.h"
#include "../exercise2/fraction.h"
#include "pRNPRunner.h"

using namespace std;

void pRNPRunner::run()
{
    cout << "Enter path with filename where you want to store your data:" << endl;
    string path = "";
    cin >> path;

    // need to change type of stack here
    pRNP <fraction> pRNP(path);
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //typeid didn't work anymore so for every type a vector to compare need to be declared
    vector <int> intv;
    vector <fraction> fractionv;
    vector <double> doublev;

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

                //getting the type of our Vector
                if(typeid(pRNP.getNumberStack())== typeid(intv))
                {
                    pRNP.putOnStack(stoi(sub));
                }
                else if(typeid(pRNP.getNumberStack()) == typeid(doublev))
                {
                    pRNP.putOnStack(stod(sub));
                }
                else if(typeid(pRNP.getNumberStack()) == typeid(fractionv))
                {
                    string delimiter = "/";
                    if (sub.find(delimiter) != string::npos)
                    {
                        string ctr = sub.substr(0, sub.find(delimiter));
                        string denom = sub.substr(sub.find(delimiter) + 1, sub.length() - 1);
                        try {
                            int counter = stoi(ctr);
                            int denominator = stoi(denom);
                            if (denominator == 0){
                                cout << "The denominator can't be zero. Try some other input." << endl;
                            }
                            else{
                            pRNP.putOnStack(fraction(counter, denominator));}
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
                else{
                    cout << "This template-type is not implemented." << endl;
                }
            } else if (sub == "d")
            {
                pRNP.popFromStack();
            } else if (sub == "+")
            {
                pRNP.addition();
            } else if (sub == "-")
            {
                pRNP.subtraction();
            } else if (sub == "*")
            {
                pRNP.multiplication();
            } else if (sub == "/")
            {
                pRNP.division();
            } else if (sub == "m")
            {
                pRNP.myMin();
            } else
            {
                cout << "No possible input, try again." << endl << "Be careful with whitespaces!" << endl;
            }
        }
    }
}
