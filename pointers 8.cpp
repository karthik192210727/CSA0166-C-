#include <iostream>

int main() {
    float numbers[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    float *arrayPointer = numbers;
    std::cout << "The values of the float array are: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << arrayPointer[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
