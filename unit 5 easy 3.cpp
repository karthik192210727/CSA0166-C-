#include <iostream>
using namespace std;

class Number {
protected:
    int M, N, K;
public:
    void getData() {
        cout << "Enter starting number (M): ";
        cin >> M;
        cout << "Enter ending number (N): ";
        cin >> N;
        cout << "Enter the number to skip (K): ";
        cin >> K;
    }
};

class Skipper : public Number {
public:
    void printSkippedNumbers() {
        for (int i = M; i <= N; i += (K + 1)) {
            cout << i;
            if (i + (K + 1) <= N) {
                cout << ", ";
            }
        }
        cout << endl;
    }
};

int main() {
    Skipper skipper;

    skipper.getData();
    skipper.printSkippedNumbers();

    return 0;
}
