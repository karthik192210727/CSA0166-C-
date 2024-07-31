#include <iostream>

class ClassA;

class ClassB {
private:
    int numB;

public:
    ClassB(int b) : numB(b) {}

    friend int findMax(const ClassA& a, const ClassB& b);
};

class ClassA {
private:
    int numA;

public:
    ClassA(int a) : numA(a) {}
    friend int findMax(const ClassA& a, const ClassB& b);
};
int findMax(const ClassA& a, const ClassB& b) {
    return (a.numA > b.numB) ? a.numA : b.numB;
}

int main() {
    ClassA objA(10);
    ClassB objB(20);

    std::cout << "The maximum number is: " << findMax(objA, objB) << std::endl;

    return 0;
}
