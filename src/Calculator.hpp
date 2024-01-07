#pragma once

#include <optional>
#include "src/CalculatorInterface.hpp"

class Calculator: public CalculatorIntreface {
private:
    std::optional<long double> lastResult = std::nullopt;
    long double _saveLastResult(long double result);
public:
    Calculator() = default;
    virtual ~Calculator() = default;

    long double add(const long double &a, const long double &b) override;
    long double sub(const long double &a, const long double &b) override;
    long double mul(const long double &a, const long double &b) override;
    long double div(const long double &a, const long double &b) override;

    long double getLastResult() const override;
    void resetLastResult() override;
};