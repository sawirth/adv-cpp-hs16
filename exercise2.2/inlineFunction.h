#ifndef ADV_CPP_HS16_INLINEFUNCTION_H
#define ADV_CPP_HS16_INLINEFUNCTION_H

#include <iostream>
using namespace std;

class Polygon {
protected:
    int width;
    int height;
public:
    void set_values (int a, int b)
    {
        width=a;
        height=b;
    }
    inline virtual int area ()
    {
        return 0;
    }
};

class Rectangle: public Polygon {
public:
    inline int area ()
    {
        return width * height;
    }
};

#endif //ADV_CPP_HS16_INLINEFUNCTION_H
