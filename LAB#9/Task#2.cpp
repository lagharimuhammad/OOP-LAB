#include <iostream>
using namespace std;

class SmartDevice
{
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual bool getStatus() const = 0;
};

class LightBulb : public SmartDevice
{
private:
    bool isOn;
    int brightness;

public:
    LightBulb(bool stat, int b) : isOn(stat), brightness(b) {}
    void turnOn() override
    {
        isOn = true;
        cout << "Light Bulb turned On Brightness level " << brightness << "%" << endl;
    }
    void turnOff() override
    {
        isOn = false;
        cout << "Light Bulb turned Off" << endl;
    }
    bool getStatus() const override
    {
        return isOn;
    }
};
class Thermostat : public SmartDevice
{
private:
    bool isOn;
    double temperature;

public:
    Thermostat(bool stat, double temp): isOn(stat), temperature(temp){}
    void turnOn() override
    {
        isOn = true;
        cout << "Thermostat turned On, temperature: " <<temperature<< endl;
    }
    void turnOff() override
    {
        isOn = false;
        cout << "Thermostat turned Off" << endl;
    }
    bool getStatus() const override
    {
        return isOn;
    }
};
int main(){
    LightBulb bulb(false, 72);
    Thermostat t(true, 45);
    bulb.turnOn();
    bulb.turnOff();
    cout << "Bulb Status : " << (bulb.getStatus() ? "On" : "Off") << endl;
    t.turnOn();
    t.turnOff();
    cout << "Thermostat Status : " << (t.getStatus() ? "On" : "Off") << endl;
    return 0;
}