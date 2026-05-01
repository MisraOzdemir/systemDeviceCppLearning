//
// C++ Version
//

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <stdexcept>

using std::strncpy;

// Structure to hold a record
struct Record {
  int identifier;
  long long registerNumber;
  char surname[31];
  char name[31];
  int mark;
};

// Function to convert text file to binary file
void textToBinary(const std::string& inputFilename, const std::string& outputFilename) {
    std::ifstream inputFile(inputFilename);
    if (!inputFile.is_open()) {
        throw std::runtime_error("Failed to open input file.");
    }

    std::ofstream outputFile(outputFilename, std::ios::binary);
    if (!outputFile.is_open()) {
        throw std::runtime_error("Failed to open output file.");
    }

    Record record;
    int identifier;
    long long registerNumber;
    std::string surname, name;
    int mark;

    while (inputFile >> identifier >> registerNumber >> surname >> name >> mark) {
        record.identifier = identifier;
        record.registerNumber = registerNumber;

        // Copy strings into fixed-length arrays
        std::strncpy(record.surname, surname.c_str(), 30);
        record.surname[30] = '\0'; // Ensure null-termination
        std::strncpy(record.name, name.c_str(), 30);
        record.name[30] = '\0'; // Ensure null-termination

        record.mark = mark;

        // Write record to binary file
        outputFile.write(reinterpret_cast<char*>(&record), sizeof(Record));
    }

    inputFile.close();
    outputFile.close();
}

// Function to convert binary file back to text file
void binaryToText(const std::string& inputFilename, const std::string& outputFilename) {
    std::ifstream inputFile(inputFilename, std::ios::binary);
    if (!inputFile.is_open()) {
        throw std::runtime_error("Failed to open input file.");
    }

    std::ofstream outputFile(outputFilename);
    if (!outputFile.is_open()) {
        throw std::runtime_error("Failed to open output file.");
    }

    Record record;

    while (inputFile.read(reinterpret_cast<char*>(&record), sizeof(Record))) {
        outputFile << record.identifier << " " << record.registerNumber << " "
                   << record.surname << " " << record.name << " " << record.mark << "\n";
    }

    inputFile.close();
    outputFile.close();
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " file_1 file_2 file_3\n";
        return 1;
    }

    try {
        textToBinary(argv[1], argv[2]);
        binaryToText(argv[2], argv[3]);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
