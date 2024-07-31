#include <iostream>
using namespace std;

class Student {
private:
    double marks[4];

public:
    void getMarks() {
        cout << "Enter the marks in Python: ";
        cin >> marks[0];
        cout << "Enter the marks in C programming: ";
        cin >> marks[1];
        cout << "Enter the marks in Mathematics: ";
        cin >> marks[2];
        cout << "Enter the marks in Physics: ";
        cin >> marks[3];
    }

    void calculateGrade() {
        double total = 0;
        for (int i = 0; i < 4; i++) {
            total += marks[i];
        }
        double aggregate = total / 4;

        if (aggregate < 50) {
            cout << "Fail" << endl;
        } else {
            cout << "Pass" << endl;
        }
    }
};

int main() {
    Student student;
    student.getMarks();
    student.calculateGrade();
    return 0;
}
