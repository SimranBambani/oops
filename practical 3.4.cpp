#include<iostream>
using namespace std;
template<typename T>
T Max(T *a,int size)
{
    T max=a[0];
    for(int i=1;i<size;i++)
    {
        if(a[i]>max)
            max=a[i];
    }
    return max;
}
template<typename T>
void Reverse_Array(T *a,int size)
{
    for(int i=0;i<size/2;i++)
    {
        T temp=a[i];
        a[i]=a[size-i-1];
        a[size-i-1]=temp;
    }
}
template<typename T>
void Display(T *a,int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<a[i]<<endl;
    }
}

int main() {
    int choice,array_size;
    cout<< "Enter data type: Enter 1 for Integer , Enter 2 for Float , Enter 3 for Character: "<<endl;
    cin>>choice;
    cout<<"Enter size of the array: ";
    cin>>array_size;
    if(choice==1)
        {
        int* arr=new int[array_size];
        cout<<"Enter integers values: "<<endl;
        for(int i=0;i<array_size;i++)
        {
            cin>>arr[i];
        }
        cout<<"Max: "<<Max(arr,array_size)<<endl;
        Reverse_Array(arr,array_size);
        cout<<"Reversed: "<<endl;
        Display(arr,array_size);
        delete[] arr;

    }
     else if(choice==2)
    {
        float* arr=new float[array_size];
        cout<<"Enter float values: "<<endl;
        for(int i=0;i<array_size;i++)
        {
            cin>>arr[i];
        }
        cout<<"Max: "<<Max(arr, array_size)<<endl;
        Reverse_Array(arr,array_size);
        cout<<"Reversed: "<<endl;
        Display(arr, array_size);
        delete[] arr;

    }
     else if(choice==3)
        {
        char* arr=new char[array_size];
        cout<<"Enter characters: "<<endl;
        for (int i=0;i<array_size;i++)
        {
            cin>>arr[i];
        }
        cout<<"Max: "<<Max(arr,array_size)<<endl;
        Reverse_Array(arr,array_size);
        cout<<"Reversed: "<<endl;
        Display(arr,array_size);
        delete[] arr;

    }
     else{
        cout<<"Invalid choice"<<endl;
    }

    return 0;
}
