#include "emulatingPointersRunner.h"
#include <iostream>
#include "tester.cpp"
using namespace std;


void print(smart_pointer<int> p){
    std::cout << p.counter() << ": " << *p << endl;
}

void print(dumb_pointer<int> p){
    std::cout << *p << endl;
}

void emulatingPointersRunner::run() {

    cout << "Test 1 :" << endl;

    int *o1=new int(1);
    int *o2=new int(2);
    smart_pointer<int> p(o1);
    cout << p.counter() << endl;
    smart_pointer<int> q(p);
    cout << p.counter() << endl;
    cout << q.counter() << endl;
    smart_pointer<int> r(o2);
    cout << r.counter() << endl;
    q=r;
    cout << p.counter() << endl;
    cout << q.counter() << endl;
    cout << r.counter() << endl;
    print(p); print(q); print(r);
    cout << *p << *r << endl;

    cout << endl << "Test 2 :" << endl;

    tester *t1 = new tester();
    tester *t2= new tester();
    smart_pointer<tester> sp(t1);
    smart_pointer<tester> sp2(sp);
    smart_pointer<tester> sp3(t2);
    sp2=sp3;
    cout << sp->method1() << sp2->method2() << sp3->method3() << endl;

    cout << endl << "Test 3 :" << endl;

    smart_pointer<int> smart1(new int(25));
    print(smart1);
    {
        smart_pointer<int> smart2 = smart1;
        print(smart2);
            // Destructor of smart2 will be called here..
    }
    print(smart1);

    /*dumb_pointer<int> dumb1(new int(25));
    print(dumb1);
    {
        dumb_pointer<int> dumb2 = dumb1;
        print(dumb2);
        // Destructor of dumb2 will be called here..
    }
    print(dumb1);*/

    // -> would print an error because dumb1 refers to nothing
    // destructor also doesn't work


}