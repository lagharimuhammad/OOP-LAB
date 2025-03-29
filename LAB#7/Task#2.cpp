#include <iostream>
#include <cmath>
using namespace std;
class Shape 
{
public:
    int x, y;
    string color;
    double border_thickness;
    Shape(int x, int y, string color, double border_thickness = 0.0) : x(x), y(y), color(color), border_thickness(border_thickness) {}
    virtual void draw() = 0;
    virtual double calculate_a() = 0;
    virtual double calculate_p() = 0;
};
class Circle : public Shape 
{
public:
    double radius;
    Circle(int x, int y, string color, double radius, double border_thickness = 0.0) : Shape(x, y, color, border_thickness), radius(radius) {}
    void draw() override 
    {
        cout << "drawing cirrcle at ("<< x<< ","<< y<<") with radius " << radius << endl;
    }
    double calculate_a() override 
    {
        return 3.142*radius*radius;
    }
    double calculate_p() override 
    {
        return 2*3.142*radius;
    }
};
class Rectangle : public Shape 
{
public:
    double width, height;
    Rectangle(int x, int y, string color, double width, double height, double border_thickness = 0.0) : Shape(x, y, color, border_thickness), width(width), height(height) {}
    void draw() override 
    {
        cout << "DRawing rectangle at ("<<x<<","<<x<<") with width " << width << " and height " << height << endl;
    }
    double calculate_a() override 
    {
        return width*height;
    }
    double calculate_p() override 
    {
        return 2*(width+height);
    }
};
class Triangle : public Shape 
{
public:
    double base, height, side1, side2, side3;
    Triangle(int x, int y, string color, double base, double height, double side1, double side2, double side3, double border_thickness = 0.0) : Shape(x, y, color, border_thickness), base(base), height(height), side1(side1), side2(side2), side3(side3) {}
    void draw() override 
    {
        cout << "Drawing Triangle at ("<< x<< ", " << y <<") with base " << base << " and height " << height << "\n";
    }
    double calculate_a() override 
    {
        return 0.5*base*height;
    }
    double calculate_p() override 
    {
        return side1+side2+side3;
    }
};

int main() {
    Circle c(10, 10, "Red", 5);
    Rectangle r(20, 20, "Blue", 10, 15);
    Triangle t(5, 5, "Green", 6, 8, 5, 6, 7);
    c.draw();
    cout << "circle Area: "  << endl << c.calculate_a() << endl;
    cout << "circle Perimeter: " << endl << c.calculate_p() << endl;
    r.draw();
    cout << "rectangle Area: " << endl << r.calculate_a() << endl;
    cout << "ectangle Perimeter: " << endl << r.calculate_p() << endl;
    t.draw();
    cout << "triangle Area: " << endl << t.calculate_a() << endl;
    cout << "rectangle Perimeter: " << endl << t.calculate_p() << endl;
    return 0;
}