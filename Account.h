#include <string>
#include <iostream>
#pragma once

class Account{

    double balance;
    int age;
    std::string name;
    int *x;
public:
    explicit Account(int d, double b = 0, int a = 0, std::string n = "None");
    void getX(){
        std::cout << "Memory address of x: " << x << std::endl << "Value of *x: " << *x << std::endl;
    }
    Account(const Account &a);
    ~Account();
    void set_balance(double bal);
    double get_balance();
    void print(){
        std::cout << "Balance: " << balance << " Age: " << age << " Name: " << name;
    }

};