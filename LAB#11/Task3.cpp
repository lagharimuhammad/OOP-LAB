#include <iostream>
using namespace std;

template <typename T1, typename T2>
class Pair
{
    T1 f1;
    T2 f2;
public:
    Pair(T1 f, T2 s) : f1(f), f2(s) {}
    void display() const
    {
        cout << "(" << f1 << ", " << f2 << ")" << endl;
    }
};

int main()
{
    Pair<int, string> p1(5, "Hello");
    p1.display();
    return 0;
}