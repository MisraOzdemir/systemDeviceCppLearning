#include "f.h"

// Function 3: Display the array
void displayArray(double* arr, int n) {
    std::cout << "Output sorted array (" << n << " elements): ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
