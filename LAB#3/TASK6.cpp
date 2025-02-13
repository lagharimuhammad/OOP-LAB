#include <iostream>
#include <string>

using namespace std;

class Employee 
{
private:
    string name_employee;
    double salary_employee;
    double tax_percent;

public:
    Employee() : name_employee(""), salary_employee(0.0), tax_percent(2.0) {}

    void get_data()
    {
        cout << "input employee name: ";
        cin >> name_employee;
        cout << "input monthly salary: ";
        cin >> salary_employee;
        cout<< "input tax percentage: ";
        cin >> tax_percent;
    }

    double salary_after_tax() 
    {
        return salary_employee * (1 - tax_percent / 100);
    }

    double update_percent(double new_sal) 
    {
        tax_percent = new_sal;
        return salary_after_tax();
    }
};

int main() 
{
    Employee emp;
    emp.get_data();
    cout << "salary after tax: " << emp.salary_after_tax() << endl;
    
    double new_sal;
    cout << "enter new tax percentage: ";
    cin >> new_sal;
    
    cout << "updated salary after tax: " << emp.update_percent(new_sal) << endl;
    return 0;
}

