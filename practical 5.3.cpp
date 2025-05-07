#include<iostream>
using namespace std;
class Coordinate_system
{
    int real;
    int imaginary;
public:
    void get_data()
    {
    cout<<"Enter the real part: "<<endl;
    cin>>real;
    cout<<"Enter the imaginary part: "<<endl;
    cin>>imaginary;
    }
    int operator==(Coordinate_system c)
    {
        if(real==c.real && imaginary==c.imaginary)
          return 1;
        else
           return 0;
    }
    Coordinate_system operator-()
    {
       Coordinate_system temp;
        temp.real=-real;
        temp.imaginary=-imaginary;
        return temp;
    }
   Coordinate_system operator+(Coordinate_system c)
    {
        Coordinate_system temp;
        temp.real=real+c.real;
        temp.imaginary=imaginary+c.imaginary;
        return temp;
    }
    void display()
    {
        cout<<"Real part is: "<<real<<endl;
        cout<<"Imaginary part is: "<<imaginary<<endl;
        cout<<"---------------------------------------"<<endl;
    }
};
int main()
{
    Coordinate_system c1,c2,c3;
    c1.get_data();
    c2.get_data();
    if(c1==c2)
    {
        cout<<"----------------------"<<endl;
        cout<<"Same coordinates."<<endl;
    }
    else{
       cout<<"----------------------"<<endl;
        cout<<"Different Coordinates."<<endl;
    }
    cout<<"Sum: "<<endl;
    c3=c1+c2;
    c3.display();
    c2=-c2;
    c2.display();
    return 0;
}
