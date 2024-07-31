#include <iostream>
#include <stdexcept>

unsigned long long factorial_iterative(int n);
unsigned long long factorial_recursive(int n);

int main() {
    int number = 5;

    try {
        std::cout << "Iterative factorial of " << number << " is " << factorial_iterative(number) << std::endl;
        std::cout << "Recursive factorial of " << number << " is " << factorial_recursive(number) << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

unsigned long long factorial_iterative(int n) {
    if (n < 0) {
        throw std::invalid_argument("Factorial is not defined for negative numbers.");
    }
    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

unsigned long long factorial_recursive(int n) {
    if (n < 0) {
        throw std::invalid_argument("Factorial is not defined for negative numbers.");
    }
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial_recursive(n - 1);
    }
}
