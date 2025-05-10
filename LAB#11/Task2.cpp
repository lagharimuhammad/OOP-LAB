#include <iostream>
#include <stdexcept>
using namespace std;

class MyException
{
    string message;
public:
    MyException(const string &msg) : message(msg) {}
    string what() const { return message; }
};

int main()
{
    int num, den;
    while (true)
    {
        cout << "enter numerator & denominator: ";
        cin >> num >> den;
        try
        {
            if (den == 0)
            {
                throw MyException("division by zero is not allowed!");
            }
            int result = num / den;
            cout << "Result: " << result << endl;
            break;
        }
        catch (const MyException &e)
        {
            cout << "rrror: " << e.what() << endl;
        }
    }
    return 0;
}