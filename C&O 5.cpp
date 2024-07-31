#include <iostream>
using namespace std;

class class_2;

class class_1 {
private:
    int data1;

public:
    class_1(int value) : data1(value) {}

    void display() const {
        cout << "class_1 data: " << data1 << endl;
    }
    friend void swapData(class_1 &obj1, class_2 &obj2);
};

class class_2 {
private:
    int data2;

public:
    class_2(int value) : data2(value) {}

    void display() const {
        cout << "class_2 data: " << data2 << endl;
    }
    friend void swapData(class_1 &obj1, class_2 &obj2);
};
void swapData(class_1 &obj1, class_2 &obj2) {
    int temp = obj1.data1;
    obj1.data1 = obj2.data2;
    obj2.data2 = temp;
}
int main() {
    class_1 obj1(10);
    class_2 obj2(20);
    cout << "Before swapping:" << endl;
    obj1.display();
    obj2.display();
    swapData(obj1, obj2);
    cout << "After swapping:" << endl;
    obj1.display();
    obj2.display();
    return 0;
}
