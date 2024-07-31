#include <iostream>
#include <string>

class Manager {
public:
    std::string name;
    int age;

    Manager() : name(""), age(0) {}

    Manager(const std::string& name, int age) : name(name), age(age) {}

    void display() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

int main() {
    const int numManagers = 3;
    Manager managers[numManagers];
    for (int i = 0; i < numManagers; ++i) {
        std::cout << "Enter details for manager " << (i + 1) << ":\n";
        std::cout << "Name: ";
        std::cin >> managers[i].name;
        std::cout << "Age: ";
        std::cin >> managers[i].age;
    }
    std::cout << "\nList of Managers:\n";
    for (int i = 0; i < numManagers; ++i) {
        managers[i].display();
    }
    return 0;
}
