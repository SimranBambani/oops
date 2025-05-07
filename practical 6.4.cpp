#include <iostream>
using namespace std;
class Base {
public:
    Base() {
        cout << "Base class constructor called" << endl;
    }

    virtual ~Base() {
        cout << "Base class destructor called" << endl;
    }
};
class Derived1 : public Base {
public:
    int* data;
    Derived1() {
        data = new int(10);
        cout << "Derived1 class constructor called" << endl;
    }
    ~Derived1() {
        delete data;
        cout << "Derived1 class destructor called" << endl;
    }
};
class Derived2 : public Base {
public:
    float* data;
    Derived2() {
        data = new float(3.14);
        cout << "Derived2 class constructor called" << endl;
    }

    ~Derived2() {
        delete data;
        cout << "Derived2 class destructor called" << endl;
    }
};
int main() {
    Base* obj1 = new Derived1();
    Base* obj2 = new Derived2();
    delete obj1;
    delete obj2;
    return 0;
}

