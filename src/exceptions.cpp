#include "exceptions.hpp"

DivizionByZeroException::DivizionByZeroException(
    const std::string &msg
) : message(msg) {}

const char *DivizionByZeroException::what() const throw() {
    return message.c_str();
}

NoLastResultException::NoLastResultException(
    const std::string &msg
) : message(msg) {}

const char *NoLastResultException::what() const throw() {
    return message.c_str();
}

IncorrectCommandException::IncorrectCommandException(
    const std::string &msg
) : message(msg) {}

const char *IncorrectCommandException::what() const throw() {
    return message.c_str();
}

IncorrectCommandFormatException::IncorrectCommandFormatException(
    const std::string &msg
) : message(msg) {}

const char *IncorrectCommandFormatException::what() const throw() {
    return message.c_str();
}

IncorrectResultFormatException::IncorrectResultFormatException(
    const std::string &msg
) : message(msg) {}

const char *IncorrectResultFormatException::what() const throw() {
    return message.c_str();
}