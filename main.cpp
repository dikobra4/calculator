#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>
#include <spdlog/spdlog.h>

#include "src/Calculator.hpp"
#include "src/exceptions.hpp"
#include "cli/cliMessages.hpp"
#include "cli/CliCommandHandler.hpp"


int main() {
    spdlog::set_level(spdlog::level::debug);

    Calculator calc;

    std::vector<std::string> operationList = {"add", "sub", "mul", "div"};
    std::vector<std::string> lastResultCommands = {"lastresult", "resetlastresult"};

    std::cout << "Calculator v1.0. Type 'help' to see available commands" << std::endl;

    while (true)
    {
        std::string line;
        std::cout << "> ";
        std::getline(std::cin, line);
        try{
            CliCommandHandler handler(calc, line);
            if (handler.isExit()) {
                spdlog::debug("Exit command received");
                break;
            } else if (handler.isError()) {
                spdlog::debug("Found error string");
                std::cout << handler.getError() << std::endl;
            } else if (handler.isResultString()) {
                spdlog::debug("Found result string");
                std::cout << handler.getResultString() << std::endl;
            } else {
                spdlog::debug("Found result number");
                std::cout << handler.getResult() << std::endl;
            }
        } catch (const IncorrectCommandException &e) {
            std::cout << e.what() << std::endl;
            spdlog::info("Caught IncorrectCommandException");
        } catch (const IncorrectCommandFormatException &e) {
            std::cout << e.what() << std::endl;
            spdlog::info("Caught IncorrectCommandFormatException");
        } catch (const DivizionByZeroException &e) {
            std::cout << e.what() << std::endl;
            spdlog::info("Caught DivizionByZeroException");
        } catch (const NoLastResultException &e) {
            std::cout << e.what() << std::endl;
            spdlog::info("Caught NoLastResultException");
        }
    }
    return 0;
}