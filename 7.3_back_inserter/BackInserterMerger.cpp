#include <iostream>


using namespace std;

template<typename T1, typename T2, typename type1>
class BackInserterMerger{
public:
    void merge(T1 &in1, T2 &in2){
        type1 tempValue;
        // push container 2 at the end of container 1
        back_insert_iterator<T1> bi = back_inserter(in1);
        while(!(in2.empty())){
            tempValue = in2.back();
            in2.pop_back();
            bi = tempValue;
        }
    }
};

/*
 differents to the original implementation:
  - we don't build a new container
  -> we push container 2 behind container 1
  -> this makes that container 1 isn't on the head anymore

 original implementation:

template<typename T, typename T2, typename type1>
class merger{
public:
    void merge(T &in1, T2 &in2, T &out){
        type1 tempValue;
        // push container 1 in our new container
        while(!(in1.empty())){
            tempValue = in1.back();
            in1.pop_back();
            out.push_back(tempValue);
        }
        // push container 2 in our new container
        while(!(in2.empty())){
            tempValue = in2.back();
            in2.pop_back();
            out.push_back(tempValue);
        }
    }
};
 */