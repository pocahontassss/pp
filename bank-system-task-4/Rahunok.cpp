#include "Rahunok.h"
#include <iostream>
#include <iomanip>

Rahunok::Rahunok(long long accNum, double initBalance, double rate)
    : accountNumber(accNum), balance(initBalance), interestRate(rate) {}

void Rahunok::displayAccountInfo() const {
    std::cout << "--- Інформація про рахунок ---\n"
              << "Номер рахунку: " << accountNumber << "\n"
              << "Баланс: " << std::fixed << std::setprecision(2) << balance << " грн\n"
              << "Відсоткова ставка: " << interestRate << "%\n";
}

void Rahunok::setInterestRate(double rate) {
    if (rate >= 0) {
        interestRate = rate;
        std::cout << "Встановлено нову відсоткову ставку: " << interestRate << "%\n";
    } else {
        std::cout << "Помилка: відсоткова ставка не може бути від'ємною!\n";
    }
}

void Rahunok::applyInterest() {
    double addedAmount = balance * (interestRate / 100.0);
    balance += addedAmount;
    std::cout << "Нараховано відсотки: +" << addedAmount << " грн. Новий баланс: " << balance << " грн\n";
}

double Rahunok::getBalance() const {
    return balance;
}