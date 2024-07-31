#include <iostream>
using namespace std;
class Person {
public:
    virtual void getdata() = 0;
    virtual void displaydata() const = 0;
    virtual void calculateBonus() const = 0;
};
class Admin : public Person {
protected:
    double salary;
public:
    void getdata() {
        cout << "Enter the salary: ";
        cin >> salary;
    }

    void displaydata() const {
        cout << "Salary: " << salary << endl;
    }

    void calculateBonus() const {
        cout << "Bonus = " << salary * 1.02 << endl; 
    }
};
class Account : public Person {
protected:
    double salary;
public:
    void getdata() {
        cout << "Enter the salary: ";
        cin >> salary;
    }

    void displaydata() const {
        cout << "Salary: " << salary << endl;
    }

    void calculateBonus() const {
        cout << "Bonus = " << salary * 1.03 << endl; 
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

    void calculateBonus() const {
        Admin::calculateBonus(); 
    }
};

int main() {
    Master master;
    master.getdata();
    master.displaydata();
    master.calculateBonus();
    return 0;
}
