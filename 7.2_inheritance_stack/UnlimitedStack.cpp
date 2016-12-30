#include "Stack.cpp"
#include <iostream>

using namespace std;

class UnlimitedStack : public Stack
{
	private:
		int *unlimitedBuf;
		int unlimitedSp, size;

		void increaseBuf()
		{
			int newBuf[size * 2];
			for (int i = size; i < size * 2; i++)
			{
				newBuf[i] = unlimitedBuf[i - size];
			}

			unlimitedBuf = new int[size * 2];
			for (int i = size; i < size * 2; i++)
			{
				unlimitedBuf[i] = newBuf[i];
			}

			unlimitedSp += size;
			size *= 2;
			cout << "\nSize increased from " << size << " to " << size * 2 << endl;
		}

	public:
		UnlimitedStack()
		{
			Stack();
			size = 256;
			unlimitedBuf = new int[size];
			unlimitedSp = 256;
		}

		virtual void push(int i) override
		{
			if (unlimitedSp == 0)
			{
				increaseBuf();
			}

			if (size <= 256)
			{
				Stack::push(i);
			}

			unlimitedBuf[--unlimitedSp] = i;
		}

		virtual int pop() override
		{
			Stack::pop();
			return unlimitedBuf[unlimitedSp++];
		}

		virtual int empty() override
		{
			return unlimitedSp == size;
		}

		virtual void print() override
		{
			cout << "Print array" << endl;
			for (int i = size - 1; i >= unlimitedSp; i--)
			{
				cout << unlimitedBuf[i] << " ";
			}
		}
};

