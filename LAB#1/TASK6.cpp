#include<iostream>
using namespace std;

int main()
{
int upper_bound, lower_bound;

cout << "enter lower bound: ";
cin >> lower_bound;

cout << "enter upper bound: ";
cin >> upper_bound;
cout << endl;

// for even lower bound
int num = 0;
if(lower_bound % 2 != 0)
{

for(int i = lower_bound; i < upper_bound; i++)
{
	if ( i % 2 == 0)
	{
		cout << i << endl;
		num++;
	}
	if ( num % 4 == 0)
	{
		cout << i+1 << endl;
	}
}
}

int num1 = 0;
if(lower_bound % 2 == 0)
{

for(int i = lower_bound; i <= upper_bound; i++)
{
	if ( i % 2 == 0)
	{
		cout << i << endl;
		num1++;
	}
	if ( num1 % 4 == 0)
	{
		cout << i+1 << endl;
	}
}
}



return 0;
}

