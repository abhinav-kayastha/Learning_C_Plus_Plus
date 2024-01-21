#include <iostream>
#include <vector>

using namespace std;

int main() {

    int amount;

    cout << "How many numbers do you want to enter: ";
    cin >> amount;
    cout << endl;

    vector<int> vector_of_nums(amount);

    for (int i = 0; i < amount; i++) {
        int num;
        cout << "Enter vector_of_nums[" << i << "]: ";
        cin >> num;
        vector_of_nums[i] = num;
    }

    cout << endl << "You entered: ";

    for (int num : vector_of_nums) {
        cout << num << " ";
    }

    return 0;
}