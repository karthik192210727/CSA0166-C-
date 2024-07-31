#include <iostream>
void displayMessage() {
    std::cout << "Hello from the function!" << std::endl;
}
int main() {
    void (*functionPointer)() = &displayMessage;
    (*functionPointer)();
    return 0;
}
