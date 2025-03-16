#include <iostream>
#include <string>
using namespace std;

class Vehicle 
{
public:
    string company;
    string model;
    int year;
    Vehicle(string c, string m, int y) : company(c), model(m), year(y) {}
};

class Car : public Vehicle 
{
public:
    int door;
    double fuel_E;
    Car(string c, string m, int y, int d, double f) : Vehicle(c, m, y), door(d), fuel_E(f) {}
};

class ElectricCar : public Car 
{
public:
    int battery_length;
    ElectricCar(string c, string m, int y, int d, double f, int b) : Car(c, m, y, d, f), battery_length(b) {}
    void display() 
	{
        cout << "company: " << company << endl << "model: " << model << endl << "year: " << year << endl << "door: " << door << endl << "fuel effenicncy: " << fuel_E << endl << "battery length: " << battery_length << endl;
    }
};

int main() 
{
    ElectricCar e("Teasla", "model s", 2025, 4, 111, 277);
    e.display();
    return 0;
}
