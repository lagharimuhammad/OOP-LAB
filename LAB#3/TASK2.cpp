#include<iostream>
using namespace std;

class Circle
{
    private:

    double radii;
    double pi = 3.14;

    public:

    void setter_radii(double r)
    {
        radii = r;
    }

    double getter_radii()
    {
        return radii;
    }

    double getter_area()
    {
        double area;
        area = pi * radii * radii;
        return area;
    }

    double getter_diameter()
    {
        double diameter = radii * 2;
        return diameter;
    }
    double getter_circum()
    {
        double circumference = 2 * pi * radii;
        return circumference;
    }
};

int main()
{
    Circle c1;
    double r, A, D, C;
    cout << "enter radius: ";
    cin >> r;

    c1.setter_radii(r);
    A = c1.getter_area();
    D = c1.getter_diameter();
    C = c1.getter_circum();

    cout << "area: " << A << endl;
    cout << "diameter: " << D << endl;
    cout << "circumference: " << C << endl;
    return 0;
}
