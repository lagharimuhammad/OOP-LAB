/*Traffic jams are the ultimate test of patience, but what if C++ could take control of the chaos?
Enter the TrafficSystem class, designed to bring order to the madness using operator overloading.
First up is addition (+), because when more cars enter a busy intersection (50 cars + 20 more), the
total count surges to 70, making the situation even worse. Then comes subtraction (-), offering a
glimmer of hope—if 15 cars finally move out, the congestion eases to 55, though not for long!
Next, there’s multiplication (*), useful for scenarios like a traffic signal failure doubling the wait
time—if the delay was 5 minutes, it instantly jumps to 10 minutes, leaving drivers questioning all
their life choices. And finally, there's equality (==), critical for detecting traffic gridlocks—when
road A and road B both have 100 cars stuck motionless, it’s official: the city is doomed! Your
mission? Write a TrafficSystem class in C++ that smartly handles all these scenarios with operator
overloading, ensuring that while real-world traffic stays frustrating, at least the code stays
efficient and under control!*/
#include<iostream>
using namespace std;

class TrafficSystem
{
    int cars;
    double timedelayed;

    public:
    TrafficSystem(int c= 0, double m= 0) : cars(c), timedelayed(m) {}

    void display()
    {
        cout << "cars: " << cars << "\ntime: " << timedelayed << endl;
    }

    TrafficSystem operator +(const TrafficSystem& obj)
    {
        TrafficSystem temp;
        temp.cars = cars + obj.cars;
        return temp;
    }

    TrafficSystem operator -(const TrafficSystem& obj)
    {
        TrafficSystem temp;
        temp.cars = cars - obj.cars;
        return temp;
    }

    TrafficSystem operator *()
    {
        timedelayed *= 2;
        return *this;
    }

    bool operator == (const TrafficSystem& obj)
    {
        return (cars == obj.cars);
    }
};

int main()
{
    TrafficSystem t1(15, 3);
    TrafficSystem t2(30, 4);

    TrafficSystem t3 = t1 + t2;
    t3.display();

    TrafficSystem t4 = t2 - t1;
    t4.display();
    
    *(&t1);
    t1.display();

    TrafficSystem t5(30,2.5);
    bool flag = t5==t2;

    if(flag)
    {
        cout << "city is doomed";
    }
    else
    cout << "city is still safe";
    return 0;
} 