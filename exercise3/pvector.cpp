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
//			for(;;)
//			{
//				T x;
//				ifs >> x;
//
//				if (!ifs.good())
//				{
//					break;
//				}
//
//				v.push_back(x);
//			}
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