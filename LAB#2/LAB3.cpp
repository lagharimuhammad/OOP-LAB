#include <iostream>
using namespace std;

int* pointer_function(int size)
{
    int *p = new int[size];
    return p;
}

int main() 
{
int size;
cout << "Enter number of elements to allocate: ";
cin >> size;

int *ptr = pointer_function(size);

for(int i = 0; i < size; i++)
{
    int *ptr1 = ptr;
    cout << "input " << i+1 << "th element: ";
    cin >> *(ptr1+i);
}

for (int i = 0; i < size; i++ )
{
    cout << *(ptr+i)<< endl;
}

delete[] ptr;

    return 0;
}
