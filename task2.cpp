#include <iostream>
using namespace std;

class Matrix
{
private:
    int rows;
    int cols;
    int** data;

public:

    // Constructor
    Matrix(int r, int c)
    {
        cout << "Constructor called" << endl;

        rows = r;
        cols = c;

        data = new int*[rows];

        for (int i = 0; i < rows; i++)
        {
            data[i] = new int[cols];

            for (int j = 0; j < cols; j++)
            {
                data[i][j] = 0;
            }
        }
    }

    // Copy Constructor
    Matrix(const Matrix& other)
    {
        cout << "Copy constructor called" << endl;

        rows = other.rows;
        cols = other.cols;

        data = new int*[rows];

        for (int i = 0; i < rows; i++)
        {
            data[i] = new int[cols];

            for (int j = 0; j < cols; j++)
            {
                data[i][j] = other.data[i][j];
            }
        }
    }

    // Copy Assignment Operator
    Matrix& operator=(const Matrix& other)
    {
        cout << "Copy assignment operator called" << endl;

        if (this != &other)
        {
            // Delete old memory
            for (int i = 0; i < rows; i++)
            {
                delete[] data[i];
            }

            delete[] data;

            // Copy dimensions
            rows = other.rows;
            cols = other.cols;

            // Allocate new memory
            data = new int*[rows];

            for (int i = 0; i < rows; i++)
            {
                data[i] = new int[cols];

                for (int j = 0; j < cols; j++)
                {
                    data[i][j] = other.data[i][j];
                }
            }
        }

        return *this;
    }

    // Destructor
    ~Matrix()
    {
        cout << "Destructor called" << endl;

        for (int i = 0; i < rows; i++)
        {
            delete[] data[i];
        }

        delete[] data;
    }

    void set(int r, int c, int value)
    {
        if (r >= 0 && r < rows && c >= 0 && c < cols)
        {
            data[r][c] = value;
        }
        else
        {
            cout << "Boundary Error" << endl;
        }
    }

    int get(int r, int c) const
    {
        if (r >= 0 && r < rows && c >= 0 && c < cols)
        {
            return data[r][c];
        }
        else
        {
            cout << "Boundary Error" << endl;
            return -1;
        }
    }

    void display() const
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << data[i][j] << " ";
            }

            cout << endl;
        }
    }

    // Operator +
    Matrix operator+(const Matrix& other) const
    {
        if (rows != other.rows || cols != other.cols)
        {
            cout << "Matrices must have the same size." << endl;

            // Return a small matrix to avoid returning nothing
            return Matrix(0, 0);
        }

        Matrix result(rows, cols);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }

        return result;
    }
};

int main()
{
    cout << "Creating Matrix A:" << endl;

    Matrix A(2, 2);

    A.set(0, 0, 1);
    A.set(0, 1, 2);
    A.set(1, 0, 3);
    A.set(1, 1, 4);

    cout << "\nMatrix A:" << endl;
    A.display();


    cout << "\nCreating Matrix B:" << endl;

    Matrix B(2, 2);

    B.set(0, 0, 5);
    B.set(0, 1, 6);
    B.set(1, 0, 7);
    B.set(1, 1, 8);

    cout << "\nMatrix B:" << endl;
    B.display();


    // Operator +
    cout << "\nA + B:" << endl;

    Matrix C = A + B;

    C.display();


    // Copy Constructor
    cout << "\nCreating D using copy constructor:" << endl;

    Matrix D = A;

    cout << "Matrix D:" << endl;
    D.display();


    // Modify D
    D.set(0, 0, 100);

    cout << "\nAfter changing D:" << endl;

    cout << "Matrix A:" << endl;
    A.display();

    cout << "Matrix D:" << endl;
    D.display();


    // Copy Assignment
    cout << "\nCreating Matrix E:" << endl;

    Matrix E(2, 2);

    cout << "\nAssigning A to E:" << endl;

    E = A;

    cout << "Matrix E:" << endl;
    E.display();


    // Modify E
    E.set(1, 1, 999);

    cout << "\nAfter changing E:" << endl;

    cout << "Matrix A:" << endl;
    A.display();

    cout << "Matrix E:" << endl;
    E.display();

    return 0;
}
