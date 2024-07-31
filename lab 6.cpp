#include <iostream>
class Complex {
private:
    double real;
    double imag;
public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}
    friend Complex addComplex(const Complex &c1, const Complex &c2);
    void display() const {
        if (imag >= 0)
            std::cout << real << " + " << imag << "i" << std::endl;
        else
            std::cout << real << " - " << -imag << "i" << std::endl;
    }
};
Complex addComplex(const Complex &c1, const Complex &c2) {
    Complex temp;
    temp.real = c1.real + c2.real;
    temp.imag = c1.imag + c2.imag;
    return temp;
}
int main() {
    Complex num1(3.5, 2.5);
    Complex num2(1.5, 4.5);
    std::cout << "First complex number: ";
    num1.display();
    std::cout << "Second complex number: ";
    num2.display();
    Complex sum = addComplex(num1, num2);
    std::cout << "Sum of the complex numbers: ";
    sum.display();
    return 0;
}
