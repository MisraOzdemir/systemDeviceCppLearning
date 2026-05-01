//
// Created by Mısra Özdemir on 30.04.2026.
//

#include "./inputOutputTrials.h"
#include <iostream>
#include <fstream>
using namespace std;

void take_3_and_sum() {
    int i = 0;
    int sum = 0;
    int sayi;
    while (i < 3) {
        cout << "sayı girin"  << endl;
        cin >> sayi;
        sum = sum + sayi;
        i++;
    }
    cout << "toplam:" << sum << " adet: " << i << endl;
}

void take_until_0_and_sum() {
    int i = 0;
    int sum = 0;
    int sayi;
    while (true) {
        cout << "sayi girin"  << endl;
        cin >> sayi;
        if (sayi == 0) break;
        sum = sum + sayi;
        i++;
    }
    cout << "toplam:" << sum << " adet: " << i << endl;
}

void read_file_and_sum_numbers() {
    int a, b, c, d;
    ifstream inputFile("inputFile.txt");
    if (inputFile.is_open()) {
        inputFile >> a >> b >> c >> d;
        cout << a << " " << b << " " << c << " " << d << endl;
        cout << "toplam:" << a + b + c + d << endl;
    }
    else {
        cout << "File does not exist!" << endl;
    }
}

void read_file_and_find_max_num() {
    int max_num = INT_MIN; // böyle yapmazsan ve 0 dersen negatif sayılarda sorun olur
    ifstream inputFile("inputFile.txt");
    if (inputFile.is_open()) {
        int x;
        // this controls  if reading file is true or not so until the end of the file it keeps going
        while (inputFile >> x) {
            if (x > max_num) {
                max_num = x;
            }

        }
    cout << "max:" << max_num << endl;
    }
}

void read_file_and_create_output_file() {

    ofstream outputFile("outputFile.txt");
    ifstream inputFile("inputFile.txt");
    if (inputFile.is_open()) {
        int x;
        while (inputFile >> x) {
            outputFile << x * x << endl; // sırayla inputtaki syaıların karesini alıp outputa koy
        }
    }
    else {
        cout << "File does not exist!" << endl;
    }
    inputFile.close();
    outputFile.close();
}
int main() {
    //take_3_and_sum();
    // take_until_0_and_sum();
    //read_file_and_sum_numbers();
    // read_file_and_find_max_num();
    read_file_and_create_output_file();
}
