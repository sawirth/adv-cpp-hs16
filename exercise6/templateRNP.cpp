#include <vector>
#include "templateRNP.h"
#include "../utils/inputUtils.h"

using namespace std;

/*void templateRNP::addition()
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

void TemplateRNP::subtraction()
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
void TemplateRNP::multiplication()
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

void TemplateRNP::division()
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

void TemplateRNP::putOnStack()
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

void TemplateRNP::popFromStack()
{
    if (!numberStack.empty())
    {
        int numb = numberStack[numberStack.size() - 1];
        cout << "Removed message: " << numb << endl;
        numberStack.pop_back();
    }
    else
    {
        cout << "Stack is empty." << endl;
    }
}
*/
