#include <iostream>
#include <cmath> // For M_PI constant

double calculateCircleArea(double radius);

int main() {
    double radius = 5.0;
    double area = calculateCircleArea(radius);

    std::cout << "Radius of the circle: " << radius << std::endl;
    std::cout << "Area of the circle: " << area << std::endl;

    return 0;
}

double calculateCircleArea(double radius) {
    return M_PI * radius * radius;
}
