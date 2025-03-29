#include <iostream>
using namespace std;

class Person 
{
public:
    string name, id, address, number, mail;
    Person(string n, string i, string a, string num, string e) : name(n), id(i), address(a), number(num), mail(e) {}
    virtual void display_data() 
    {
        cout << "name: " << name  << endl << " id: " << id << endl << " address: " << address << endl << " phone: " << number << endl << " mail: " << mail << endl;
    }
    void update_data(string new_a, string new_p, string new_m) 
    {
        address = new_a;
        number = new_p;
        mail = new_m;
    }
};

class Student : public Person 
{
public:
    string courses[10];
    int counter = 0;
    double GPA = 0.0;
    int batch_year;
    Student(string n, string i, string a, string num, string e, int year) : Person(n, i, a, num, e), batch_year(year) {}
    void enroll(string course) 
    {
        if (counter < 10) 
            courses[counter++] = course;
        else 
            cout << "course limit reached" << endl;
    }
    void update_GPA(double gpa) 
    {
        GPA = gpa; 
    }
    void display_data() override 
    {
        Person::display_data();
        cout << "enrollment year: " << batch_year << endl << "GPA: " << GPA << endl << "Courses: ";
        for (int i = 0; i < counter; i++) 
            cout << courses[i] << endl;
    }
};

class Professor : public Person 
{
public:
    string dept;
    string subjects[10];
    int counter = 0;
    double salary;

    Professor(string n, string i, string a, string num, string e, string dept, double sal) : Person(n, i, a, num, e), dept(dept), salary(sal) {}

    void add_courses(string course) 
    {
        if (counter < 10) 
            subjects[counter++] = course;
        else 
            cout << "limit reached!\n";
    }

    void display_data() override 
    {
        Person::display_data();
        cout << "department: " << dept << endl << "salary: " << salary << endl << "courses taught: ";
        for (int i = 0; i < counter; i++) 
            cout << subjects[i] << endl;
    }
};

class Staff : public Person 
{
public:
    string dept, position;
    double salary;

    Staff(string n, string i, string a, string num, string e, string dept, string pos, double sal) : Person(n, i, a, num, e), dept(dept), position(pos), salary(sal) {}
    void display_data() override 
    {
        Person::display_data();
        cout << "department: " << dept << endl << "Position: " << position << endl <<"salary: " << salary << endl;
    }
};

class Course 
{
public:
    string c_id, c_name, schedule;
    int credits;
    Professor* instructor;
    Student* students[50];
    int counter = 0;

    Course(string id, string name, int cr, string sched, Professor* prof) : c_id(id), c_name(name), credits(cr), schedule(sched), instructor(prof) {}

    void registerStudent(Student* student) 
    {
        if (counter < 50) 
        {
            students[counter++] = student;
            student->enroll(c_name);
        } 
        else 
        cout << "cannot register more student" << endl;
    }

    void display_course() 
    {
        cout << "Course ID: " << c_id << endl << "course name: " << c_name << endl << "credits: " << credits << endl << "schedule: " << schedule << endl << "instructor: " << instructor->name << endl << "enrolled students: ";
        for (int i = 0; i < counter; i++) 
            cout << students[i]->name << endl;
    }
};

int main() {
    Professor prof("Instructor Sameer Faisal", "CS1004", "Fast", "12345678", "sameer.faisal@nu.edu.pk", "OOP", 200000);
    prof.add_courses("CS1004");

    Student s1("Baqar", "0006", "Hyd College", "9876543", "k240006@nu.edu.pk", 2024);
    Student s2("Kashif", "2539", "Malir College", "2345678", "k242539@nu.edu.pk", 2024);

    Course cs1004("CS1004", "OOP", 3, "FRI 11 AM-1 PM", &prof);
    cs1004.registerStudent(&s1);
    cs1004.registerStudent(&s2);

    cout << endl << "\t professor Info \t" << endl;
    prof.display_data();

    cout << endl << "\t student Info \t" << endl;
    s1.display_data();
    s2.display_data();

    cout << endl << "\t course Info \t" << endl ;
    cs1004.display_course();

    return 0;
}
