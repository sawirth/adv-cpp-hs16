#include <limits>
#include "pvector.cpp"

class pvectorRunner
{
	public:
		void run()
		{
			cout << "Enter path with filename where you want to store your data:" << endl;
			string path = "";
			cin >> path;

			pvector<string> v = pvector<string>(path);
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

			bool quit = false;
			while(!quit)
			{
				cout << "What do you want to do?" << endl;
				cout << "a(dd) - p(op) - d(elete) - q(uit)" << endl;
				string choice = "";
				cin >> choice;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				if (choice == "q")
				{
					quit = true;
				}
				else if (choice == "a")
				{
					cout << "Enter the message you want to store: ";
					string msg = "";
					cin.sync();
					getline(cin, msg);
					v.push_back(msg);
				}
				else if (choice == "p")
				{
					if (!v.getVector().empty())
					{
						string msg = v.getVector()[v.getVector().size() - 1];
						cout << "Removed message: " << msg << endl;
						v.pop_back();
					}
				}
			}
		}
};

