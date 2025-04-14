/* Meet Student, a class that holds a student's name and their three precious grades—because
what’s school without some academic drama? But wait, students can’t just update their own
grades (obviously), so we bring in Teacher, a class with special access privileges (a.k.a. a friend
class) that can peek into grades, modify them, and perhaps even save students from academic
disaster! To keep things fair and scientific, there’s also a friend function called
calculateAverageGrade() that computes the average grade—because math doesn’t lie (even if
students wish it would). In main(), we’ll simulate a high-stakes grading scenario: first, we’ll display
the student’s grades, then let the teacher graciously update one of them (whether out of
generosity or mercy, who knows?), and finally, we’ll recalculate the average to see if things
improved or got even worse. Ready to code this virtual school system? Just remember: Teacher
holds all the power!*/
#include<iostream>
using namespace std;

class Student
{
    string name;
    double subject1;
    double subject2;
    double subject3;
    friend class Teacher;
    
    public:
    
    Student(string n, double s1, double s2, double s3) : name(n), subject1(s1), subject2(s2), subject3(s3) {}
    friend double calculateAverageGrade(const Student& s);
    void display()
    {
        cout << "name: " << name << endl << "subject 1: "<< subject1 << endl << "subject 2: " << subject2 << endl << "subject 3: " << subject3 << endl;
    }
};

double calculateAverageGrade(const Student& s)
{
    double avg;
    avg = (s.subject1 + s.subject2 + s.subject3) / 3;
    return avg;
}

class Teacher
{

    public:
    void updategrades(Student& obj, int num, double marks)
    {
        if(num == 1) {obj.subject1=marks;}
        else if(num == 2) {obj.subject2=marks;}
        else if(num == 3) {obj.subject3=marks;}
        else{cout << "pick from 1 to 3";}
    }

};

int main()
{
Student s1("baqar", 80, 88, 55);
s1.display();
double m = calculateAverageGrade(s1);
cout << "grade: " << m <<endl;
// after teacher alters my marks
Teacher t1;
t1.updategrades(s1,3,99);
s1.display();
double m2 = calculateAverageGrade(s1);
cout<< "grade: " << m2;
    return 0;
}