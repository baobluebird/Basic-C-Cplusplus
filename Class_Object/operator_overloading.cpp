#include <iostream>
using namespace std;

class Complex
{
private:
    float real;
    float imag;

public:
    // Constructor
    Complex(float r = 0, float i = 0) : real(r), imag(i) {}

    // Function overloading operator '+'
    Complex operator+(const Complex &other)
    {
        return Complex(real + other.real, imag + other.imag);
    }

    // Function to display complex numbers
    void display()
    {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main()
{
    Complex c1(3.5, 2.5);
    Complex c2(1.5, 4.5);
    Complex c3 = c1 + c2; // Call the overloaded '+' operator

    cout << "c1 + c2 = ";
    c3.display();

    return 0;
}