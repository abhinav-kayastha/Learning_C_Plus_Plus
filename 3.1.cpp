//
// Created by abhin on 23/01/2024.
//

#include "iostream"
#include "map"
#include "utility"

using namespace std;

int main() {
    string decision;
    map<string, int> nameNum;
    map<string, int>::iterator it = nameNum.begin();
    // inserts key value pairs using make_pair func.: nameNum.insert(make_pair("yeet", 1));

    while (true) {
        cout << "Enter name or 'stop' or 'print': " << endl;
        getline(cin, decision);

        if (decision == "stop") {
            cout << "Stopping program.";
            break;
        }

        else if (decision == "print") {
            it = nameNum.begin();
            while (it != nameNum.end()) {
                cout << it->first << " : " << it->second << endl;
                it++;
            }
        }

        else {
            int num;
            cout << "Enter integer: ";
            cin >> num;
            nameNum.insert(make_pair(decision, num));
            cin.ignore();
        }
    }
}