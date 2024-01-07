#include "Calculator.hpp"
#include "exceptions.hpp"

double Calculator::add(const double &a, const double &b) {
    return _saveLastResult(a + b);
}

double Calculator::sub(const double &a, const double &b) {
    return _saveLastResult(a - b);
}

double Calculator::mul(const double &a, const double &b) {
    return _saveLastResult(a * b);
}

double Calculator::div(const double &a, const double &b) {
    if (b == 0) {
        throw DivizionByZeroException("You try to devide by 0");
    }
    return _saveLastResult(a / b);
}

double Calculator::_saveLastResult(double result) {
    lastResult = result;
    return result;
}

double Calculator::getLastResult() const {
    if (lastResult.has_value()){
        return *lastResult;
    } else {
        throw NoLastResultException();
    }
}

void Calculator::resetLastResult() {
    lastResult = std::nullopt;
}