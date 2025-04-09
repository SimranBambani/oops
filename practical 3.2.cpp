#include<iostream>
using namespace std;
class array
{
    int *array_1;
    int size,i;
public:
    array(int array_size)
    {
        size=array_size;
        array_1 = new int[size];
    }
    void get_data(int array_size)
    {
      size=array_size;
      for(i=0;i<size;i++)
      {
          cout<<"Enter the value: "<<endl;
          cin>>array_1[i];
      }
    }
    void display(int array_size)
    {
        cout<<"The size of the array: "<<size<<endl;
        for(i=0;i<size;i++)
        {
        cout<<"Array elements are: "<<array_1[i]<<endl;
        }
    }
    int recursivesum(int array_size)
    { int total=0;
        if(array_size==0)
        {
            return 0;
        }
        else{
            return array_1[array_size-1]+recursivesum(array_size-1);
        }
    }
    int iterativesum(int array_size)
    {
        int total=0;
        for(i=0;i<array_size;i++)
        {
        total=total+array_1[i];
        }
        cout<<"Iterative sum: "<<total<<endl;
    }
    ~array()
    {
        delete[] array_1;
    }

};
int main()
{

    int i,array_size;
    cout<<"Enter the size of array: ";
    cin>>array_size;
    array object(array_size);

    object.get_data(array_size);
    object.display(array_size);
    object.iterativesum(array_size);
    cout<<"RECURSIVE SUM: "<<object.recursivesum(array_size);

    return 0;
}

