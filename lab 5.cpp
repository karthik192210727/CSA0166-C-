#include <iostream>

class Class2; 

class Class1 {
private:
    int data1;

public:
    Class1(int value) : data1(value) {}
    void display() const {
        std::cout << "Class1 data1: " << data1 << std::endl;
    }
    friend void swapData(Class1 &c1, Class2 &c2);
};

class Class2 {
private:
    int data2;

public:
    Class2(int value) : data2(value) {}
    void display() const {
        std::cout << "Class2 data2: " << data2 << std::endl;
    }
    friend void swapData(Class1 &c1, Class2 &c2);
};
void swapData(Class1 &c1, Class2 &c2) {
    int temp = c1.data1;
    c1.data1 = c2.data2;
    c2.data2 = temp;
}
int main() {
    Class1 obj1(10);
    Class2 obj2(20);

    std::cout << "Before swapping:" << std::endl;
    obj1.display();
    obj2.display();

    swapData(obj1, obj2);

    std::cout << "After swapping:" << std::endl;
    obj1.display();
    obj2.display();

    return 0;
}
