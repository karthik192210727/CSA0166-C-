
#include <iostream>
using namespace std;

class Compare {
private:
    int num;

public:
    Compare(int n) : num(n) {}
    friend int findMax(Compare c1, Compare c2);
};
int findMax(Compare c1, Compare c2) {
    return (c1.num > c2.num) ? c1.num : c2.num;
}

int main() {
    int a, b;
    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;

    Compare c1(a), c2(b);

    cout << "The maximum number is: " << findMax(c1, c2) << endl;

    return 0;
}
