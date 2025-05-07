#include <iostream>
using namespace std;
class Fahrenheit;
class Celsius {
    float temp;
public:
    Celsius(float t = 0) {
        temp = t;
    }
    float Get_Temperature() {
        return temp;
    }
    operator Fahrenheit();
    int operator==(Fahrenheit& f);
};
class Fahrenheit {
    float temp;
public:
    Fahrenheit(float t = 32.0f) {
        temp = t;
    }

    float Get_Temperature() {
        return temp;
    }

    operator Celsius() {
        return Celsius((temp - 32.0f) * 5.0f / 9.0f);
    }

    int operator==(Celsius& c) {
        Fahrenheit temp_fahrenheit = c;
        if (temp == temp_fahrenheit.Get_Temperature()) {
            return 1;
        } else {
            return 0;
        }
    }
};

Celsius::operator Fahrenheit() {
    return Fahrenheit(temp * 9.0f / 5.0f + 32.0f);
}

int Celsius::operator==(Fahrenheit& f) {
    Fahrenheit temp_fahrenheit = *this;
    if (temp_fahrenheit.Get_Temperature() == f.Get_Temperature()) {
        return 1;
    } else {
        return 0;
    }
}

const int MAX_TEMPS = 10;
Fahrenheit stored_temp[MAX_TEMPS];
int stored_count = 0;

void Store_Temperature(Celsius c) {
    if (stored_count < MAX_TEMPS) {
        stored_temp[stored_count++] = c;
    } else {
        cout << "Storage is full. Cannot store more temperatures." << endl;
    }
}
void Display_Temperature() {
    cout << "Stored Fahrenheit Temperatures:" << endl;
    for (int i = 0; i < stored_count; i++) {
        cout << "Temp: " << stored_temp[i].Get_Temperature() << "°F" << endl;
    }
}
int main() {
    Celsius c1(100);
    Fahrenheit f1 = c1;
    cout << "Celsius: " << c1.Get_Temperature() << "°C -> Fahrenheit: " << f1.Get_Temperature() << "°F" << endl;
    Celsius c2 = f1;
    cout << "Converted back to Celsius: " << c2.Get_Temperature() << "°C" << endl;
    if (c1 == f1) {
        cout << "Temperatures are equal." << endl;
    } else {
        cout << "Temperatures are not equal." << endl;
    }
    Store_Temperature(Celsius(0));
    Store_Temperature(Celsius(25));
    Display_Temperature();
    return 0;
}
