#include <iostream>
using namespace std;

class DivisionByZeroException {
public:
    const char* what() const {
        return "Divide by zero.";
    }
};

int divide(int a, int b) {
    if (b == 0) {
        throw DivisionByZeroException();
    }
    return a / b;
}

int main() {
    int num1, num2;
    cout << "Enter two integers: ";
    cin >> num1 >> num2;

    try {
        int result = divide(num1, num2);
        cout << "Result: " << result << endl;
    } catch (const DivisionByZeroException& e) {
        cout << e.what() << endl;
    }

    return 0;
}
