#include <iostream>
#include <string>
using namespace std;

class SmartDevice 
{
private:
    string device_name;
    string device_type;
    bool device_status;

public:
    SmartDevice(string name, string type, bool is_on) : device_name(name), device_type(type), device_status(is_on) 
        {
        cout << device_name << " (" << device_type << ") is now " << (device_status ? "ON." : "OFF.") << endl;
        }

    ~SmartDevice() 
        {
            cout << device_name << " is powered off" << endl;
        }
};

int main() {
    SmartDevice* bulb = new SmartDevice("Room Light", "Smart Light", true);
    SmartDevice* vaccum = new SmartDevice("Vaccum X3000", "Vacuum Cleaner", false);
    SmartDevice* tea_maker = new SmartDevice("Tea Head", "Smart Tea Maker", true);
    
    delete bulb;
    delete vaccum;
    delete tea_maker;
    
    return 0;
}
