#include <vector>
#include <iostream>
#include <sys/file.h>


using namespace std;

struct FileLocker {
    const char * res;
    FILE *f;
    FileLocker(const char * lockme) : res(lockme) {
        f = fopen(lockme, "r");
        flock(fileno(f), LOCK_EX);
    }

    ~FileLocker()
    {
        flock(fileno(f), LOCK_UN);
    }
};