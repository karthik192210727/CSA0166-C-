#include <iostream>
class Person {
public:
    std::string name;
    int age;
    Person(std::string n, int a) : name(n), age(a) {}
};
int main() {
    Person person("John Doe", 30);
    Person* personPointer = &person;
    std::cout << "Name: " << personPointer->name << std::endl;
    std::cout << "Age: " << personPointer->age << std::endl;
    return 0;
}
