#include <iostream>
#include <string>
using namespace std;
class Airport
{
private:
    string name;
    string city;

public:
    Airport(string naame = "Unknown", string city_name = "Unknown") : name(naame), city(city_name) {}

    void setDetails(string naame, string city_name) 
    {
        name = naame;
        city = city_name;
    }
    void show() const
	{
        cout << "Airport:  " << name << "\ncity: " << city << endl;
    }
};
class Flight 
{
private:
    string flight_no;
    Airport airport_stops[10]; 
    int stop_counter;
public:
    Flight(string fn = "Unknown") : flight_no(fn), stop_counter(0) {}

    void add_stop(const Airport& air_port) 
    {
        if (stop_counter < 10) 
        {
            airport_stops[stop_counter++] = air_port;
        } 
		else
		{
            cout << "no more stop can be added" << endl;
        }
    }
    void show() 
    const{
        cout << "Flight: " << flight_no << endl;
        for (int i = 0; i < stop_counter; i++) 
        {
            cout << "Stop " << i+1 << ": ";
            airport_stops[i].show();
        }
    }
};
int main() 
{
    Airport Hyderabad("Hyderabad International", "Hyderabad, Sindh");
    Airport Karachi("Karachi International", "Karachi, Sindh");
    Airport Batu("Malaysia International", "Batu, Kaula Lumpur");
    Flight pk0006("PK-0006");
    pk0006.add_stop(Hyderabad); 
    pk0006.add_stop(Karachi);
    pk0006.add_stop(Batu);
    pk0006.show();
    return 0;
}
