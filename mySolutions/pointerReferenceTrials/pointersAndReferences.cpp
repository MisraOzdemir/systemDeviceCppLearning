//
// Created by Mısra Özdemir on 26.03.2026.
//

#include "pointersAndReferences.h"
#include <string>
#include <iostream>
using namespace std;

void tryReferences() {
    string food = "Pizza";
    string &meal = food;

    // updating through references
    meal = "burger"; // changes both meal and food

    std::cout << "food: " + food << std::endl;
    std::cout << "meal: " + meal << std::endl;

    cout << &food << std::endl; // prints 0x16d38f0a8
}

void tryPointers() {
    string food = "Pizza"; // if you put const you cannot change it later
    string* ptr = &food;

    cout << "food: " << food << std::endl; // prints Pizza
    cout << "&food: "<< &food << std::endl; // prints 0x16d38f0a8
    cout << "ptr: " << ptr << std::endl; // ptr: 0x16ef230a8
    // dereferencing
    cout << "*ptr: " + *ptr << std::endl; // *ptr: Pizza

    // change the value of the pointer
    *ptr = "burger";
    cout << "changed food: " << food << std::endl; // prints burger
    cout << "changed &food: "<< &food << std::endl; // prints 0x16ef230a8
    cout << "changed ptr: " << ptr << std::endl; // ptr: 0x16ef230a8
    // dereferencing
    cout << "changed *ptr: " + *ptr << std::endl; // *ptr: burger

}

int main() {
    tryReferences();
    std::cout << "pointers method" << std::endl;
    tryPointers();
}
