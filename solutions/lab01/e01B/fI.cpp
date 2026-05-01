#include "f.h"

// Function 1: Dynamically allocate and read array
double* readArray(int n) {
    double* arr = (double*)malloc(n * sizeof(double));
    if (arr == nullptr) {
        std::cerr << "Memory allocation failed." << std::endl;
        exit(1);
    }
    std::cout << "Input array (" << n << " elements): "; 
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    return arr;
}
