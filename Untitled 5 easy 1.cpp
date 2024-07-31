#include <iostream>
using namespace std;
class Person {
protected:
    float salary;
public:
    void getdata() {
        cout << "Enter salary: ";
        cin >> salary;
    }
    void displaydata() const {
        cout << "Salary: " << salary << endl;
    }
    virtual void bonus() const {
        cout << "Bonus = " << (salary * 1.10) << endl; 
    }
};
class Admin : virtual public Person {
public:
    void getdata() {
        Person::getdata();
    }
    void displaydata() const {
        Person::displaydata();
    }
    void bonus() const {
        Person::bonus();
    }
};
class Account : virtual public Person {
public:
    void getdata() {
        Person::getdata();
    }
    void displaydata() const {
        Person::displaydata();
    }
    void bonus() const {
        Person::bonus();
    }
};
class Master : public Admin, public Account {
public:
    void getdata() {
        Admin::getdata();
    }
    void displaydata() const {
        Admin::displaydata();
    }
    void bonus() const {
        Admin::bonus();
    }
};
int main() {
    Master employee;

    employee.getdata();
    employee.displaydata();
    employee.bonus();
    return 0;
}
