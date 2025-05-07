#include <iostream>
using namespace std;
class Dynamic_Array
{
private:
    int *data;
    int size;
    int capacity;

    void resize(int newCapacity)
    {
        int *newData = new int[newCapacity];
        for (int i = 0; i < size; i++)
        {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    Dynamic_Array(int initial_Capacity = 4)
    {
        data = new int[initial_Capacity];
        size = 0;
        capacity = initial_Capacity;
    }

    ~Dynamic_Array()
    {
        delete[] data;
    }

    void Append(int value)
    {
        if (size == capacity)
        {
            resize(capacity * 2);
        }
        data[size++] = value;
    }

    void Remove_At(int index)
    {
        if (index < 0 || index >= size)
        {
            cout << "Index out of bounds.\n";
            return;
        }
        for (int i = index; i < size - 1; i++)
        {
            data[i] = data[i + 1];
        }
        size--;
        if (size > 0 && size <= capacity / 4)
        {
            resize(capacity / 2);
        }
    }

    int Get_Data(int index) const
    {
        if (index < 0 || index >= size)
        {
            cout << "Index out of bounds.\n";
            return -1;
        }
        return data[index];
    }

    int Get_Data_Size() const
    {
        return size;
    }

    void Display_Data() const
    {
        cout << "[ ";
        for (int i = 0; i < size; i++)
        {
            cout << data[i] << " ";
        }
        cout << "]\n";
    }
};

int main()
{
    Dynamic_Array arr;

    arr.Append(5);
    arr.Append(10);
    arr.Append(15);
    arr.Append(20);
    arr.Append(25);

    cout << "Array after appending elements: ";
    arr.Display_Data();

    arr.Remove_At(1);
    cout << "After removing index 2 :: ";
    arr.Display_Data();

    cout << "Element at index 1 :: " << arr.Get_Data(1) << endl;

    arr.Append(40);
    cout << "After appending 40 :: ";
    arr.Display_Data();

    return 0;
}
