#pragma once

#include <gmock/gmock.h>
#include "src/Calculator.hpp"


class CalculatorMock: public Calculator {

public:
    MOCK_METHOD(double, add, (const double &a, const double &b));
    MOCK_METHOD(double, sub, (const double &a, const double &b));
    MOCK_METHOD(double, mul, (const double &a, const double &b));
    MOCK_METHOD(double, div, (const double &a, const double &b));
    MOCK_METHOD(double, getLastResult, ());
    MOCK_METHOD(void, resetLastResult, ());
};