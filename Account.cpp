#include "Account.h"
#include <iostream>

double Account::get_balance() {
    return balance;
}

void Account::set_balance(double bal) {
    balance = bal;
}

Account::Account(int d, double b, int a, std::string n)
    : balance{b}, age{a}, name{n}, x{new int} {
    *x = d;
    std::cout << "default";
}
Account::Account(const Account &a) : Account::Account{*(a.x), a.balance,a.age, a.name}{}
Account::~Account(){
    delete x;
}

