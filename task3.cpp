#include <iostream>
using namespace std;

class DynamicArray
{
private:
    int* arr;
    int size;
    int capacity;

public:

    // Constructor
    DynamicArray()
    {
        cout << "Constructor called" << endl;

        size = 0;
        capacity = 2;

        arr = new int[capacity];
    }

    // Copy Constructor
    DynamicArray(const DynamicArray& other)
    {
        cout << "Copy constructor called" << endl;

        size = other.size;
        capacity = other.capacity;

        arr = new int[capacity];

        for (int i = 0; i < size; i++)
        {
            arr[i] = other.arr[i];
        }
    }

    // Copy Assignment Operator
    DynamicArray& operator=(const DynamicArray& other)
    {
        cout << "Copy assignment operator called" << endl;

        if (this != &other)
        {
            delete[] arr;

            size = other.size;
            capacity = other.capacity;

            arr = new int[capacity];

            for (int i = 0; i < size; i++)
            {
                arr[i] = other.arr[i];
            }
        }

        return *this;
    }

    // Destructor
    ~DynamicArray()
    {
        cout << "Destructor called" << endl;

        delete[] arr;
    }

    void pushBack(int value)
    {
        if (size == capacity)
        {
            cout << "Resizing array..." << endl;

            int newCapacity = capacity * 2;

            int* newArr = new int[newCapacity];

            for (int i = 0; i < size; i++)
            {
                newArr[i] = arr[i];
            }

            delete[] arr;

            arr = newArr;
            capacity = newCapacity;
        }

        arr[size] = value;
        size++;
    }

    int& operator[](int index)
    {
        if (index < 0 || index >= size)
        {
            cout << "Index out of bounds" << endl;
            exit(1);
        }

        return arr[index];
    }

    void print() const
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    cout << "Creating arr1:" << endl;

    DynamicArray arr1;

    // Push 6 values to force resizing
    arr1.pushBack(10);
    arr1.pushBack(20);
    arr1.pushBack(30);
    arr1.pushBack(40);
    arr1.pushBack(50);
    arr1.pushBack(60);

    cout << "\narr1: ";
    arr1.print();

    // Copy constructor
    cout << "\nCreating arr2 using copy constructor:" << endl;

    DynamicArray arr2 = arr1;

    cout << "arr2: ";
    arr2.print();

    // Modify copy
    arr2[0] = 999;

    cout << "\nAfter modifying arr2:" << endl;

    cout << "arr1: ";
    arr1.print();

    cout << "arr2: ";
    arr2.print();

    // Copy assignment
    cout << "\nCreating arr3 and using copy assignment:" << endl;

    DynamicArray arr3;

    arr3 = arr1;

    cout << "arr3: ";
    arr3.print();

    return 0;
}
