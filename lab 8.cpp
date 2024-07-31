#include <iostream>
#include <string>
class Student {
private:
    std::string name;
    int age;
public:
    Student(const std::string& n, int a) : name(n), age(a) {}
    void display() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};
int main() {
    Student* ptrStudent = new Student("Alice", 20);
    std::cout << "Student details (using pointer):" << std::endl;
    ptrStudent->display();
    delete ptrStudent;
    return 0;
}
