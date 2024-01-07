#pragma once

#include <exception>
#include <string>

class DivizionByZeroException : public std::exception {
private:
    std::string message;

public:
    DivizionByZeroException(const std::string &msg = "Divizion by zero exception.");

    virtual const char *what() const throw();
};

class NoLastResultException : public std::exception {
private:
    std::string message;
public:
    NoLastResultException(const std::string &msg = "There is no last result. "
                                                   "Looks like it was resetted or nothing was added yet.");
    virtual const char *what() const throw();
};

class IncorrectCommandException : public std::exception {
private:
    std::string message;
public:
    IncorrectCommandException(
        const std::string &msg = "Incorrect command! "
                                 "Use 'help' to see available commands.");
    virtual const char *what() const throw();
};

class IncorrectCommandFormatException : public std::exception {
private:
    std::string message;
public:
    IncorrectCommandFormatException(
        const std::string &msg = "Incorrect command format! "
                                 "Use 'help' to see available commands and example.");
    virtual const char *what() const throw();
};

class IncorrectResultFormatException : public std::exception {
private:
    std::string message;
public:
    IncorrectResultFormatException(
        const std::string &msg = "Internal error! Incorrect result format.");
    virtual const char *what() const throw();
};