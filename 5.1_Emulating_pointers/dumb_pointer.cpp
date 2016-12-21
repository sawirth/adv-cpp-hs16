#include <vector>

using namespace std;

template<typename T>
class dumb_pointer {

private:
    T* pointer;

public:
    dumb_pointer (): pointer(0)
    {
    }

    dumb_pointer (T* point_to): pointer(point_to)
    {
    }

    ~dumb_pointer(){
        delete pointer;
    }

    T &operator*(){
        return *pointer;
    }

    T* operator->(){
        return pointer;
    }
};