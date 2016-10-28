#ifndef PSET_CPP
#define PSET_CPP

#include "../exercise3.1/persistence_traits.cpp"
#include <set>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

template<typename T, typename P>
class pset
{
    private:
        set<T> s;
        string filename;

    public:
    typedef P persister;
    typedef typename set<T>::iterator iterator;

        pset(const string &filename) : filename(filename)
        {
            readSet();
        }

        ~pset()
        {
            writeSet();
        }

        const set<T> &getSet() const
        {
            return s;
        }

        void insert(const T &el)
        {
            s.insert(el);
        }

        void readSet()
        {
            ifstream ifs(filename);
            string line;

            while(getline(ifs, line, '\n'))
            {
                persister::read(ifs, line);
                s.insert(line);
            }
        }

        void writeSet()
        {
            ofstream ofs(filename);
            iterator first = s.begin();
            iterator last = s.end();

            while (first != last)
            {
                persister::write(ofs, *first++);
            }
        }

        typename set<T>::iterator find(const T &el)
        {
            return s.find(el);
        }


        bool contains(const T &el)
        {
            return find(el) != s.end();
        }
};

#endif