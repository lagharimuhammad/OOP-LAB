#include <iostream>
#include <string>

using namespace std;

class Exception
{
    string message;

public:
    Exception(const string &msg) : message(msg) {}
    string what() const
    {
        return message;
    }
};

template <typename T>
class SmartArray
{
    T *data;
    int size;

public:
    SmartArray(int s) : size(s)
    {
        data = new T[size];
    }

    ~SmartArray()
    {
        delete[] data;
    }

    T &operator[](int index)
    {
        if (index < 0 || index >= size)
        {
            throw Exception("not valid index access attempted!");
        }
        return data[index];
    }

    int getSize() const
    {
        return size;
    }
};

int main()
{
    int size;
    cout << "Array size: ";
    cin >> size;
    SmartArray<int> intArray(size);
    cout << "Enter elements: ";
    for (int i = 0; i < size; ++i)
    {
        cin >> intArray[i];
    }
    try 
    {
        cout << "for index 2: " << intArray[2] << endl;
        cout << "for index 5: " << intArray[5] << endl;
    }
    catch (const Exception &e)
    {
        cout << "error: " << e.what() << endl;
    }
    return 0;
}