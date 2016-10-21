#ifndef PSET_CPP
#define PSET_CPP

#include <set>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

template<typename T>
class pset
{
    private:
        set<T> s;
        string filename;

    public:
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
                istringstream iss(line);
                s.insert(line);
            }
        }

        void writeSet()
        {
            ofstream ofs(filename);
            typename set<T>::iterator first = s.begin();
            typename set<T>::iterator last = s.end();

            while (first != last)
            {
                ofs << *first++ << endl;
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