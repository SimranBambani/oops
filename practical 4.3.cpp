#include<iostream>
using namespace std;

class Fuel_type{
protected:
    string Fuel;
public:
    Fuel_type(string f)
    {
        Fuel=f;
    }
    void put()
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
    void put_data()
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
    void display()
    {
        cout<<"Car: "<<car<<endl;
        put_data();
        put();
        cout<<"-------------------------------"<<endl;
    }
};
int main()
{
    int a,i;
    string f,b,c1;
    cout<<"Enter the number of cars: "<<endl;
    cin>>a;
    Car** c = new Car*[a];
    for(i=0;i<a;i++)
    {
         cout<<"Enter fuel type: ";
         cin.ignore();
        getline(cin,f);
        cout<<"Enter brand: ";
        cin.ignore();
        getline(cin,b);
        cout<<"Enter car: ";
        cin.ignore();
        getline(cin,c1);

        c[i]=new Car(f,b,c1);
    }
    for(i=0;i<a;i++)
    {
         cout<<"-------------------------------"<<endl;
        c[i]->display();
    }
    for (i=0;i<a;i++) {
        delete c[i];
    }
    delete[] c;
    return 0;
}
