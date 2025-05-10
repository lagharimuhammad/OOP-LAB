#include <iostream>
#include <string>
using namespace std;

template <typename T>
T findMax(T arr[], int size)
{
    T max = arr[0];
    for(int i = 1; i < size; ++i)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int main()
{
    string str[] = {"Apple", "Mango", "Banana", "Peach"};
    int size = sizeof(str) / sizeof(str[0]);
    cout << "[ Apple, Mango, Banana, Peach]" << endl;
    cout << "meximum: " << findMax(str, size) << endl;
    return 0;
}
