#include "iostream"
#include <string>

using namespace std;

// Function to replace all occurrences of a character with underscores
void replaceCharWithUnderscore(string &str, char replaceChar) {
    for (char &character : str) {
        if (character == replaceChar) {
            character = '_';
        }
    }
}

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
    } else {
        char replacement_char = choice[0];

        // Call the function to replace occurrences of the character with underscores
        replaceCharWithUnderscore(sentence, replacement_char);
    }

    cout << "Result: " << sentence;

    return 0;
}