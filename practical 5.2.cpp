#include <iostream>
using namespace std;
class Complex_Number
{
private:
    int real,imaginary;
public:
    void Set_Data()
    {
    cout<<"Enter the real value: "<<endl;
    cin>>real;
    cout<<"Enter the imaginary value: "<<endl;
    cin>>imaginary;
    }
    void Display_Data()
    {
        cout<<"----------------------"<<endl;
        cout<<real<<"+"<<imaginary<<"i"<<endl;
    }
    Complex_Number operator+(Complex_Number C)
    {
        Complex_Number add;
        add.real=real+C.real;
        add.imaginary=imaginary+C.imaginary;
        return add;
    }
    Complex_Number operator-(Complex_Number C)
    {
        Complex_Number subtract;
        subtract.real=real-C.real;
        subtract.imaginary=imaginary-C.imaginary;
        return subtract;
    }
};
int main()
{
    Complex_Number C1,C2,C3,C4;
    C1.Set_Data();
    C2.Set_Data();
    C3=C1+C2;
    C4=C1-C2;
    C3.Display_Data();
    C4.Display_Data();
    return 0;
}
