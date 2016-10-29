#include <iostream>
#include <limits>
#include "pset.cpp"
#include "../exercise3.1/persistence_traits.cpp"


using namespace std;

class psetRunner
{
    public:
        void run()
        {
            cout << "Enter path with filename where you want to store your data:" << endl;
            string path = "";
            cin >> path;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            pset<string, persistence_traits<string> > s = pset<string, persistence_traits<string>>(path);

            bool quit = false;
            while(!quit)
            {
                cout << "What do you want to do? a = add, q = quit: ";
                string choice = "";
                cin >> choice;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (choice != "a")
                {
                    quit = true;
                }
                else if (choice == "a")
                {
                    cout << "Enter the message you want to store: ";
                    string msg = "";
                    cin.sync();
                    getline(cin, msg);
                    s.insert(msg);
                }
            }
            }
};