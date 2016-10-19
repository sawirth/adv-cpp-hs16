//
// Created by Sandro on 19.10.2016.
//
#include <fstream>
#include <sstream>

using namespace std;

template<typename T>
struct persistence_traits {
    static void read(ifstream &ifstream, T &element)
    {

    }

    static void write(ofstream &ofstream, const T &element)
    {
        ofstream << element << endl;
    }
};

template<>
struct persistence_traits<string>
{
    static void read(ifstream &ifstream, string &element)
    {
        istringstream iss(element);
    }

    static void write(ofstream &ofstream, const string &element)
    {
        ofstream << element << endl;
    }
};