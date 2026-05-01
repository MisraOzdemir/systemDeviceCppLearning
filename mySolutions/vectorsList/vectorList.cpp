//
// Created by Mısra Özdemir on 1.05.2026.
//

#include "vectorList.h"

#include <iostream>
#include <vector>
using namespace std;

// VECTOR
void take_num_until_zero() {
    vector<int> numList;
    int num;

    while (true) {
        cout << "insert number" << endl;
        cin >> num;
        if (num != 0) {
            numList.push_back(num);
        }
        else
            break;
    }
    for (int i: numList) {
        cout << i << endl;
    }

}

int main() {
    take_num_until_zero();
}