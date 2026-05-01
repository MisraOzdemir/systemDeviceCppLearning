//
// Created by Mısra Özdemir on 30.04.2026.
//

#include "./structTrials.h"

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Student {
    int id;
    string name;
    string surname;
    double gpa;
};

void match_id_with_gpa(Student stList[], int size, int studentId) {
    for (int i = 0; i < size; i++) {
        if (stList[i].id == studentId) {
            cout << "Merhaba " << stList[i].name
                 << "! GPA'in: " << stList[i].gpa << endl;
            return;
        }
    }
    cout << "Ogrenci bulunamadi!" << endl;
}

int main() {
    Student stList[3];
    ifstream f("students.txt");
    if (!f.is_open()) { cout << "Dosya acilamadi!" << endl; return 1; }

    // student txt deki verileri al tek tek listedeki elemanlara doldur
    for (int i = 0; i < 3; i++) {
        f >> stList[i].id >> stList[i].name >> stList[i].surname >> stList[i].gpa;
    }
    f.close();

    // kullanıcıdan id al
    int studentId;
    cout << "give your student id: " << endl;
    cin >> studentId;

    // match functionı çağır
    match_id_with_gpa(stList, 3, studentId);
}