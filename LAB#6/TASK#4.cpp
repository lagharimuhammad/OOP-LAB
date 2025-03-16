#include <iostream>
#include <string>
using namespace std;

class Person 
{
private:
    string name;
    int age;
public:
    Person(string name, int age) : name(name), age(age) {}
    void display_person() 
    {
        cout << "name: " << name << endl << "age: " << age << endl;
    }
};

class Student : virtual public Person 
{
protected:
    int s_id;
    int grade;
public:
    Student(string s_name, int s_age, int id, int grade) : Person(s_name, s_age), s_id(id), grade(grade) {}
    void display_student() const 
    {
        cout << "student id: " << s_id << endl << "grade Level: " << grade << endl;
    }
};

class Teacher : virtual public Person 
{
protected:
    string subject;
    int room_no;
public:
    Teacher(string t_name, int t_age, string s, int r) : Person(t_name, t_age), subject(s), room_no(r) {}
    void display_teacher() const 
    {
        cout << "subject: " << subject << endl << "room number: " << room_no << endl;
    }
};

class GraduateStudent : public Student, public Teacher
{
public:
    GraduateStudent(string graduate_name, int graduate_age, int g_id, int grade, string g_s, int g_r) : Person(graduate_name, graduate_age), Student(graduate_name, graduate_age, g_id, grade), Teacher(graduate_name, graduate_age, g_s, g_r) {}
    void display_graduate()
    {
        cout << "Graduate Student: " << endl;
        display_person();
        display_student();
        display_teacher();
    }
};

int main() 
{
    GraduateStudent g1("Baqar", 19, 06, 3, "oop", 35);
    g1.display_graduate();
    return 0;
}
