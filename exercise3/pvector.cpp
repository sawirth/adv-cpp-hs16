#ifndef PVECTOR_CPP
#define PVECTOR_CPP

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

template<typename T>
class pvector
{
	private:
		string filename;
		vector<T> v;

		void write(const string filename)
		{
			ofstream ofs(filename);
			typename vector<T>::iterator first = v.begin();
			typename vector<T>::iterator last = v.end();

			while (first != last)
			{
				ofs << *first++ << endl;
			}
		}

	public:
		pvector(string filename) : filename(filename)
		{
			readVector();
		}

		~pvector()
		{
			writeVector();
		}

		const vector<T> &getVector() const
		{
			return v;
		}

		void setVector(const vector<T> &v)
		{
			pvector::v = v;
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

			while(getline(ifs, line, '\n'))
			{
				istringstream iss(line);
				v.push_back(line);
			}
		}

		void writeVector()
		{
			write(filename);
		}

		void writeVectorToNewFile(const string newFileName)
		{
			write(newFileName);
		}

		typename vector<T>::iterator erase(typename vector<T>::const_iterator position)
		{
			return v.erase(position);
		}

		typename vector<T>::iterator insert(typename vector<T>::const_iterator position, T &element)
		{
			return v.insert(position, element);
		}
};

#endif