#pragma once

#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <spdlog/spdlog.h>

#include "src/Calculator.hpp"
#include "src/exceptions.hpp"
#include "cli/cliMessages.hpp"

/**
 * Handler for CLI commands
 * Parse and process commands and executes them into Calculator object.
 * 
 * Parameters:
 *      @param calc_obj Calculator object
 *      @param cmd full CLI user input as string
 * 
 * Throws:
 *      @throws IncorrectCommandException        if command doesn't exist
 *      @throws IncorrectCommandFormatException  if command has invalid number of parametres
 *      @throws DivizionByZeroException          if user tries to devide by 0
 *      @throws NoLastResultException            if there is no last result when user trys to get it
 * 
 * Usage:
 *      @code
 *      std::string cmd = "add 1 2"; // Here should be an user input
 *      Calculator calc;
 *      CliCommandHandler handler(calc, cmd);
 *      double result = handler.getResult();
 *      @endcode
*/
class CliCommandHandler {
private:
    Calculator &calc;

    // Parsed command arguments
    std::string _command;
    double _num1;
    double _num2;
    
    // Result arguments
    double _result;
    std::string _resultString;
    std::string _error;
    
    // Available commands
    std::vector<std::string> avaliableOperations = {
        "add", "sub", "mul", "div", "lastresult", "resetlastresult"};
    std::vector<std::string> lastResultCommands = {
        "lastresult", "resetlastresult"};
    std::vector<std::string> serviceCommands = {
        "help", "exit"};
    
    /**
     * Parses command and records value into _command
     * 
     * Parameters:
     *      @param tokens vector with string command words
    */
    void _parseLastResultCommand(std::vector<std::string> &tokens);
    
    /**
     * Parses command and records value into _command, _num1 and _num2
     * 
     * Parameters:
     *      @param tokens vector with string command words
    */
    void _parseOperationCommand(std::vector<std::string> &tokens);

    /**
     * Performs operation based on values in _command, _num1 and _num2
     * 
     * Throws:
     *      @param IncorrectCommandException    if command doesn't exist or nothing to perform 
     *                                          (like 'help' or 'exit')
    */
    void _performOperation();

public:
    CliCommandHandler(Calculator &calc_obj, const std::string &cmd);
    virtual ~CliCommandHandler() = default;
    
    // Getters
    double getResult();
    std::string getResultString();
    std::string getError();
    
    // Checkers
    bool isError();
    bool isResultString();
    bool isExit();
};