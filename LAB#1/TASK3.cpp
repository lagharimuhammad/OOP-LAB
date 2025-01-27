#include<iostream>
using namespace std;

int main()
{
int num1, num2, operation;

// inputting numbers and operations
cout << "enter first operand: ";
cin >> num1;
cout << endl;
cout << "enter second operand: ";
cin >> num2;
cout << endl;
cout << "1 for '-' \n 2 for'+' \n 3 for'/' \n 4 for'*'" << endl;
cout << "enter operation: ";
cin >> operation;

//operation = ;

switch(operation)
{
	case 1: // subtraction;
	cout << num1-num2;
	break;
	
	case 2: // addition;
	cout << (-num1-num2)*-1;
	break;
	
	case 3: // division;
	cout << (double)num1/(double)num2;
	break;
	
	case 4: 
	cout << num1*num2;
	break;
	
	default: 
	cout << "invalid operation";
	
}

return 0;
}

