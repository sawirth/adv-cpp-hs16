#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "../utils/inputUtils.h"

using namespace std;

class RPNRunner
{
    private:
        vector <int> numberStack;
    public:
        void run()
        {
            cout << "What do you want to do?" << endl;
            cout << "q - quit the program" << endl;
            cout << "n - puts a number you chose afterwards on the stack"<< endl;
            cout << "d - removes last number from the stack" << endl;
            cout << "Or just simply do some operations on the last two numbers from the stack: '+', '-', '*', '/'" << endl;
            string choice = "";
            getline(cin,choice);
            if (choice == "q")          //better with switch
            {
                return;
            }
            else if (choice == "n")
            {
                while(true)
                {
                    cout << "Enter the number you want to put on the stack: ";
                    int number;
                    number = utils::inputUtils::getInt();

                    if (cin.fail())
                    {
                        cout << "You didn't enter a number, please enter a number:" << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    else
                    {
                        numberStack.push_back(number);
                        break;
                    }
                }
            }
            else if (choice == "d")
            {
                if (!numberStack.empty())
                {
                    int numb = numberStack[numberStack.size() - 1];
                    cout << "Removed message: " << numb << endl;
                    numberStack.pop_back();
                }
            }
            else if(choice == "+")
            {
                int numb1 = 0;
                int numb2 = 0;
                if (!numberStack.empty()) {
                    numb1 = numberStack[numberStack.size() - 1];
                    numberStack.pop_back();
                }
                if (!numberStack.empty()) {
                    numb2 = numberStack[numberStack.size() - 1];
                    numberStack.pop_back();
                } else {
                    cout << "Stack doesn't have 2 numbers to sum up" << endl;
                    return;
                }
                cout << numb1 << " + " << numb2 << " = " << numb1 + numb2 << endl;
                numberStack.push_back(numb1 + numb2);
            }
            else if(choice == "-")
            {
                int numb1 = 0;
                int numb2 = 0;
                if (!numberStack.empty()) {
                    numb1 = numberStack[numberStack.size() - 1];
                    numberStack.pop_back();
                }
                if (!numberStack.empty()) {
                    numb2 = numberStack[numberStack.size() - 1];
                    numberStack.pop_back();
                } else {
                    cout << "Stack doesn't have 2 numbers to subtract" << endl;
                    return;
                }
                cout << numb1 << " - " << numb2 << " = " << numb1 - numb2 << endl;
                numberStack.push_back(numb1 - numb2);
            }
            else if(choice == "*")
            {
                int numb1 = 0;
                int numb2 = 0;
                if (!numberStack.empty()) {
                    numb1 = numberStack[numberStack.size() - 1];
                    numberStack.pop_back();
                }
                if (!numberStack.empty()) {
                    numb2 = numberStack[numberStack.size() - 1];
                    numberStack.pop_back();
                } else {
                    cout << "Stack doesn't have 2 numbers to multiply" << endl;
                    return;
                }
                cout << numb1 << " * " << numb2 << " = " << numb1 * numb2 << endl;
                numberStack.push_back(numb1 * numb2);
            }
            else if(choice == "/")
            {
                int numb1 = 0;
                int numb2 = 0;
                if (!numberStack.empty()) {
                    numb1 = numberStack[numberStack.size() - 1];
                    numberStack.pop_back();
                }
                if (!numberStack.empty()) {
                    numb2 = numberStack[numberStack.size() - 1];
                    numberStack.pop_back();
                } else {
                    cout << "Stack doesn't have 2 numbers to divide" << endl;
                    return;
                }
                cout << numb1 << " / " << numb2 << " = " << numb1 / numb2 << endl;
                numberStack.push_back(numb1 / numb2);
            }
            else
            {
                cout << "No possible input, try again." << endl;
            }
            run();
        }
};
