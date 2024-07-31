#include <iostream>
int main() {
    char character = 'A';
    char *charPointer = &character;
    std::cout << "The value of the char variable is: " << *charPointer << std::endl;
    return 0;
}
