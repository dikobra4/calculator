#pragma once

class CalculatorIntreface {
public:
    virtual ~CalculatorIntreface() = default;

    virtual long double add(const long double &a, const long double &b) = 0;
    virtual long double sub(const long double &a, const long double &b) = 0;
    virtual long double mul(const long double &a, const long double &b) = 0;
    virtual long double div(const long double &a, const long double &b) = 0;

    virtual long double getLastResult() const = 0;
    virtual void resetLastResult() = 0;
};