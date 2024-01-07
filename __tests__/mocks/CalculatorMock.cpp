#pragma once

#include <gmock/gmock.h>
#include "src/Calculator.hpp"


class CalculatorMock: public Calculator {

public:
    MOCK_METHOD(long double, add, (const long double &a, const long double &b));
    MOCK_METHOD(long double, sub, (const long double &a, const long double &b));
    MOCK_METHOD(long double, mul, (const long double &a, const long double &b));
    MOCK_METHOD(long double, div, (const long double &a, const long double &b));
    MOCK_METHOD(long double, getLastResult, ());
    MOCK_METHOD(void, resetLastResult, ());
};