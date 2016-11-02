#ifndef ADV_CPP_HS16_PVECTORRNP_H
#define ADV_CPP_HS16_PVECTORRNP_H

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <typeinfo>

using namespace std;

template<typename T>
class pvectorRNP
{
private:
    string filename;
    vector<T> v;

public:
    pvectorRNP(string filename) : filename(filename)
    {
        readVector();
    }

    ~pvectorRNP()
    {
        writeVector();
    }

    const vector<T> &getVector() const
    {
        return v;
    }

    void push_back(const T &el)
    {
        v.push_back(el);
    }

    void pop_back()
    {
        v.pop_back();
    }

    void readVector()
    {
        ifstream ifs(filename);
        string line;

        //typeid didn't work anymore so for every type a vector to compare need to be declared
        vector <int> intv;
        vector <fraction> fractionv;
        vector <double> doublev;

        while(getline(ifs, line, '\n'))
        {
            istringstream iss(line);
            string sub;
            if(typeid(v) == typeid(intv)){
                while(iss >> sub) {
                    v.push_back(stoi(sub));
                }
            }
            else if(typeid(v) == typeid(doublev)){
                while(iss >> sub){
                    v.push_back(stod(sub));
                }
            }
            else if(typeid(v) == typeid(fractionv)) {
                string delimiter = "/";
                while (iss >> sub) {
                    if (sub.find(delimiter) != string::npos) {
                        string ctr = sub.substr(0, sub.find(delimiter));
                        string denom = sub.substr(sub.find(delimiter) + 1, sub.length() - 1);
                        try {
                            int counter = stoi(ctr);
                            int denominator = stoi(denom);
                            v.push_back(fraction(counter, denominator));
                        }
                        catch (invalid_argument e) {
                            cout << "invalid_argument exception while parsing: " << ctr << " " << denom << endl;
                            cin.clear();
                        }
                    }
                }
            }
        }
    }

    void writeVector()
    {
        ofstream ofs(filename);
        typename vector<T>::iterator first = v.begin();
        typename vector<T>::iterator last = v.end();

        while (first != last)
        {
            ofs << *first++ << endl;
        }
    }
};

#endif //ADV_CPP_HS16_PVECTORRNP_H
