#include <iostream>
using namespace std;
class AddAmount {
protected:
    double amount;
public:
    AddAmount() : amount(50) {} 
    virtual void addAmount(double additionalAmount) = 0;
    double getAmount() const { return amount; }
};

class AddToPiggieBank : public AddAmount {
public:
    AddToPiggieBank(double additionalAmount) {
        addAmount(additionalAmount);
    }

    void addAmount(double additionalAmount) {
        amount += additionalAmount;
    }
};

int main() {
    double additionalAmount;
    cout << "Enter the amount to add: ";
    cin >> additionalAmount;

    AddToPiggieBank piggyBank(additionalAmount);
    cout << "Total Amount is = " << piggyBank.getAmount() << endl;

    return 0;
}
