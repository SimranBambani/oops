#include<iostream>
using namespace std;
int Super_Digit(long s) {
    if(s<10)
    {
        return s;
    }
    long sum=0;
    while(s>0)
    {
        sum+=s%10;
        s/=10;
    }
    return Super_Digit(sum);
}

int main() {
    int size;
    cout<<"Enter the size: "<<endl;
    cin>>size;
    char* n=new char[size];
    int k;
    cout<<"Enter the number string: ";
    cin>>n;
    cout<<"Enter the repetition count: ";
    cin>>k;
    long Digit_Sum=0;
    for (int i=0;n[i]!='\0';++i)
    {
        Digit_Sum+=n[i]-'0';
    }
    Digit_Sum*=k;

    int result=Super_Digit(Digit_Sum);

    cout<<"Super Digit: "<<result<<endl;

    delete[] n;

    return 0;
}

