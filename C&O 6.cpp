#include <iostream>
using namespace std;

class Complex {
private:
    float real;
    float imag;

public:
    Complex() : real(0), imag(0) {}

    Complex(float r, float i) : real(r), imag(i) {}

    void display() const {
        cout << real << " + " << imag << "i" << endl;
    }

    friend Complex addComplex(const Complex &c1, const Complex &c2);
};

Complex addComplex(const Complex &c1, const Complex &c2) {
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

int main() {
    Complex num1(3.4, 5.6);
    Complex num2(1.2, 3.8);

    cout << "First complex number: ";
    num1.display();

    cout << "Second complex number: ";
    num2.display();

    Complex sum = addComplex(num1, num2);

    cout << "Sum of complex numbers: ";
    sum.display();

    return 0;
}
