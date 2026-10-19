#include "Vkladnyk.h"
#include <iostream>

Vkladnyk::Vkladnyk(const std::string& name, const std::string& passport)
    : fullName(name), passportSeriesNumber(passport) {}

void Vkladnyk::displayVkladnykInfo() const {
    std::cout << "--- Інформація про вкладника ---\n"
              << "ПІБ: " << fullName << "\n"
              << "Паспортні дані: " << passportSeriesNumber << "\n";
}