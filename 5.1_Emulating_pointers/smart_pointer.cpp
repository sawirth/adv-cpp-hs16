#include <vector>
#include "reference_counting.cpp"

using namespace std;

template<typename T>
class smart_pointer {

private:
    T* pointer;
    reference_counting* reference;

public:
    smart_pointer (): pointer(0), reference(0)
    {
        reference = new reference_counting();
        reference->increase_count();
    }

    smart_pointer (T* point_to): pointer(point_to), reference(0)
    {
        reference = new reference_counting();
        reference->increase_count();
    }

    smart_pointer(const smart_pointer<T>& smart_pointer1): pointer(smart_pointer1.pointer), reference(smart_pointer1.reference)
    {
        reference->increase_count();
    }

    ~smart_pointer(){
        if(reference->decrease_count() == 0){
            delete pointer;
            delete reference;
        }
    }

    T &operator*(){
        return *pointer;
    }

    T* operator->(){
        return pointer;
    }

    smart_pointer<T> &operator=(const smart_pointer<T>& smart_pointer1)
    {
        if (this != &smart_pointer1)
        {
            if(reference->decrease_count() == 0)
            {
                delete pointer;
                delete reference;
            }
            pointer = smart_pointer1.pointer;
            reference = smart_pointer1.reference;
            reference->increase_count();
        }
        return *this;
    }

    int counter(){
        return reference->getReferenceCount();
    }
};