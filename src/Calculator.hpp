#pragma once

#include <optional>
#include "src/CalculatorInterface.hpp"

class Calculator: public CalculatorIntreface {
private:
    std::optional<double> lastResult = std::nullopt;
    double _saveLastResult(double result);
public:
    Calculator() = default;
    virtual ~Calculator() = default;

    double add(const double &a, const double &b) override;
    double sub(const double &a, const double &b) override;
    double mul(const double &a, const double &b) override;
    double div(const double &a, const double &b) override;

    double getLastResult() const override;
    void resetLastResult() override;
};