#ifndef RAHUNOK_VKLADNYKA_H
#define RAHUNOK_VKLADNYKA_H

#include "Rahunok.h"
#include "Vkladnyk.h"
#include <string>

class RahunokVkladnyka : public Rahunok, public Vkladnyk {
private:
    double maxDailyLimit;
    double minBalanceLimit;
    double withdrawnToday;
    std::string password;

public:
    RahunokVkladnyka(long long accNum, const std::string& name, const std::string& passport,
                     double initBalance, double dailyLimit, double minBalance,
                     const std::string& initPassword = "default_pass");

    void displayFullDetails() const;
    bool changePassword(const std::string& oldPass, const std::string& newPass);
    void deposit(double amount);
    bool withdraw(double amount, const std::string& enteredPassword);
};

#endif