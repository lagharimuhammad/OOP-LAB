#include <iostream>
using namespace std;

class Activity
{
public:
    virtual void calculateCaloriesBurned() = 0;
};

class Running : public Activity
{
private:
    double distance;
    double time;

public:
    Running(double d, double t) : distance(d), time(t) {}
    void calculateCaloriesBurned() override
    {
        cout << "Calories burned while Running: " << 60 * distance << endl;
    }
};
class Cycling : public Activity
{
    double speed;
    double time;

public:
    Cycling(double s, double t) : speed(s), time(t) {}
    void calculateCaloriesBurned() override
    {
        cout << "Calories burned while Cycling: " << 30 * speed * (time / 60.0) << endl;
    }
};

int main()
{
    Running run(5.6, 30);
    Cycling cycle(10.5, 45);
    run.calculateCaloriesBurned();
    cycle.calculateCaloriesBurned();
    return 0;
}