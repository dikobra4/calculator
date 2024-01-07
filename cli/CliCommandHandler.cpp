#include "cli/CliCommandHandler.hpp"

CliCommandHandler::CliCommandHandler(Calculator &calc_obj, const std::string &cmd)
        : calc(calc_obj) {
    std::istringstream iss(cmd);
    std::vector<std::string> tokens{
        std::istream_iterator<std::string>{iss}, 
        std::istream_iterator<std::string>{} 
    };
    
    spdlog::debug("Try command: {}", cmd);
    if (tokens.empty()) throw IncorrectCommandException();

    if (find(serviceCommands.begin(), 
             serviceCommands.end(), 
             tokens[0]) != serviceCommands.end()) {
        _command = tokens[0];
        spdlog::debug("{} recognized as service command", _command);
    } else if (find(lastResultCommands.begin(), 
                    lastResultCommands.end(), 
                    tokens[0]) != lastResultCommands.end()) {
        _parseLastResultCommand(tokens);
        spdlog::debug("{} recognized as last result command", _command);
    } else if (find(avaliableOperations.begin(), 
             avaliableOperations.end(), 
             tokens[0]) != avaliableOperations.end()) {
        _parseOperationCommand(tokens);
    } else {
        throw IncorrectCommandException();
    }
    _performOperation();
}

void CliCommandHandler::_parseOperationCommand(std::vector<std::string> &tokens) {
    if (tokens.size() != 3) throw IncorrectCommandFormatException();
    _command = tokens[0];
    spdlog::debug("{} recognized as operation command", _command);
    try {
    _num1 = std::stod(tokens[1]);
    _num2 = std::stod(tokens[2]); 
    spdlog::debug("Arguments: {}, {}", _num1, _num2);
    } catch (const std::invalid_argument &e) {
        _error = "Invalid argument: " + std::string(e.what());
    } catch (const std::out_of_range &e) {
        _error = "Arguments are out of range: " + std::string(e.what());
    }
}

void CliCommandHandler::_parseLastResultCommand(std::vector<std::string> &tokens) {
    if (tokens.size() != 1) throw IncorrectCommandFormatException();
    _command = tokens[0];
}

void CliCommandHandler::_performOperation() {
    spdlog::debug("Perform operation: {}", _command);
    if (_command == "help") {
        _resultString = HELP_MESSAGE;
        spdlog::debug("Help message recorded");
    } else if (_command == "exit") {
        _resultString = EXIT_MESSAGE;
        spdlog::debug("Exit message recorded");
    } else if (_command == "add") {
        _result = calc.add(_num1, _num2);
    } else if (_command == "sub") {
        _result = calc.sub(_num1, _num2);
    } else if (_command == "mul") {
        _result = calc.mul(_num1, _num2);
    } else if (_command == "div") {
        try {
            _result = calc.div(_num1, _num2);
        } catch (const DivizionByZeroException &e) {
            _error = e.what();
        }
    } else if (_command == "lastresult") {
        try {
            _result = calc.getLastResult();
        } catch (const NoLastResultException &e) {
            _error = e.what();
        }
    } else if (_command == "resetlastresult") {
        calc.resetLastResult();
        _resultString = "Last result was reset";
    } else {
        throw IncorrectCommandException();
    }
}

double CliCommandHandler::getResult() {
    return _result;
}

std::string CliCommandHandler::getResultString() {
    return _resultString;
}

std::string CliCommandHandler::getError() {
    return _error;
}

bool CliCommandHandler::isResultString() {
    return _resultString != "";
}

bool CliCommandHandler::isError() {
    return _error != "";
}

bool CliCommandHandler::isExit() {
    return _command == "exit";
}
