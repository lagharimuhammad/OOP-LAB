/*A C++ developer, utterly fed up with the simplicity of real numbers, decides to shake things up by
creating a ComplexNumber class—because why settle for numbers that behave when you can
have ones with imaginary side effects? But just storing complex numbers isn’t enough—these
numbers need action and operator overloading to truly unleash their potential! First up is addition
(+), where two numbers team up like superheroes—3 + 4i and 1 + 2i join forces to become 4 + 6i.
Then comes subtraction (-), for when numbers need a little personal space—like 8 + 3i kicking 5 +
6i to the curb, leaving behind a 3 - 3i situation. Of course, there's multiplication (*), where two
numbers combine with chaotic consequences—(2 + 3i) * (1 + 4i) suddenly transforms into -10 +
11i, proving that multiplying complex numbers is anything but simple. Finally, there's the equality
check (==), because some numbers are identical (3 + 5i == 3 + 5i), while others are just wannabes
(3 + 5i != 4 + 5i—nice try). Your mission? Write a ComplexNumber class in C++ that makes all this
mathematical madness possible using operator overloading—because even in C++, numbers
shouldn’t get a free pass to be boring!*/

#include <iostream>
using namespace std;

class Complex
{
    int real;
    int imag;

public:
    Complex() : real(0), imag(0) {}
    Complex(int r, int i) : real(r), imag(i) {}

    Complex operator+(Complex const &para)
    {
        Complex temp;
        temp.real = real + para.real;
        temp.imag = imag + para.imag;
        return temp;
    }

    Complex operator-(Complex const &para)
    {
        Complex temp;
        temp.real = real - para.real;
        temp.imag = imag - para.imag;
        return temp;
    }

    Complex operator*(Complex const &para)
    {
        Complex temp;
        temp.real = real * para.real - imag * para.imag;
        temp.imag = imag * para.imag + imag * para.real;
        return temp;
    }

    bool operator==(Complex const &para)
    {
        if (real == para.real)
        {
            if (imag == para.imag)
                return 1;
        }
        return 0;
    }

    void print()
    {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main()
{
    Complex c1(3, 4);
    Complex c2(7, 6);
    Complex c3 = c1+c2;
    c3.print();
    Complex c4 = c1-c2;
    c4.print();
    Complex c5 = c1*c2;
    c5.print();
    if((c1 == c2))
    {cout << "c1 = c2"; }
    else {cout << "c1 != c2";}
}