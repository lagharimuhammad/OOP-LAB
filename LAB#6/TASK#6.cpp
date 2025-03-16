#include <iostream>
#include <string>
using namespace std;

class Device 
{
public:
    string brand;
    string model;
    Device(string b, string m) : brand(b), model(m) {}
};

class Smartphone : virtual public Device 
{
public:
    int sims;
    Smartphone(string b, string m, int s) : Device(b, m), sims(s) {}
};

class Tablet : virtual public Device 
{
public:
    bool stylus;
    Tablet(string b, string m, bool st) : Device(b, m), stylus(st) {}
};

class HybridDevice : public Smartphone, public Tablet 
{
public:
    HybridDevice(string b, string m, int s, bool st) : Device(b, m), Smartphone(b, m, s), Tablet(b, m, st) {}
    void display() 
	{
        cout << "brand: " << brand << endl << "model: " << model << endl << "no of sims: " << sims << endl << "stylus support: " << (stylus ? "Yes" : "No") << endl;
    }
};

int main()
{
    HybridDevice hb1("TECH", "ProZ", 1, false);
    hb1.display();
    cout << endl;
    HybridDevice hb2("TECH", "ProX", 2, true);
    hb2.display();
    return 0;
}
