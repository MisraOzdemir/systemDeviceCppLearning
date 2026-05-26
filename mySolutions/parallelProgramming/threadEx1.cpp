//
// Created by Mısra Özdemir on 24.05.2026.
//

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

int counter = 0;
std::mutex m;

// increment without mutex - her thread tek seferde arttırdığından sonuç 9877 çıkıuo mesela
void increment() {
    for (int i = 0; i < 1000; i++) {
        counter++; // kritik bölüm, birden fazla thread erişebilir ve sonuç yanlış çıkabilir
    }
}

// increment with mutext - her thread tek seferde arttırdığından sonuç doğru çıkar
void incrementWithMutex() {
    for (int i = 0; i < 1000; i++) {
        std::lock_guard<std::mutex> lock(m); // lock_guard ile mutex'i kilitle ve scope dışına çıkınca otomatik aç
        counter++; // kritik bölüm, sadece bir thread erişebilir
    }
}
int main() {
    std::vector<std::thread> pool ;

    for (int i = 1; i <= 10; i++) {
        pool.emplace_back(incrementWithMutex);
    }

    for (auto& t : pool) {
        t.join();
    }

    std::cout << "Counter: " << counter << std::endl;

}
