#include <iostream>
using namespace std;
class IncomeTax {
public:
    virtual void TDS(double income) const = 0; 
};
class Slab1 : public IncomeTax {
private:
    IncomeTax* nextSlab;
public:
    Slab1(IncomeTax* next = NULL) : nextSlab(next) {}

    void TDS(double income) const {
        if (income <= 150000) {
            cout << "No tax" << endl;
        } else {
            if (nextSlab != NULL) {
                nextSlab->TDS(income);
            }
        }
    }
};
class Slab2 : public IncomeTax {
private:
    IncomeTax* nextSlab;
public:
    Slab2(IncomeTax* next = NULL) : nextSlab(next) {}

    void TDS(double income) const {
        if (income <= 300000) {
            cout << "Tax = " << (income - 150000) * 0.10 << endl;
        } else {
            if (nextSlab != NULL) {
                nextSlab->TDS(income);
            }
        }
    }
};
class Slab3 : public IncomeTax {
public:
    Slab3() {}

    void TDS(double income) const {
        if (income <= 500000) {
            cout << "Tax = " << (income - 300000) * 0.20 + 15000 << endl;
        } else {
            cout << "Tax = " << (income - 500000) * 0.30 + 55000 << endl;
        }
    }
};

int main() {
    Slab3 slab3;
    Slab2 slab2(&slab3);
    Slab1 slab1(&slab2);
    double income;
    cout << "Enter the total income: ";
    cin >> income;
    slab1.TDS(income);
    return 0;
}
