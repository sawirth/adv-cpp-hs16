#include <vector>
#include <iostream>
#include "RPN.h"
#include "RPNRunner.h"

using namespace std;

void RPNRunner::run()
{
    cout << "What do you want to do?" << endl;
    cout << "q - quit the program" << endl;
    cout << "n - puts a number you chose afterwards on the stack"<< endl;
    cout << "d - removes last number from the stack" << endl;
    cout << "Or just simply do some operations on the last two numbers from the stack: '+', '-', '*', '/'" << endl;
    string choice = "";
    getline(cin,choice);
    /*switch(choice)
           {
               case "j":
                   cout <<"sfas";
               default:                    break;
            }*/
    if (choice == "q")          //better with switch
    {
        return;
    }
    else if (choice == "n")
    {
        stack.putOnStack();
    }
    else if (choice == "d")
    {
        stack.popFromStack();
    }
    else if(choice == "+")
    {
        stack.addition();
    }
    else if(choice == "-")
    {
        stack.subtraction();
    }
    else if(choice == "*")
    {
        stack.multiplication();
    }
    else if(choice == "/")
    {
        stack.division();
    }
    else
    {
        cout << "No possible input, try again." << endl;
    }
    run();
}

