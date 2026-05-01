//
// Created by Mısra Özdemir on 26.03.2026.
//

#ifndef LABORATORY_LAB1EX1_H
#define LABORATORY_LAB1EX1_H

#include <iostream>
#include <cstdlib>

// question says dynamically allocate an array so we are using pointers
// os bize veriyi değil verinin bellekte başladığı adresi veriyor.
// malloc ve new her zaman adres döndürür
// adresleri saklayabilmek için de pointer kullanmamız gerekiyor
double *readArray (int);
void sortArray (double *, int);
void displayArray (double *, int);

class lab1ex1 {
};


#endif //LABORATORY_LAB1EX1_H