#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
class Student_Report {
private:
    string* names;
    float* marks;
    char* grades;
    int count;
    int capacity;

    void resize() {
        capacity *= 2;
        string* newNames = new string[capacity];
        float* newMarks = new float[capacity];
        char* newGrades = new char[capacity];

        for (int i = 0; i < count; ++i) {
            newNames[i] = names[i];
            newMarks[i] = marks[i];
            newGrades[i] = grades[i];
        }

        delete[] names;
        delete[] marks;
        delete[] grades;

        names = newNames;
        marks = newMarks;
        grades = newGrades;
    }
public:
    Student_Report(int initialSize = 5) {
        capacity = initialSize;
        count = 0;
        names = new string[capacity];
        marks = new float[capacity];
        grades = new char[capacity];
    }

    ~Student_Report() {
        delete[] names;
        delete[] marks;
        delete[] grades;
    }

    void Load_From_File(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Error: Cannot open file " << filename << endl;
            return;
        }

        while (file >> names[count] >> marks[count] >> grades[count]) {
            count++;
            if (count >= capacity) {
                resize();
            }
        }

        file.close();
    }

    void Display_Report() const {
        cout << left << setw(15) << "Name"
             << setw(10) << "Marks"
             << setw(10) << "Grade" << endl;
        cout << string(35, '-') << endl;

        for (int i = 0; i < count; ++i) {
            cout << left << setw(15) << names[i]
                 << setw(10) << fixed << setprecision(1) << marks[i]
                 << setw(10) << grades[i] << endl;
        }
    }

};

int main() {
    Student_Report report;

    report.Load_From_File("students.txt");

    report.Display_Report();

    return 0;
}
