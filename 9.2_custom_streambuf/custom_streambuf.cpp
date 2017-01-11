#include <streambuf>
#include <iostream>

using namespace std;

class custom_streambuf : public streambuf {
    /*char buf[256];
    ostream *os;
    streambuf *basebuf;
    int off; public:
    custom_streambuf(ostream &os, int off=13) : os(&os), basebuf(os.rdbuf(this)), off(off) { setp(buf, buf+sizeof(buf)); }
    virtual ~encbuf() { if (os!=NULL) owner->rdbuf(basebuf);} */};