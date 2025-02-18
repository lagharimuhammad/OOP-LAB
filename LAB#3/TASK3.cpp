#include <iostream>
#include <string>
using namespace std;

class WaterBottle 
{
private:
    string company_name;
    string bottle_color;
    double water_capacity_litre;
    int water_capacity_mlitre;

public:
    
    string getter_company_name()
    { 
        return company_name; 
    }
    string getter_bottle_color()
    { 
        return bottle_color; 
    }
    double getter_water_capacity_litre()
    { 
        return water_capacity_litre;
    }
    int getter_water_capacity_mlitre()
    { 
        return water_capacity_mlitre; 
    }

    void setter(const string &c_name, const string &color, double capacity_in_litre)
    {
        company_name = c_name;
        bottle_color = color;
        water_capacity_litre = capacity_in_litre;
        water_capacity_mlitre = static_cast<int>(capacity_in_litre * 1000);
    }
    

    void drink_water(int water_in_ml)
    {
        if (water_in_ml > water_capacity_mlitre)
        {
            cout << "not enough water to drink " << water_in_ml << " ml. increase drink capacity" << endl;
            water_capacity_litre = 0;
            water_capacity_mlitre = 0;
        } 
        else
        {
            water_capacity_mlitre -= water_in_ml;
            water_capacity_litre = water_capacity_mlitre / 1000.0;
            cout << "after drinking " << water_in_ml << "ml of water. remaining is: " << water_capacity_mlitre << "ml" << endl;
        }
    }
};

int main() 
{
    WaterBottle b;
    b.setter("Hope", "Purple", 1.7);
    cout << "Water Bottle:" << endl;
    cout << "name: " << b.getter_company_name() << endl;
    cout << "Color: " << b.getter_bottle_color() << endl;
    cout << "Capacity: " << b.getter_water_capacity_litre() << "L (" << b.getter_water_capacity_mlitre() << "ml)\n";
    b.drink_water(250); 
    b.drink_water(500); 
    b.drink_water(800); 

    return 0;
}
