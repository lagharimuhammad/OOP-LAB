#include <iostream>
using namespace std;

void resize(int*& arraya, int& n)
 {
    int* t = new int[n * 2];
    for (int i = 0; i < n; i++) 
    {
        t[i] = arraya[i];
    }
    delete[] arraya;
    arraya = t;
    n *= 2;
}

void shrink(int*& arraya, int size) 
{
    int* t = new int[size];
    for (int i = 0; i < size; i++) 
    {
        t[i] = arraya[i];
    }
    delete[] arraya;
    arraya = t;
}

int main() 
{
    int n = 5, size = 0, num;
    int* arraya = new int[n];

    while (true) 
    {
        cout << "Enter a number (-1 to stop): ";
        cin >> num;
        if (num == -1) 
        {
            break;
        }
        if (size == n) 
        {
            resize(arraya, n);
        }
        arraya[size++] = num;
    }

    shrink(arraya, size);

    cout << "Final array: ";
    for (int i = 0; i < size; i++) 
    {
        cout << arraya[i] << " ";
    }
    cout << endl;

    delete[] arraya;
    return 0;
}

