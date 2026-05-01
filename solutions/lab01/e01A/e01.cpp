#include <iostream>
#include <cstdlib>

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

// Function 2: Sort the array using insertion sort
void sortArray(double* arr, int n) {
    for (int i = 1; i < n; ++i) {
        double key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function 3: Display the array
void displayArray(double* arr, int n) {
    std::cout << "Output sorted array (" << n << " elements): ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <n>" << std::endl;
        return 1;
    }

    int n = std::atoi(argv[1]);
    if (n <= 0) {
        std::cerr << "n must be a positive integer." << std::endl;
        return 1;
    }

    double* myArray = readArray(n);
    sortArray(myArray, n);
    displayArray(myArray, n);

    free(myArray); // Free the allocated memory
    return 0;
}
