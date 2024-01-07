#include "Calculator.hpp"
#include "exceptions.hpp"

long double Calculator::add(const long double &a, const long double &b) {
    return _saveLastResult(a + b);
}

long double Calculator::sub(const long double &a, const long double &b) {
    return _saveLastResult(a - b);
}

long double Calculator::mul(const long double &a, const long double &b) {
    return _saveLastResult(a * b);
}

long double Calculator::div(const long double &a, const long double &b) {
    if (b == 0) {
        throw DivizionByZeroException("You try to devide by 0");
    }
    return _saveLastResult(a / b);
}

long double Calculator::_saveLastResult(long double result) {
    lastResult = result;
    return result;
}

long double Calculator::getLastResult() const {
    if (lastResult.has_value()){
        return *lastResult;
    } else {
        throw NoLastResultException();
    }
}

void Calculator::resetLastResult() {
    lastResult = std::nullopt;
}