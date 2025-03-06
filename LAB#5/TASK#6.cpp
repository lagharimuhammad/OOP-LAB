#include<iostream>
using namespace std;

class LoanCalculator
{
	double loan, rate;
	int month;
	
	public:
	LoanCalculator(double l, double r, int m) : loan(l), rate(r), month(m) 
	{
	rate = (r >= 0 && r <= 0.005) ? r : 0.005;
	}
	
	void calculate()
	{
		double payment = (loan / month) * (1 + rate);
		cout << payment << " per month for " << month << " months";
	}
};
int main()
{
	LoanCalculator lc(15000, 0.004, 7);
	lc.calculate();
	
	return 0;
}
