#include "f.h"

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
