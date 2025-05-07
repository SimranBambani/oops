#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector<int> sequence;
    int no_of_elements, input;
    cout << "Enter number of elements: ";
    cin >> no_of_elements;
    cout << "Enter " << no_of_elements << " integers: "<<endl;
    for (int i = 0; i < no_of_elements; ++i) {
        cin >> input;
        sequence.push_back(input);
    }
    reverse(sequence.begin(), sequence.end());
    cout << "Reversed sequence: "<<endl;
    for (const int& num : sequence) {
        cout << num << " ";
    }
    auto front = sequence.begin();
    auto back = sequence.end() - 1;
    while (front < back) {
        iter_swap(front, back);
        --back;
    }
    cout << "\n Reversed sequence: "<<endl;
    for (const int& num : sequence) {
        cout << num << " ";
    }
        return 0;
}


