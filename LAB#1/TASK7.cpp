#include <iostream>
using namespace std;

int main() 
{
    double units, bill, sur_charge, total_bill;

    cout << "Enter units: ";
    cin >> units;

    if (units <= 50) 
	{
        bill = units * 0.50;
    }
    
    else if (units <= 150) 
	{
        bill = 50 * 0.50 + (units - 50) * 0.75;
    }
    
    else if (units <= 250) 
	{
        bill = 50 * 0.50 + 100 * 0.75 + (units - 150) * 1.20;
    }
    
    else 
	{
        bill = 50 * 0.50 + 100 * 0.75 + 100 * 1.20 + (units - 250) * 1.50;
    }

    sur_charge = 0.20 * bill;

    total_bill = bill + sur_charge;

    cout << "Electricity bill without surcharge: " << bill << " rs" << endl;
    cout << "Total electricity bill with surcharge: " << total_bill << " rs";

    return 0;
}

