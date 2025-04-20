#include<iostream>
using namespace std;
class Array
{
    int *array_1;
    int size,i;
public:
    Array(int array_size)
    {
        size=array_size;
        array_1 = new int[size];
    }
    void Get_Data(int array_size)
    {
      size=array_size;
      for(i=0;i<size;i++)
      {
          cout<<"Enter the value: "<<endl;
          cin>>array_1[i];
      }
    }
    void Display_Data(int array_size)
    {
        cout<<"The size of the array: "<<size<<endl;
        for(i=0;i<size;i++)
        {
        cout<<"Array elements are: "<<array_1[i]<<endl;
        }
    }
    int Recursive_Sum(int array_size)
    { int total=0;
        if(array_size==0)
        {
            return 0;
        }
        else{
            return array_1[array_size-1]+Recursive_Sum(array_size-1);
        }
    }
    int Iterative_Sum(int array_size)
    {
        int total=0;
        for(i=0;i<array_size;i++)
        {
        total=total+array_1[i];
        }
        cout<<"Iterative sum: "<<total<<endl;
    }
    ~Array()
    {
        delete[] array_1;
    }

};
int main()
{

    int i,array_size;
    cout<<"Enter the size of array: ";
    cin>>array_size;
    Array object(array_size);

    object.Get_Data(array_size);
    object.Display_Data(array_size);
    object.Iterative_Sum(array_size);
    cout<<"RECURSIVE SUM: "<<object.Recursive_Sum(array_size);

    return 0;
}

