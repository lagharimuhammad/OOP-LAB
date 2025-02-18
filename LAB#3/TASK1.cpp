#include <iostream>
#include <string>
using namespace std;

class BoardMarker
{
private:
    string company_name;
    string color_marker;
    bool is_refill;
    bool status;

public:

    string getter_company_name()
    {
        return company_name;
    }
    string getter_color_marker()
    {
        return color_marker; 
    }
    bool is_refillable()
    { 
        return is_refill;
    }
    bool getter_status()
    { 
        return status; 
    }

    void setter(const string &comp, const string &col, bool refill, bool ink)
    
    {
        company_name = comp; 
        color_marker = col; 
        is_refill = refill; 
        status = ink; 
    }

    void write()
    {
        if (!getter_status())
        {
            cout << "ink is empty, cannot write."<< endl;
        }
        else
        {
            cout << "marker is full, can write"<< endl;
        }
    }

    void refill()
    {
        if (!is_refill)
        {
            status = true;
            cout << "refilled marker" << endl;
        }
        else
        {
            cout << "cannot refilled" << endl;
        }
    }
};

int main()
{
    BoardMarker m1;
    BoardMarker m2;
    BoardMarker m3;
    m1.setter("Signature", "Black", true, true);
    m2.setter("Signature", "red", false, false);
    m3.setter("Signature", "blue", true, false);

    
    cout << "Marker 1:";
    m1.write();
    m1.refill();
    m1.write();

    cout << "\nMarker 2:";
    m2.write();
    m2.refill();
    m2.write();

    cout << "\nMarker 3:";
    m3.write();
    m3.refill();
    m3.write();

    return 0;
}
