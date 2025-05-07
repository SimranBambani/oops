#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main() {
    int no_of_transaction, id;
    cout << "Enter number of transaction IDs: ";
    cin >> no_of_transaction;
    set<int> uniqueIDs;
    cout << "Enter " << no_of_transaction << " transaction IDs: "<<endl;
    for (int i = 0; i <no_of_transaction; ++i) {
        cin >> id;
        uniqueIDs.insert(id);
    }
    cout << "\nUnique Transaction IDs (sorted): "<<endl;
    for (auto it = uniqueIDs.begin(); it != uniqueIDs.end(); ++it) {
        cout << *it << " ";
    }
    return 0;
}
