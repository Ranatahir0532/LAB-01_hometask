#include <iostream>
using namespace std;

/*
1. The problem is that Buffer has a dynamically allocated array but does not
have a copy constructor or copy assignment operator. Therefore, when b2 is
created using "Buffer b2 = b1", the compiler-generated copy constructor
performs a shallow copy, so b1.data and b2.data point to the same memory.
When b2.setValue(1, 20) is called, it changes the shared array, so the change
is also visible through b1. When both objects are destroyed, their destructors
both call delete[] on the same memory, causing a double deletion and undefined
behavior.

2. The corruption is visible before the program ends. After b2.setValue(1, 20),
both b1.display() and b2.display() will show the changed value at index 1
because both objects are using the same dynamically allocated array.
*/

class Buffer
{
private:
    int* data;
    int length;

public:

    // Constructor
    Buffer(int len)
    {
        cout << "Constructor called" << endl;

        length = len;

        data = new int[length];

        for (int i = 0; i < length; i++)
        {
            data[i] = 0;
        }
    }

    // Copy Constructor
    Buffer(const Buffer& other)
    {
        cout << "Copy constructor called" << endl;

        length = other.length;

        data = new int[length];

        for (int i = 0; i < length; i++)
        {
            data[i] = other.data[i];
        }
    }

    // Copy Assignment Operator
    Buffer& operator=(const Buffer& other)
    {
        cout << "Copy assignment operator called" << endl;

        if (this != &other)
        {
            delete[] data;

            length = other.length;

            data = new int[length];

            for (int i = 0; i < length; i++)
            {
                data[i] = other.data[i];
            }
        }

        return *this;
    }

    void setValue(int index, int value)
    {
        if (index >= 0 && index < length)
        {
            data[index] = value;
        }
    }

    void display() const
    {
        for (int i = 0; i < length; i++)
        {
            cout << data[i] << " ";
        }

        cout << endl;
    }

    // Destructor
    ~Buffer()
    {
        cout << "Destructor called" << endl;

        delete[] data;
    }
};

int main()
{
    cout << "Creating b1:" << endl;

    Buffer b1(5);

    b1.setValue(0, 10);

    cout << "\nCreating b2 using copy constructor:" << endl;

    Buffer b2 = b1;

    b2.setValue(1, 20);

    cout << "\nb1: ";
    b1.display();

    cout << "b2: ";
    b2.display();

    // Test copy assignment
    cout << "\nCreating b3:" << endl;

    Buffer b3(3);

    cout << "\nAssigning b1 to b3:" << endl;

    b3 = b1;

    cout << "b3: ";
    b3.display();

    // Modify b3 to prove deep copy
    b3.setValue(0, 999);

    cout << "\nAfter modifying b3:" << endl;

    cout << "b1: ";
    b1.display();

    cout << "b3: ";
    b3.display();

    return 0;
}
