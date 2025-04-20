#include<iostream>
using namespace std;
class Fuel_type
{
protected:
    string Fuel;
public:
    Fuel_type(string f)
    {
        Fuel=f;
    }
    void Display_Fuel()
    {
        cout<<"Fuel: "<<Fuel<<endl;
    }
};
class Brand
{
protected:
    string brand;
public:
    Brand(string b)
    {
        brand=b;
    }
    void Display_Brand()
    {
        cout<<"Brand: "<<brand<<endl;
    }
};
class Car: public Fuel_type, public Brand
{
private:
    string car;
public:
    Car(string f,string b,string c): Fuel_type(f),Brand(b)
    {
        car=c;
    }
    void Display_Car()
    {
        cout<<"Car: "<<car<<endl;
       Display_Fuel();
       Display_Brand();
        cout<<"-------------------------------"<<endl;
    }
};
int main()
{
    int number,i;
    string fuel,brand,car;
    cout<<"Enter the number of cars: "<<endl;
    cin>>number;
    Car** c = new Car*[number];
    for(i=0;i<number;i++)
    {
         cout<<"Enter fuel type: ";
         cin.ignore();
        getline(cin,fuel);
        cout<<"Enter brand: ";
        cin.ignore();
        getline(cin,brand);
        cout<<"Enter car: ";
        cin.ignore();
        getline(cin,car);
        c[i]=new Car(fuel,brand,car);
        c[i]->Display_Car();
    }
    for (i=0;i<number;i++) {
        delete c[i];
    }
    delete[] c;
    return 0;
}
