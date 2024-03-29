#include <iostream>
#include "exercise1/HelloWorld.h"
#include "exercise2/fractionTestDriver.h"
#include "exercise2/interactiveFraction.h"
#include "exercise2.5/pRNPRunner.h"
#include <algorithm>
#include "exercise3/pvectorRunner.cpp"
#include "utils/inputUtils.h"
#include "exercise5/RPNRunner.h"
#include "exercise3.1/pvectorRunner_traits.cpp"
#include "exercise3.1/psetRunner.cpp"
#include "tests/testRunner.cpp"
#include "3.2_spell_checker/spellChecker.h"
#include "3.4_connect4/connect4game.h"
#include "exercise5/RPN.h"
#include "exercise5/RPNRunner.h"
#include "exercise6/templateRPNRunner.h"
#include "exercise4.1/merger.h"
#include <list>
#include "4.1_find_if/find_if_Benchmark.h"
#include "exercise4.5/somefunction_t.cpp"
#include "exercise2.2/inlineFunction.h"
#include "5.1_Emulating_pointers/emulatingPointersRunner.h"
#include "7.2_inheritance_stack/Stack.cpp"
#include "7.2_inheritance_stack/UnlimitedStack.cpp"
#include "7.1_range_checking_iterator/RangeCheckingIterator.cpp"
#include "7.3_back_inserter/BackInserterMerger.cpp"
#include "8.4_constructor_destructor/ConstrDestrDemo.h"
#include "8.2_regex_spell_checker/regexSpellChecker.h"
#include "6.2_mem_fun/demo.h"
#include "9.1_single_manipulator/manipulator.h"
#include "6.4_RPN_complex/templateRPNcomplexRunner.h"

using namespace std;

//Declare exercise functions here and implement them at the end
void runExercise2();
void runExercise3();
void runExercise4();
void runExercise5();
void runExercise6();
void runExercise7();
void runExercise8();
void runExercise9();
void runExercise10();
void runExercise11();
void runExercise12();
void runExercise13();
void runExercise14();
void runExercise15();
void runExercise16();
void runExercise17();
void runExercise18();
void runExercise19();
void runExercise20();
void runExercise21();
void runExercise22();
void runExercise23();

void selectExercise()
{
    cout << "The following exercises are currently implemented:" << endl;
    cout << "0 - tests" << endl;
    cout << "1 - Hello World (1.1)" << endl;
    cout << "2 - Fraction (1.2)" << endl;
    cout << "3 - Persistent vector (2.1)" << endl;
	cout << "4 - Inline (2.2)" << endl;
	cout << "5 - RPN calculator (2.3)" << endl;
	cout << "6 - RPN calculator with templates (2.4), additionally (3.3) is also included" << endl;
	cout << "7 - RPN calculator with persistent vector (2.5)" << endl;
    cout << "8 - pvector_traits with persistence_traits (3.1)" << endl;
    cout << "9 - pset (3.1)" << endl;
    cout << "10 - Spell Checker (3.2)" << endl;
    cout << "11 - Connect 4 (all modes)" << endl;
    cout << "12 - Merging STL Containers" << endl;
    cout << "13 - find_if benchmark" << endl;
    cout << "14 - somefunction_t (4.5)" << endl;
    cout << "15 - Emulating Pointers (5.1)" << endl;
    cout << "16 - Inheritance Stack (7.2)" << endl;
    cout << "17 - Regex spell checker (8.2)" << endl;
    cout << "18 - Range Checking Iterator" << endl;
    cout << "19 - Merging Containers with back_inserter" << endl;
	cout << "20 - Constructor Destructor Execution (8.4)" << endl;
    cout << "21 - std::mem_fun demo (6.2)" << endl;
    cout << "22 - User defined manipulator (9.1)" << endl;
    cout << "23 - RPN calculator with complex numbers" << endl;

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
        case 4:
            runExercise4();
            break;
        case 5:
            runExercise5();
            break;

        case 6:
            runExercise6();
            break;

        case 7:
            runExercise7();
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

        case 11:
            runExercise11();
            break;

        case 12:
            runExercise12();
            break;

        case 13:
            runExercise13();
            break;

        case 14:
            runExercise14();
            break;

        case 15:
            runExercise15();
			break;

        case 16:
            runExercise16();
            break;

        case 17:
            runExercise17();
            break;

        case 18:
            runExercise18();
            break;

        case 19:
            runExercise19();
            break;

		case 20:
			runExercise20();
			break;

        case 21:
            runExercise21();
            break;

        case 22:
            runExercise22();
            break;
            
        case 23:
            runExercise23();
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

void runExercise4()
{
    Polygon *poly = new Rectangle();
    poly->set_values(1, 2);
    cout << poly->area() << '\n';
}

void runExercise5()
{
    RPNRunner r = RPNRunner();
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    r.run();
}

void runExercise6(){
    templateRPNRunner r = templateRPNRunner();
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    r.run();
}

void runExercise7(){
    pRNPRunner r = pRNPRunner();
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    r.run();
}

void runExercise8() {
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

void runExercise11()
{
    connect4game game = connect4game();
    game.startGame();
}

void runExercise12()
{
    // for output type we always take a vector
    // to add other types we need to differ between the different types and handle them differently
    merger<vector<fraction>,list<fraction>,fraction> merger1;
    vector<fraction> v1;
    v1.push_back(fraction(3,4));
    v1.push_back(fraction(5,7));
    v1.push_back(fraction(8,9));
    list<fraction> v2;
    v2.push_back(fraction(1,2));
    v2.push_back(fraction(4,7));
    v2.push_back(fraction(12,13));
    vector<fraction> v3;
    merger1.merge(v1, v2, v3);
    cout << "Our new container contains the values:" << endl;
    for(int i = 0; i < v3.size(); i++){
        cout << v3[i] << endl;
    }
}

void runExercise13()
{
    find_if_Benchmark benchmark = find_if_Benchmark();
    benchmark.run();
}

void runExercise14()
{
    divide_by_2<int, int> div2;
    square<int, int> sqr;
    multiplication<int, int, int> multipl;

    somefunction_t<multiplication<int, int, int>, square<int, int>, divide_by_2<int, int> > func = somefunction_t<multiplication<int, int, int>, square<int, int>, divide_by_2<int, int> >(multipl, sqr, div2);

    //Makes the following calculation: multiplication(divide_by_2(8), square(8))
    // (8 * 8) * (8 / 2) = 256
    cout << func(8) << endl;
}

void runExercise15()
{
    emulatingPointersRunner r = emulatingPointersRunner();
    r.run();
}

void stackSlicing(Stack stack)
{
    cout << "Slicing by value" << endl;

    //Das ruft die print-Methode in der Basisklasse auf und wird somit nur die ersten 256 Elemente ausgeben
    stack.print();
}

void stackSlicing2(Stack &stack)
{
    cout << "Slicing by reference" << endl;

    //Das ruft die print-Methode in der Subklasse auf und wird gibt somit alle Elemente aus
    stack.print();
}

void runExercise16()
{
    UnlimitedStack us = UnlimitedStack();

    for (int i = 0; i < 256; i++)
    {
        us.push(i);
    }

    us.print();

    //Add another 256 elements
    for (int i = 256; i < 512; i++)
    {
        us.push(i);
    }

    us.print();
    stackSlicing(us);
    stackSlicing2(us);
}

void runExercise17()
{
    regexSpellChecker::run();
}

void runExercise18()
{
    vector<int> v1;
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    RangeCheckingIterator<vector<int>::iterator> rangeCheckingIterator(v1.begin(),v1.end());

    try{
    for(;;rangeCheckingIterator++){
        cout << *rangeCheckingIterator << endl;
    }}
    catch (string e){
        cout << e << endl;
    }

     try{
         rangeCheckingIterator--;
         rangeCheckingIterator--;
         rangeCheckingIterator--;
         rangeCheckingIterator--;
         rangeCheckingIterator--;
         rangeCheckingIterator--;
     }
     catch (string e){
         cout << e << endl;
     }
    cout << *rangeCheckingIterator << endl;

}


void runExercise19()
{
    BackInserterMerger<vector<fraction>,list<fraction>,fraction> merger1;
    vector<fraction> v1;
    v1.push_back(fraction(3,4));
    v1.push_back(fraction(5,7));
    v1.push_back(fraction(8,9));
    list<fraction> v2;
    v2.push_back(fraction(1,2));
    v2.push_back(fraction(4,7));
    v2.push_back(fraction(12,13));
    merger1.merge(v1, v2);
    cout << "Our new container contains the values:" << endl;
    for(int i = 0; i < v1.size(); i++){
        cout << v1[i] << endl;
    }
}

void runExercise20()
{
	ConstrDestrDemo::run();
}

void runExercise21()
{
    demo::run();
}

void runExercise22()
{
    manipulator::run();
}

void runExercise23()
{
    templateRPNcomplexRunner r = templateRPNcomplexRunner();
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    r.run();
}