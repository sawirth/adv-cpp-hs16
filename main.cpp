
#include <iostream>
#include "exercise1/HelloWorld.h"
#include "exercise2/fractionTestDriver.h"
#include "exercise2/interactiveFraction.h"
#include <algorithm>
#include "exercise3/pvectorRunner.cpp"

using namespace std;

void runExercise2();
void runExercise3();

void selectExercise()
{
    cout << "The following exercises are currently implemented:" << endl;
    cout << "1 - Hello World" << endl;
    cout << "2 - Fraction" << endl;
    cout << "3 - Persistent vector" << endl;

    int exerciseNumber = 0;
    cout << "Please enter the number of the exercise that you want to run: ";
    cin >> exerciseNumber;

    if (cin.fail()) {
        cout << "You didn't enter a number, please try again" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        selectExercise();
    }

    switch (exerciseNumber)
    {
        case 1:
            helloWorld();
            break;

        case 2:
            runExercise2();
            break;

        case 3:
			runExercise3();
            break;

        default:
            cout << "Exercise " << exerciseNumber << " does not exist" << endl;
            cin.clear();
            selectExercise();
            break;
    }

    string answer;
    cout << endl;
    cout << "Do you want to run another exercise? y/n: ";
    cin >> answer;
    transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

    if (answer == "y")
    {
        selectExercise();
    }

    cout << "Okay bye bye :)" << endl;
    return;
}

int main() {
    cout << "=====================================================" << endl;
    cout << "======= WELCOME TO THE ADVANCED C++ EXERCISES =======" << endl;
    cout << "=====================================================" << endl;

    cout << endl;
    cout << endl;

    selectExercise();

    return 0;
}

void runExercise2() {

    cout << "Press 1 for test driver and 2 for interactive testing: ";
    int num;
    cin >> num;

    if (cin.fail()) {
        cout << "You didn't enter a number, please try again" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        runExercise2();
    }

    if (num == 1)
	{
        auto testDriver = fractionTestDriver();
        testDriver.run();
    }
	else if (num == 2)
	{
		auto interactive = interactiveFraction();
		interactive.run();
    }
}

void runExercise3()
{
	pvectorRunner r = pvectorRunner();
	r.run();
}

