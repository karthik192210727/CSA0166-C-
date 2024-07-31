#include <iostream>
using namespace std;

class Shape {
public:
    virtual double area() const = 0;
};
class Rectangle : public Shape {
protected:
    double length;
    double breadth;
public:
    Rectangle(double l = 0, double b = 0) : length(l), breadth(b) {}
    double area() const {
        return length * breadth;
    }
};
class Cuboid : public Rectangle {
protected:
    double height;
public:
    Cuboid(double l, double b, double h) : Rectangle(l, b), height(h) {}

    void display() const {
        cout << "Area of rectangle: " << area() << endl;
        cout << "Volume of cuboid: " << area() * height << endl;
    }
};

int main() {
    double length, breadth, height;

    cout << "Enter length: ";
    cin >> length;
    cout << "Enter breadth: ";
    cin >> breadth;
    cout << "Enter height: ";
    cin >> height;

    Cuboid cuboid(length, breadth, height);
    cuboid.display();

    return 0;
}
