#include "RahunokVkladnyka.h"
#include <iostream>

RahunokVkladnyka::RahunokVkladnyka(long long accNum, const std::string& name, const std::string& passport,
                                   double initBalance, double dailyLimit, double minBalance,
                                   const std::string& initPassword)
    : Rahunok(accNum, initBalance, 0.0), 
      Vkladnyk(name, passport),
      maxDailyLimit(dailyLimit), 
      minBalanceLimit(minBalance), 
      withdrawnToday(0.0), 
      password(initPassword) {}

void RahunokVkladnyka::displayFullDetails() const {
    std::cout << "\n=========================================\n";
    displayVkladnykInfo();
    displayAccountInfo();
    std::cout << "Добовий ліміт зняття: " << maxDailyLimit << " грн\n"
              << "Мінімальний залишок: " << minBalanceLimit << " грн\n"
              << "Знято за сьогодні: " << withdrawnToday << " грн\n"
              << "=========================================\n";
}

bool RahunokVkladnyka::changePassword(const std::string& oldPass, const std::string& newPass) {
    if (oldPass == password) {
        password = newPass;
        std::cout << "[УСПІХ] Пароль успішно змінено.\n";
        return true;
    }
    std::cout << "[ПОМИЛКА БЕЗПЕКИ] Невірний старий пароль!\n";
    return false;
}

void RahunokVkladnyka::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        std::cout << "[ПОПОВНЕННЯ] Поповнено на " << amount << " грн. Поточний баланс: " << balance << " грн\n";
    } else {
        std::cout << "[ПОМИЛКА] Сума поповнення має бути більшою за 0!\n";
    }
}

bool RahunokVkladnyka::withdraw(double amount, const std::string& enteredPassword) {
    if (enteredPassword != password) {
        std::cout << "[ПОМИЛКА БЕЗПЕКИ] Відхилено: Невірно введено пароль!\n";
        return false;
    }

    if (amount <= 0) {
        std::cout << "[ПОМИЛКА] Сума зняття має бути додатною!\n";
        return false;
    }

    if (withdrawnToday + amount > maxDailyLimit) {
        std::cout << "[ВІДХИЛЕНО] Превищено добовий ліміт зняття! Доступний залишок ліміту на добу: "
                  << (maxDailyLimit - withdrawnToday) << " грн\n";
        return false;
    }

    if (balance - amount < minBalanceLimit) {
        std::cout << "[ВІДХИЛЕНО] Недостатньо коштів з урахуванням вимоги мінімального залишку ("
                  << minBalanceLimit << " грн)!\n";
        return false;
    }

    balance -= amount;
    withdrawnToday += amount;
    std::cout << "[УСПІХ] Знято " << amount << " грн. Новий баланс: " << balance << " грн\n";
    return true;
}