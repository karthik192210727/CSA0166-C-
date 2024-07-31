#include <iostream>
#include <string>
class Manager {
private:
    std::string name;
    int age;
public:
    Manager(const std::string& name = "", int age = 0) : name(name), age(age) {}
    void setDetails(const std::string& name, int age) {
        this->name = name;
        this->age = age;
    }
    void display() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};
int main() {
    const int numManagers = 3;
    Manager managers[numManagers];
    managers[0].setDetails("Alice Johnson", 45);
    managers[1].setDetails("Bob Smith", 50);
    managers[2].setDetails("Carol Davis", 39);
    std::cout << "List of Managers:" << std::endl;
    for (int i = 0; i < numManagers; ++i) {
        managers[i].display();
    }
    return 0;
}
