#include <iostream>
using namespace std;
class Grandfather {
protected:
    int propertyValue;
public:
    Grandfather(int value) : propertyValue(value) {}
    
    void displayProperty() const {
        cout << "Property value: " << propertyValue << " Cr" << endl;
    }
};
class Father : public Grandfather {
public:
    Father(int value) : Grandfather(value) {}
};
class Grandson : public Father {
public:
    Grandson(int value) : Father(value) {}
    
    void receiveProperty() {
        cout << "Received the Property" << endl;
        displayProperty();
    }
};
int main() {
    int propertyValue = 500;
    Grandson grandson(propertyValue);
    grandson.receiveProperty();

    return 0;
}
