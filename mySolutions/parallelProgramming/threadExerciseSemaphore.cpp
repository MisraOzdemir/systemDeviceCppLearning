//
// Created by Mısra Özdemir on 13.05.2026.
//

/**
 * synchronize threads such that each set of 3 chars,
 * there is 1 A and 2 B's, and the output is in the form of ABBABBABB... (e.g. ABBAABBAABBA...)
 * 2 thread yazıcaksın TA sadece A döner, TB sadece B döner,
 * ve outputta her 3 karakterde 1 A ve 2 B olacak şekilde senkronize edeceksin.
 *
 * mutex kullanamazsın çünkü onda aynı thread lock ve unlock
 * yapıyor ama biz burda 2 ayrı thread birbirini uyarsın istiyoruz,
 * SEMAPHORE KULLANICAZ O YÜZDEN
 */

// semaphore TA nın 1 kez TB nin 2 kez olmasını kontrol eden sayaç aslında

#include <iostream>
#include <semaphore>
#include <thread>
#include <unistd.h> // sleep için

std::counting_semaphore<10> sa{1}, sb{2}, me{1} ;

int n; // 3*n1 karakter yazılacak 3 olunca dursun diye var

static void TA (int);
static void TB (int);

// 3 semaphore lazım 1i TA kaç kez çalıştı, 1i TB kaç kez çalıştı, 1i de sıranın kimde olduğunu tutacak
int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf (stderr, "Syntax: %s num_threads\n", argv[0]);
        return 1;
    }
    // sonsuza kadar çalışmasını engellemek için var kodun asıl logici ile alakası yok
    const int n1 = atoi(argv[1]); // terminalden gelen "5" → 5 sayısına çevir
    int n2 = 2 * n1;   // TA n1 kez ise TB n1*2 kez çalışacak

    std::thread ta (TA, n1);
    std::thread tb (TB, n2);

    ta.join();
    tb.join();

    return 0;
}

static void TA (int nc) {
    for (int i = 0; i < nc; i++) {
        sleep (rand() % 2) ; // wait for a random time
        sa.acquire(); // TA'nın çalışması için sa'nın 1 olması lazım
        me.acquire(); // sıranın TA'da olduğunu gösterir
        std::cout << "A";
        n++;
        if (n >= 3) {
            std::cout << std::endl;
            n=0;
            sa.release();
            sb.release();
            sb.release();
        }
        me.release();

    }
}


