#include <iostream>
#include "pset.cpp"

using namespace std;

class psetRunner
{
    public:
        run()
        {
            cout << "Enter path with filename where you want to store your data:" << endl;
            string path = "";
            cin >> path;

            pset<string> s = pset<string>(path);

            bool quit = false;
            while(!quit)
            {
                cout << "What do you want to do? a = add, q = quit: ";
                string choice = "";
                cin >> choice;

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