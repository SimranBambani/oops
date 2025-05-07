#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Product {
    string name;
    int quantity;
    double price;
    void display() {
        cout << "Name: " << name << ", Quantity: " << quantity << ", Price: " << price << endl;
    }
    void writeToFile(ofstream& file) {
        file << name << "," << quantity << "," << price << endl;
    }
    static Product readFromFile(ifstream& file) {
        Product p;
        getline(file, p.name, ',');
        file >> p.quantity;
        file.ignore();
        file >> p.price;
        file.ignore();
        return p;
    }
};
void addItemToFile(const string& filename) {
    ofstream file(filename, ios::app);
    if (!file) {
        cout << "Error opening file for writing!" << endl;
        return;
    }

    string name;
    int quantity;
    double price;

    cout << "Enter product name: ";
    cin >> ws; // Ignore leading whitespace
    getline(cin, name);
    cout << "Enter quantity: ";
    cin >> quantity;
    cout << "Enter price: ";
    cin >> price;

    Product newProduct = {name, quantity, price};
    newProduct.writeToFile(file);
    file.close();
    cout << "Product added successfully!" << endl;
}

void viewInventoryFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Error opening file for reading!" << endl;
        return;
    }

    cout << "Inventory:" << endl;
    while (!file.eof()) {
        Product p = Product::readFromFile(file);
        if (file) {
            p.display();
        }
    }
    file.close();
}

void searchProductByName(const string& filename, const string& searchName) {
    ifstream file(filename);
    if (!file) {
        cout << "Error opening file for reading!" << endl;
        return;
    }

    bool found = false;
    while (!file.eof()) {
        Product p = Product::readFromFile(file);
        if (file && p.name == searchName) {
            p.display();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Product not found!" << endl;
    }
    file.close();
}

int main() {
    string filename = "inventory.txt";
    int choice;

    cout << "1. Add Item\n2. View Inventory\n3. Search for Product\n4. Exit\nEnter choice: ";
    cin >> choice;

    if (choice == 1) {
        addItemToFile(filename);
    }
    else if (choice == 2) {
        viewInventoryFromFile(filename);
    }
    else if (choice == 3) {
        string searchName;
        cout << "Enter product name to search: ";
        cin >> ws;
        getline(cin, searchName);
        searchProductByName(filename, searchName);
    }
    else {
        cout << "Exiting the program." << endl;
    }

    return 0;
}

