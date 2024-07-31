#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    string emp_id;
    double basicSalary;
public:
    Employee(const string& n, const string& id, double salary)
        : name(n), emp_id(id), basicSalary(salary) {}
};
class Pay : public Employee {
public:
    Pay(const string& n, const string& id, double salary)
        : Employee(n, id, salary) {}

    void calculatePay() const {
        double grossSalary = basicSalary * 1.7;
        double deduction = basicSalary * 0.5;
        double netSalary = grossSalary - deduction;

        cout << "Gross salary: " << grossSalary << endl;
        cout << "Deduction: " << deduction << endl;
        cout << "Net salary = " << netSalary << endl;
    }
};

int main() {
    string name, emp_id;
    double salary;

    cout << "Enter employee name: ";
    cin >> name;
    cout << "Enter employee ID: ";
    cin >> emp_id;
    cout << "Enter employee salary: ";
    cin >> salary;

    Pay employee(name, emp_id, salary);
    employee.calculatePay();

    return 0;
}
