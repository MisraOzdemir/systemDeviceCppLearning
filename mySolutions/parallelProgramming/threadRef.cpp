//
// Created by Mısra Özdemir on 24.05.2026.
//

#include <iostream>
#include <thread>

void func (int& result) {
    result = 42;
}

int main () {
    int result = 3;
    std::thread t1(func, std::ref(result)); // func fonksiyonunu çalıştır, result'ı referans olarak geçir
    t1.join();
    std::cout << result << std::endl;
}