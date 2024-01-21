//
// Created by abhin on 19/01/2024.
//

#include "iostream"
#include "sstream"

using namespace std;

int main() {

    string decision;


    while (true) {
        cout << "Enter a line with numbers or 'stop': ";
        getline(cin, decision);
        if (decision == "stop")
        {
            cout << "Program Stopped." << endl;
            break;
        }

        istringstream iss(decision);
        int number;
        int sum = 0;
        int count = 0;

        while (iss >> number) {
            sum += number;
            count++;
        }

        cout << "Total of " << count << " numbers is " << sum << endl;
    }

}