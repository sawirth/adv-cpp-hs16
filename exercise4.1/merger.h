#ifndef ADV_CPP_HS16_MERGER_H
#define ADV_CPP_HS16_MERGER_H

#include <vector>

using namespace std;

template<typename T, typename T2, typename type1>
class merger{
public:
    void merge(T &in1, T2 &in2, T &out){
        type1 tempValue;
        while(!(in1.empty())){
            tempValue = in1.back();
            in1.pop_back();
            out.push_back(tempValue);
        }
        while(!(in2.empty())){
            tempValue = in2.back();
            in2.pop_back();
            out.push_back(tempValue);
        }
    }
};

#endif //ADV_CPP_HS16_MERGER_H
