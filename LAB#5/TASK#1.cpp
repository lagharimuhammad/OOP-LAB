#include<iostream>
#include<string>
using namespace std;

class Dayofyear
{
	int day;
	
	public:
		static const string month_name[12];
		static const int days_in_month[12];
		
		Dayofyear(int day_of_year)
		{
			day = day_of_year;
		}
	
	void print()
	{
		int month_count = 0;
		int day_month = day;
		while(day_month > days_in_month[month_count])
		{
			day_month -= days_in_month[month_count];
			month_count++;
		}
		
		cout << month_name[month_count] << " " << day_month << endl;
	}
};


const string Dayofyear::month_name[12] = { "January", "February", "March", "April", "May", "June","July", "August", "September", "October", "November", "December"};
const int Dayofyear::days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
	Dayofyear d1(15); d1.print();
	Dayofyear d2(99); d2.print();
	Dayofyear d3(360); d3.print();
	
	return 0;
}
