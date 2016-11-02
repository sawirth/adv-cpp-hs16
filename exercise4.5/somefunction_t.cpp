#include <functional>
#include <iostream>

using namespace std;

template <class BinOp, class Op1, class Op2>
class somefunction_t :
        public unary_function<typename Op1::argument_type,
                typename BinOp::result_type> {
protected:
    BinOp o; Op1 o1; Op2 o2;
public:
    somefunction_t(BinOp binop, Op1 op1, Op2 op2)
            : o(binop), o1(op1), o2(op2) {}
    typename BinOp::result_type
    operator()(const typename Op1::argument_type &x) {
        return o(o1(x),o2(x));
    }
};


struct multiplication {
public:
    int operator()(int arg0, int arg1) {
        return arg0 * arg1;
    }
};

struct divide_by_2 {
public:
    int operator()(int arg) {
        return arg / 2;
    }
};

struct square {
public:
    int operator()(int arg) {
        return arg * arg;
    }
};
