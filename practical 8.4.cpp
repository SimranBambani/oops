#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    int no_of_students;
    cout << "Enter number of students: ";
    cin >> no_of_students;
    vector<pair<string, int>> students;
    string name;
    int score;
    for (int i = 0; i < no_of_students;i++) {
        cout << "Enter name and score for student " << i + 1 << ": ";
        cin >> name >> score;
        students.push_back({name, score});
    }
    sort(students.begin(), students.end(),
              [](const pair<string, int>& a, const pair<string, int>& b) {
                  return a.second > b.second;
                  });
    cout << "\nRanked Student List:" <<endl;
    int rank = 1;
    for (auto it = students.begin(); it != students.end(); ++it) {
        cout << "Rank " << rank << ": " << it->first << " (Score: " << it->second <<endl;
        ++rank;
    }
    return 0;
}
