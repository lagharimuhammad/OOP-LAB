#include <iostream>
using namespace std;

void calculator(int* a, int* b, char op, int* answer, bool* available);

int main() 
{
    int n1, n2, answer;
    char operate;
    bool available;
    
    cout << "Enter first number: ";
    cin >> n1;
    cout << "Enter an operator (+, -, *, /): ";
    cin >> operate;
    cout << "Enter second number: ";
    cin >> n2;

    calculator(&n1, &n2, operate, &answer, &available);

    if (available) 
    {
        cout << "answer: " << answer << endl;
    }
    else 
    cout << "unavailable operation or division by zero.\n";

    return 0;
}

void calculator(int* a, int* b, char op, int* answer, bool* available) 
{
    *available = true;
    if (op == '+') *answer = *a + *b;
    else if (op == '-') *answer = *a - *b;
    else if (op == '*') *answer = *a * *b;
    else if (op == '/') 
    {
        if (*b != 0) 
            {
            *answer = *a / *b;
            }
        else 
           *available = false;
    } 
    else *available = false;
}


