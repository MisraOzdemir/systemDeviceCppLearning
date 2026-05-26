//
// Created by Mısra Özdemir on 1.05.2026.
//

#include <iostream>
#include <ostream>
using namespace std;

class Account {
    // class  → default: private
    // struct → default: public
    int balance;

public:
    Account() {
        balance = 0; // constructor — başlangıçta 0
    }

    // const : do not change the param in the method
    void insert_money(const int amount) {
        balance += amount;
    }

    void take_money(const int amount) {
        if (amount > balance) cout << "bakiye yetersiz" << endl;
        else {
            balance -= amount;
        }

    }

    // const : do not change any variable in the class just show something static
    void show_balance() const {
        cout << balance << endl;
    }
};

int main() {
    Account h;
    h.insert_money(100);
    h.insert_money(80);
    h.show_balance();
}
