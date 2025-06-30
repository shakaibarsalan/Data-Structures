#include <iostream>
using namespace std;

class DynamicArray
{
    int *arr;
    int size;
    int capacity;

public:
    DynamicArray(int capacity)
    {
        arr = new int[capacity];
        this->capacity = capacity;
        this->size = 0;
    }
    void addToTail(int data)
    {
        if (size == capacity)
        {
            capacity *= 2;
            int *newArray = new int[capacity];
            for (int i = 0; i < size; i++)
            {
                newArray[i] = arr[i];
            }
            delete[] arr;
            arr = newArray;
            delete []newArray;
        }
        arr[size++] = data;
    }
    int getSize()
    {
        return size;
    }
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "capacity is: " << capacity << endl;
    }
    ~DynamicArray()
    {
        delete[] arr;
    }
};

int main()
{
    // Create a DynamicArray with an initial capacity of 3
    DynamicArray dynArray(3);

    // Add elements to the array
    dynArray.addToTail(1);
    dynArray.addToTail(2);
    dynArray.addToTail(3);

    // Display the elements in the array
    cout << "Array elements: ";
    dynArray.display();
    cout << endl;

    // Add more elements to trigger resizing
    dynArray.addToTail(4);
    dynArray.addToTail(5);

    // Display the updated elements in the array
    cout << "Updated array elements: ";
    dynArray.display();
    cout << endl;

    return 0;
}
