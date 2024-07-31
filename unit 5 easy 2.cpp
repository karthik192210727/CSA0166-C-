#include <iostream>
using namespace std;
class Shape {
protected:
    double length, breadth, height;
public:
    void getDimensions() {
        cout << "Enter LENGTH: ";
        cin >> length;
        cout << "Enter BREADTH: ";
        cin >> breadth;
        cout << "Enter HEIGHT: ";
        cin >> height;
    }
};
class Rectangle : virtual public Shape {
public:
    double calculateArea() {
        return length * breadth;
    }
};
class Cuboid : public Rectangle {
public:
    double calculateVolume() {
        return length * breadth * height;
    }
};
int main() {
    Cuboid cuboid;
    cuboid.getDimensions();
    cout << "AREA OF RECTANGLE = " << cuboid.calculateArea() << endl;
    cout << "VOLUME OF RECTANGLE = " << cuboid.calculateVolume() << endl;
    return 0;
}
