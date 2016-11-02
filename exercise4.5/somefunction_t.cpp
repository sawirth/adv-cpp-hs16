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

template<class Arg1, class Arg2, class Res>
class multiplication {
	public:
		typedef Arg1 first_argument_type;
		typedef Arg2 second_argument_type;
		typedef Res result_type;

		result_type operator()(first_argument_type arg1, second_argument_type arg2) {
			return arg1 * arg2;
		}
};

template<class Arg, class Res>
class divide_by_2 {
	public:
		typedef Arg argument_type;
		typedef Res result_type;

		result_type operator()(argument_type arg) {
			return arg / 2;
		}
};

template<class Arg, class Res>
class square {
	public:
		typedef Arg argument_type;
		typedef Res result_type;

		result_type operator()(argument_type arg) {
			return arg * arg;
		}
};
