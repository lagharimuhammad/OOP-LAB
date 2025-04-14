/*Imagine you're driving on a long road trip, but instead of focusing on the road, you're too busy
trying to remember the classic formula: Distance = Speed × Time. To make life easier (and to avoid
any unnecessary mental gymnastics while driving), let's create two C++ classes—Speed and
Time—to store speed in km/h and time in hours, respectively. Now, because these two are a bit
shy and like to keep their data private, we’ll introduce them to a mutual friend, a friend function
called calculateDistance(), which will sneakily access their private members and compute the total
distance traveled. The goal? Write a C++ program where the calculateDistance() function takes
values from both classes (say, a speed of 60 km/h and a duration of 2 hours) and calculates how
far you've traveled. Finally, in the main() function, instantiate objects with these values and print
out the result—because let’s be honest, no one wants to manually do the math while on a road
trip!*/

#include<iostream>
using namespace std;

class Time;

class Speed
{
    double kmh;
    public:
    Speed(double s) : kmh(s) {}
    friend double calculatedistance(const Speed&, const Time&);
};

class Time
{
    double hours;
    public:
    Time(double t) : hours(t) {}
    friend double calculatedistance(const Speed&, const Time&);
};

double calculatedistance(const Speed& s, const Time& t)
{
    const double dist = s.kmh * t.hours ;
    cout << "distance is: " << dist;
    return dist;
}

int main()
{
    Speed s(60);
    Time t(2);
    calculatedistance(s,t);
    return 0;
}