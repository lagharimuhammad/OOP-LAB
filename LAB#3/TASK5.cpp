#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

class Employee 
{
private:
    std::string name_employee;
    double salary_employee;
    double tax_percent;

public:
    Employee();
    void get_data();
    double salary_after_tax();
    double update_percent(double new_tax);
};

#endif

