#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

class Stack
{
	private:
		int buf[256], sp;

	public:
		Stack()
		{
			sp = 256;
		}

		virtual void push(int i)
		{
			buf[--sp] = i;
		}

		virtual int pop()
		{
			return buf[sp++];
		}

		virtual int empty()
		{
			return sp == 256;
		}

		virtual void print()
		{
			cout << "Print array" << endl;
			for (int i = 256 - 1; i >= sp; i--)
			{
				cout << buf[i] << " ";
			}
		}
};

#endif
