#include <iostream>
using namespace std;

class IndexOutOfBoundsException {
public:
    const char* what() const {
        return "Array index out of boundary.";
    }
};

int main() {
    int x[] = {10, 20, 30, 40};
    int index;

    cout << "Enter an index to access: ";
    cin >> index;

    try {
        if (index < 0 || index >= sizeof(x) / sizeof(x[0])) {
            throw IndexOutOfBoundsException();
        }
        cout << "Element at index " << index << " is " << x[index] << endl;
    } catch (const IndexOutOfBoundsException& e) {
        cout << e.what() << endl;
    }

    return 0;
}
