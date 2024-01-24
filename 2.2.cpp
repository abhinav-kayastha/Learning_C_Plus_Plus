//
// Created by abhin on 24/01/2024.
//

#include "iostream"
#include "filesystem"
#include "vector"
#include "string"
#include "fstream"

using namespace std;

int main() {
    vector<string> vector_of_dir_names;

    while (true) {
        string dir_name;
        cout << "Enter a directory name: ";
        getline(cin, dir_name);

        if (dir_name.empty()) {
            break;
        }

        else {
            vector_of_dir_names.push_back(dir_name);
        }
    }

    filesystem::path base_path = "C:\\Users\\abhin\\Desktop\\";
    filesystem::path full_path = base_path;

    for (const string& name : vector_of_dir_names) {
        full_path += name + "\\";
        filesystem::create_directory(full_path);
    }

    filesystem::path result_file_path = full_path += "result.txt";
    ofstream result_file(result_file_path);

    cout << "Absolute path to the file: " << filesystem::absolute(result_file_path);
    result_file << "Absolute path to the file: " << filesystem::absolute(result_file_path) << endl;

    cout << endl << "Content of the string vector:" << endl;

    for (const string &name : vector_of_dir_names) {
        cout << name << endl;
        result_file << name << endl;
    }

    cout << endl << "Relative path to the file: " << filesystem::relative(result_file_path, base_path) << endl;
    result_file << endl << "Relative path to the file: " << filesystem::relative(result_file_path, base_path) << endl;

    result_file.close();
}