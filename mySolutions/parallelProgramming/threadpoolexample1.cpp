//
// Created by Mısra Özdemir on 24.05.2026.
//

#include <iostream>
#include <thread>
#include <vector>
int main() {
    std::vector<std::thread> pool;
    pool.reserve(5);
for (int i = 0; i<5; i++) {
        pool.emplace_back([i] {std::cout << "thread" << i << "\n"; });
    }

    for(auto& t : pool)
        t.join();
    return 0;
}