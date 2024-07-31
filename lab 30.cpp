#include <iostream>
#define MAX 10
using namespace std;

class stack {
private:
    int arr[MAX], top;

public:
    stack() {
        top = -1;
    }

    void push(int item) {
        if (top == MAX - 1) {
            cout << endl << "Stack is full";
            return;
        }
        top++;
        arr[top] = item;
    }

    int pop() {
        if (top == -1) {
            cout << endl << "Stack is empty";
            return -1;  // Return a special value to indicate an empty stack
        }
        int data = arr[top];
        top--;
        return data;
    }
};

int main() {
    stack s;

    // Attempt to pop from an empty stack
    int i = s.pop();
    cout << endl << "Item popped=" << i;
    i = s.pop();
    cout << endl << "Item popped=" << i;
    i = s.pop();
    cout << endl << "Item popped=" << i;
    i = s.pop();
    cout << endl << "Item popped=" << i;

    // Push items into the stack
    s.push(11);
    s.push(12);
    s.push(13);
    s.push(14);
    s.push(15);
    s.push(16);
    s.push(17);
    s.push(18);
    s.push(19);
    s.push(20);
    s.push(21);  // This will show "Stack is full"

    // Pop items from the stack
    i = s.pop();
    cout << endl << "Item popped=" << i;
    i = s.pop();
    cout << endl << "Item popped=" << i;
    i = s.pop();
    cout << endl << "Item popped=" << i;
    i = s.pop();
    cout << endl << "Item popped=" << i;

    return 0;
}
