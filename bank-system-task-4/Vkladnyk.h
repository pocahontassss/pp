#ifndef VKLADNYK_H
#define VKLADNYK_H

#include <string>

class Vkladnyk {
protected:
    std::string fullName;
    std::string passportSeriesNumber;

public:
    Vkladnyk(const std::string& name = "", const std::string& passport = "");
    virtual ~Vkladnyk() = default;

    void displayVkladnykInfo() const;
};

#endif