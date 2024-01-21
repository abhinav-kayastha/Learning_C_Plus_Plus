#include "iostream"

using namespace std;

int main() {

    string sentence;
    string choice;

    cout << "Enter a string: ";
    getline(cin, sentence);
    cout << endl;

    cout << "Enter character to replace or 'stop' to stop: ";
    cin >> choice;
    cout << endl;

    if (choice == "stop") {
        return 0;
    }

    else {
        char replacement_char = choice[0];
        for (char character : sentence) {
            if (character == replacement_char) {
                int pos = sentence.find(choice, 0);
                sentence[pos] = '_';
            }
        }
    }

    cout << "Result: " << sentence;

}