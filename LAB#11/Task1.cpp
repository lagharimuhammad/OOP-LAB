#include <iostream>
using namespace std;

template <typename T>
void swapValues(T &a, T &b) 
{
    T temp = a;
    a = b;
    b = temp;
}

int main() 
{
    int a = 2, b = 3;
    cout << "before swap" << endl;
    cout << "a & b: " << a << " " << b << endl;
    swapValues(a, b);
    cout << "a & b: " << a << " " << b << endl;

    double x = 5.5, y = 0.8;
    cout << "before swap" << endl;
    cout << "x & y: " << x << " " << y << endl;
    swapValues(x, y);
    cout << "x & y: " << x << " " << y << endl;

    char ch1 = 'Z', ch2 = 'B';
    cout << "before swap" << endl;
    cout << "ch1 & ch2: " << ch1 << " " << ch2 << endl;
    swapValues(ch1, ch2);
    cout << "ch1 & ch2: " << ch1 << " " << ch2 << endl;
    return 0;
}
