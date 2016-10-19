#include "pvector_traits.cpp"
#include "persistence_traits.cpp"

class pvectorRunner_traits
{
	public:
		void run()
		{
			cout << "Enter path with filename where you want to store your data:" << endl;
			string path = "";
			cin >> path;

			pvector_traits<string, persistence_traits<string> > v = pvector_traits<string, persistence_traits<string> >(path);

			bool quit = false;
			while(!quit)
			{
				cout << "What do you want to do?" << endl;
				cout << "a(dd) - p(op) - d(elete) - q(uit)" << endl;
				string choice = "";
				cin >> choice;

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

