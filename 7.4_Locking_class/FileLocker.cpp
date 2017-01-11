#include <vector>
#include <iostream>


using namespace std;

struct FileLocker {
    const char * res;
    FILE *f;

    FileLocker(const char * lockme) : res(lockme) {
        f = fopen(lockme, "a");
//        flockfile(f);
    }

    ~FileLocker()
    {
//        funlockfile(f);
    }
};