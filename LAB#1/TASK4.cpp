#include<iostream>
using namespace std;

int main()
{
	int n;
	
	cout << "Enter number of elements in array: ";
	cin >> n;
	
	int arr[n];
	
	for (int i = 0; i < n; i++)
	{
		cout << "Enter " << i+1 << "th element: ";
		cin >> arr[i];
	}
	
	int odd = 0, even = 0;
	
	for(int j = 0; j < n; j++)
	{
		if(arr[j] % 2 == 0)
		{
			even++;
		}
		else
		{
			odd++;
		}
	}
	
	cout << "No. of even elements: " << even << endl;
	cout << "No. of odd elements: " << odd;


 	return 0;
}

