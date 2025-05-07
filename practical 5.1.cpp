#include<iostream>
using namespace std;
class Calculator {
    double results[10];
    int count;
public:
    Calculator() {
        count = 0;
    }
    void Store_Result(double value) {
        if (count<10)
            results[count++] = value;
        else
            cout <<" Storage limit reached!" << endl;
    }
    int Add(int i1, int i2) {
        int sum=i1+i2;
        cout<<"Add: "<<sum<<endl;
        Store_Result(sum);
        return sum;
    }
    float Add(float f1, float f2) {
        float sum=f1+f2;
        cout<<"Add: "<<sum<<endl;
        Store_Result(sum);
        return sum;
    }
    void Display_Results() {
        for (int i=0;i<count;i++) {
            cout<<"Result: "<<results[i]<<endl;
        }
    }
    void Get_Int_Input() {
        int a,b;
        cout<<"Enter the first integer: ";
        cin>>a;
        cout<<"Enter the second integer: ";
        cin>>b;
        Add(a, b);
    }
    void Get_Float_Input() {
        float a, b;
        cout<<"Enter the first float: ";
        cin>>a;
        cout<<"Enter the second float: ";
        cin>>b;
        Add(a, b);
    }
    ~Calculator(){}
};

int main() {
    Calculator C1;
    C1.Get_Int_Input();
    C1.Get_Float_Input();
    C1.Display_Results();
    return 0;
}

