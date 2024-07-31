#include <iostream>
using namespace std;

class Interest {
protected:
    double principal;
    int years;
    double rate;
public:
    Interest(double p, int y, double r) : principal(p), years(y), rate(r) {}
};

class SimpleInterest : public Interest {
public:
    SimpleInterest(double p, int y, double r) : Interest(p, y, r) {}

    void calculateInterest() const {
        double interest = (principal * years * rate) / 100;
        cout << "Simple Interest: " << interest << endl;
    }
};

int main() {
    double principal;
    int years;
    double rate;

    cout << "Enter the principal amount: ";
    cin >> principal;
    cout << "Enter the number of years: ";
    cin >> years;
    cout << "Enter the rate of interest: ";
    cin >> rate;

    SimpleInterest si(principal, years, rate);
    si.calculateInterest();

    return 0;
}
