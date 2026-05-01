#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

// Structure to hold a record
struct Record {
    int identifier;
    long long registerNumber;
    char surname[31];
    char name[31];
    int mark;
};

// Function to read a record from the file
void readRecord(const std::string& filename, int position) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file for reading.");
    }

    Record record;
    file.seekg((position - 1) * sizeof(Record)); // Seek to the record position
    file.read(reinterpret_cast<char*>(&record), sizeof(Record));

    if (!file) {
        std::cout << "Record not found.\n";
        return;
    }

    std::cout << record.identifier << " " << record.registerNumber << " "
              << record.surname << " " << record.name << " " << record.mark << "\n";

    file.close();
}

// Function to write a record to the file
void writeRecord(const std::string& filename, int position) {
    std::ofstream file(filename, std::ios::binary | std::ios::in | std::ios::out);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file for writing.");
    }

    Record record;
    std::cout << "Data: ";
    std::cin >> record.identifier >> record.registerNumber >> record.surname
             >> record.name >> record.mark;
    //std::cin.getline(record.surname, 31);

    file.seekp((position - 1) * sizeof(Record)); // Seek to the record position
    file.write(reinterpret_cast<char*>(&record), sizeof(Record));

    file.close();
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " filename\n";
        return 1;
    }

    try {
        std::string filename = argv[1];
        char command;
        int position;

        while (true) {
            std::cout << "> ";
            std::cin >> command;

            if (command == 'R') {
                std::cin >> position;
                readRecord(filename, position);
            } else if (command == 'W') {
                std::cin >> position;
                writeRecord(filename, position);
            } else if (command == 'E') {
                break;
            } else {
                std::cerr << "Invalid command. Please use R, W, or E.\n";
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
