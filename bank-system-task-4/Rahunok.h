#ifndef RAHUNOK_H
#define RAHUNOK_H

#include <iostream>

class Rahunok {
protected:
    long long accountNumber;
    double balance;
    double interestRate;

public:
    Rahunok(long long accNum = 0, double initBalance = 0.0, double rate = 0.0);
    virtual ~Rahunok() = default;

    void displayAccountInfo() const;
    void setInterestRate(double rate);
    void applyInterest();
    
    double getBalance() const;
};

#endif