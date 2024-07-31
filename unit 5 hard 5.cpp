#include <iostream>
#include <stdexcept> // For std::runtime_error
using namespace std;

class TooSmallException {
public:
    const char* what() const {
        return "The number is too small.";
    }
};

class NegativeNumberException {
public:
    const char* what() const {
        return "Accept only positive integers.";
    }
};

int main() {
    double num;
    cout << "Enter a number: ";
    cin >> num;

    try {
        if (num < 0) {
            throw NegativeNumberException();
        } else if (num < 0.0001) {
            throw TooSmallException();
        } else {
            cout << "Number is acceptable." << endl;
        }
    } catch (const TooSmallException& e) {
        cout << e.what() << endl;
    } catch (const NegativeNumberException& e) {
        cout << e.what() << endl;
    }

    return 0;
}
