#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

template<typename T, typename P	>
class pvector_traits
{
	private:
		string filename;
		vector<T> v;

	public:
		typedef P persister;
		typedef typename vector<T>::iterator iterator;

		pvector_traits(string filename) : filename(filename)
		{
			readVector();
		}

		~pvector_traits()
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
				persister::read(ifs, line);
				v.push_back(line);
			}
		}

		void writeVector()
		{
			ofstream ofs(filename);
			iterator first = v.begin();
			iterator last = v.end();

			while (first != last)
			{
				persister::write(ofs, *first++);
			}
		}
};