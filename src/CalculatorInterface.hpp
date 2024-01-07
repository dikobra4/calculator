#pragma once

class CalculatorIntreface {
public:
    virtual ~CalculatorIntreface() = default;

    virtual double add(const double &a, const double &b) = 0;
    virtual double sub(const double &a, const double &b) = 0;
    virtual double mul(const double &a, const double &b) = 0;
    virtual double div(const double &a, const double &b) = 0;

    virtual double getLastResult() const = 0;
    virtual void resetLastResult() = 0;
};