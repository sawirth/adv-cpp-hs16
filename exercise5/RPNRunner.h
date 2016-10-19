#ifndef ADV_CPP_HS16_RPNRUNNER_H
#define ADV_CPP_HS16_RPNRUNNER_H

#include <vector>
#include <iostream>
#include "RPN.h"

using namespace std;

class RPNRunner {
private:
    RPN stack;
public:
    void run();
};

#endif //ADV_CPP_HS16_RPNRUNNER_H
