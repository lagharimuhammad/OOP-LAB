#include <iostream>
#include <string>

using namespace std;

class InvalidAge
{
    string message;
public:
    InvalidAge(const string &msg) : message(msg) {}
    string what() const 
    { 
        return message; 
    }
};

class InvalidSalary
{
    string message;

public:
    InvalidSalary(const string &msg) : message(msg) {}
    string what() const 
    { 
        return message; 
    }
};

class InvalidHeight
{
    string message;

public:
    InvalidHeight(const string &msg) : message(msg) {}
    string what() const 
    { 
        return message; 
    }
};

int main()
{
    int age, salary, height;
    cout << "Inter age: ";
    cin >> age;
    try
    {
        if (age <= 0 || age >= 120)
        {
            throw InvalidAge("0 <= Age <= 119");
        }
    }
    catch (const InvalidAge &e)
    {
        cout << "Error: " << e.what() << endl;
    }

    cout << "enter salary: ";
    cin >> salary;
    try
    {
        if (salary < 0)
        {
            throw InvalidSalary("salary should be positive or neutral");
        }
    }
    catch (const InvalidSalary &e)
    {
        cout << "Error: " << e.what() << endl;
    }

    cout << "enter height: ";
    cin >> height;
    try
    {
        if (height <= 0)
        {
            throw InvalidHeight("height should be positive");
        }
    }
    catch (const InvalidHeight &e)
    {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}