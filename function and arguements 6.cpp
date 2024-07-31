#include <iostream>
#include <climits> 

void findMinAndMax(int arr[], int size, int& minElement, int& maxElement);

int main() {
    int arr[] = {3, 7, 1, 9, 5, 2, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    int minElement, maxElement;

    findMinAndMax(arr, size, minElement, maxElement);

    std::cout << "Minimum element in the array: " << minElement << std::endl;
    std::cout << "Maximum element in the array: " << maxElement << std::endl;

    return 0;
}

void findMinAndMax(int arr[], int size, int& minElement, int& maxElement) {
    if (size <= 0) {
    
        std::cerr << "Error: Empty array." << std::endl;
        return;
    }

    minElement = INT_MAX; 
    maxElement = INT_MIN; 

    for (int i = 0; i < size; ++i) {
        if (arr[i] < minElement) {
            minElement = arr[i];
        }
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }
}
