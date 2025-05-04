#include <iostream>
using namespace std;

class Vehicle
{
protected:
    string model;
    double rate;

public:
    Vehicle(const string &mName, double dailyRate) : model(mName), rate(dailyRate) {}
    virtual double getDailyRate() const = 0;
    virtual void displayDetails() const = 0;
    virtual ~Vehicle() {}
};

class Car : public Vehicle
{
public:
    Car(const string &mName, double dailyRate) : Vehicle(mName, dailyRate) {}
    double getDailyRate() const override
    {
        return rate;
    }
    void displayDetails() const override
    {
        cout << "Car Model: " << model << endl;
        cout << "Daily Rate: $ " << rate << endl;
    }
};
class Bike : public Vehicle
{
public:
    Bike(const string &mName, double dailyRate) : Vehicle(mName, dailyRate) {}
    double getDailyRate() const override
    {
        return rate;
    }
    void displayDetails() const override
    {
        cout << "Bike Model: " << model << endl;
        cout << "Daily Rate: $ " << rate << endl;
    }
};
int main()
{
    Car c("Tesla", 90000.0);
    Bike b("Yamaha H2R", 450000.0);
    c.displayDetails();
    b.displayDetails();
    return 0;
}