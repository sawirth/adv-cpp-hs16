#include <iostream>
#include "exercise1/HelloWorld.h"
#include "exercise2/fractionTestDriver.h"
#include "exercise2/interactiveFraction.h"
#include <algorithm>
#include "exercise3/pvectorRunner.cpp"
#include "utils/inputUtils.h"
#include "exercise5/RPNRunner.h"
#include "exercise3.1/pvectorRunner_traits.cpp"
#include "exercise3.1/psetRunner.cpp"
#include "tests/testRunner.cpp"
#include "3.2_spell_checker/spellChecker.h"

using namespace std;

//Declare exercise functions here and implement them at the end
void runExercise2();
void runExercise3();
void runExercise5();
void runExercise8();
void runExercise9();
void runExercise10();

void selectExercise()
{
    cout << "The following exercises are currently implemented:" << endl;
    cout << "0 - tests" << endl;
    cout << "1 - Hello World (1.1)" << endl;
    cout << "2 - Fraction (1.2)" << endl;
    cout << "3 - Persistent vector (2.1)" << endl;
	cout << "4 - Inline (2.2)" << endl;
	cout << "5 - RPN calculator (2.3)" << endl;
	cout << "6 - RPN calculator with templates (2.4)" << endl;
	cout << "7 - RPN calculator with persistent vector (2.5)" << endl;
    cout << "8 - pvector_traits with persistence_traits (3.1)" << endl;
    cout << "9 - pset (3.1)" << endl;
    cout << "10 - Spell Checker (3.2)" << endl;

    int exerciseNumber = 0;
    cout << "Please enter the number of the exercise that you want to run: ";
    exerciseNumber = utils::inputUtils::getInt();

    if (cin.fail())
	{
        cout << "You didn't enter a number, please try again" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        selectExercise();
        return;
    }

	//Add a switch case for each exercise. Best way is to run a separate method so the switch-statement stays short
    switch (exerciseNumber)
    {
        case 0:
            TestRunner::runTests();
            break;

        case 1:
            helloWorld();
            break;

        case 2:
            runExercise2();
            break;

        case 3:
			runExercise3();
            break;

        case 5:
            runExercise5();
            break;

        case 8:
            runExercise8();
            break;

        case 9:
            runExercise9();
            break;

        case 10:
            runExercise10();
            break;

        default:
            cout << "Exercise " << exerciseNumber << " does not exist" << endl;
            cin.clear();
            selectExercise();
            return;
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
    else
    {
        cout << "Okay bye bye :)" << endl;
    }
    return;
}

int main()
{
    cout << "=====================================================" << endl;
    cout << "======= WELCOME TO THE ADVANCED C++ EXERCISES =======" << endl;
    cout << "=====================================================" << endl;
    cout << endl;
    cout << endl;

    selectExercise();

    return 0;
}

void runExercise2()
{
    cout << "Press 1 for test driver and 2 for interactive testing: ";
    int num;
    cin >> num;

    if (cin.fail())
	{
        cout << "You didn't enter a number, please try again" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        runExercise2();
    }

    if (num == 1)
	{
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');        auto testDriver = fractionTestDriver();
        testDriver.run();
    }
	else if (num == 2)
	{
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
		auto interactive = interactiveFraction();
		interactive.run();
    }
}

void runExercise3()
{
	pvectorRunner r = pvectorRunner();
	r.run();
}

void runExercise5(){
    RPNRunner r = RPNRunner();
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    r.run();
}

void runExercise8()
{
    pvectorRunner_traits r = pvectorRunner_traits();
    r.run();
}

void runExercise9()
{
    psetRunner r = psetRunner();
    r.run();
}

void runExercise10()
{
    spellChecker::run();
}