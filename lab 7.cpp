#include <iostream>
#include <string>
class Student {
private:
    std::string name;
    int age;
public:
    Student(const std::string& n, int a) : name(n), age(a) {}
    Student(const Student& other) {
        name = other.name;
        age = other.age;
    }
    void display() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};
int main() {
    Student student1("Alice", 20);
    Student student2 = student1;
    std::cout << "Student 1:" << std::endl;
    student1.display();
    std::cout << "\nStudent 2 (copied from Student 1):" << std::endl;
    student2.display();
    return 0;
}
