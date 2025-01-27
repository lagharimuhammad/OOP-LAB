#include <iostream>
#include <string>
using namespace std;

char c_grade(double average); 


int main() 
{
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    string name;
    double pf, oop, dld, ict, total, avg;

    for (int i = 0; i < n; i++) 
	{
        cout << "Enter details for student: " << (i + 1) << endl;


        cout << "Enter student name: ";
		cin >> name;

        cout << "Enter marks for PF: ";
        cin >> pf;

        cout << "Enter marks for OOP: ";
        cin >> oop;

        cout << "Enter marks for DLD: ";
        cin >> dld;

        cout << "Enter marks for ICT: ";
        cin >> ict;

        total = pf + oop + dld + ict;
        avg = total / 4.0;

        char grade = c_grade(avg);


        cout << "Results for " << name << ":" << endl;
        cout << "Total marks: " << total << endl;
        cout << "Average merks: " << avg << endl;
        cout << "Grade: " << grade << endl;
    }

    return 0;
}

char c_grade(double average)
{
    if (average >= 90) 
	{
        return 'A';
    } 
    
	else if (average >= 80) 
	{
        return 'B';
    }
    
	 else if (average >= 70) 
	{
        return 'C';
    }
    
	 else if (average >= 60) 
	{
        return 'D';
    }
    
	 else 
	 {
        return 'F';
    }
}
