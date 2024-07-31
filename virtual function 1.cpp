#include <iostream>
#include <cmath>

class Shape {
public:
    virtual double area() const = 0; 
};

class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override {
        return width * height;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return M_PI * radius * radius;
    }
};

int main() {
    Shape* rect = new Rectangle(5.0, 3.0);
    Shape* circ = new Circle(4.0);
    std::cout << "Area of Rectangle: " << rect->area() << std::endl;
    std::cout << "Area of Circle: " << circ->area() << std::endl;
    delete rect;
    delete circ;
    return 0;
}

