#include <vector>

using namespace std;

class reference_counting {

private:
    int reference_count;

public:
    void increase_count() {
        reference_count++;
    }

    int decrease_count() {
        return --reference_count;
    }

    int getReferenceCount(){
            return reference_count;
    }
};