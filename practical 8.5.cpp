#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;
int main()
{
    map<string, vector<string>> directory;
    int choice;
    string folder_name, file_name;
    while (true) {
        cout << "\nMenu: "<<endl;
        cout << "1. Create Folder "<<endl;
        cout << "2. Add File to Folder "<<endl;
        cout << "3. Show Directory Structure "<<endl;
        cout << "4. Exit "<<endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter folder name: ";
            cin >> folder_name;
            if (directory.find(folder_name) == directory.end()) {
                directory[folder_name] = {};
                cout << "Folder created successfully. "<<endl;
            } else {
                cout << "Folder already exists. "<<endl;
            }

        } else if (choice == 2) {
            cout << "Enter folder name: ";
            cin >> folder_name;
            cout << "Enter file name: ";
            cin >> file_name;

            if (directory.find(folder_name) != directory.end()) {
                directory[folder_name].push_back(file_name);
                cout << "File added successfully. "<<endl;
            } else {
                cout << "Folder not found. Please create the folder first."<<endl;
            }

        } else if (choice == 3) {
            cout << "\nDirectory Structure: "<<endl;

            for (auto it = directory.begin(); it != directory.end(); ++it) {
                cout << "Folder: " << it->first << endl;
                cout << "Files: "<<endl;

                for (const auto& file : it->second) {
                    cout << "  - " << file <<endl;
                }
            }

        } else if (choice == 4) {
            cout << "Exiting program."<<endl;
            break;
        } else {
            cout << "Invalid choice. Try again."<<endl;
        }
    }
    return 0;
}
