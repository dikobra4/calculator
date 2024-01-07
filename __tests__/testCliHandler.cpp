#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "mocks/CalculatorMock.cpp"
#include "cli/CliCommandHandler.hpp"
#include "cli/cliMessages.hpp"
#include "src/exceptions.hpp"

/**
 * Test suite for CliCommandHandler
 * Parse and process commands and executes them into Calculator object.
 * 
 * CalculatorMock is used for testing. It`s a mock object using gmock.
*/
class CliCommandHandlerTest : public ::testing::Test {
protected:
    CalculatorMock calc;
};
// Check help message recorded into result string
TEST_F(CliCommandHandlerTest, TestHelpMessage) {
    CliCommandHandler handler(calc, "help");
    EXPECT_EQ(handler.getResultString(), HELP_MESSAGE);
}
// Check exit command recognized and recorded as _command. isExit() returns true
TEST_F(CliCommandHandlerTest, TestExit) {
    CliCommandHandler handler(calc, "exit");
    EXPECT_EQ(handler.isExit(), true);
}
// Check Calculator:add command recognized and called with correct parameters
TEST_F(CliCommandHandlerTest, TestAdd) {
    EXPECT_CALL(calc, add(1, 2)).Times(1);
    CliCommandHandler handler(calc, "add 1 2");
}
// Check Calculator:sub command recognized and called with correct parameters
TEST_F(CliCommandHandlerTest, TestSub) {
    EXPECT_CALL(calc, sub(1, 2)).Times(1);
    CliCommandHandler handler(calc, "sub 1 2");
}
// Check Calculator:mul command recognized and called with correct parameters
TEST_F(CliCommandHandlerTest, TestMul) {
    EXPECT_CALL(calc, mul(1, 2)).Times(1);
    CliCommandHandler handler(calc, "mul 1 2");
}
// Check Calculator:div command recognized and called with correct parameters
TEST_F(CliCommandHandlerTest, TestDiv) {
    EXPECT_CALL(calc, div(1, 2)).Times(1);
    CliCommandHandler handler(calc, "div 1 2");
}
// Check Calculator:resetLastResult command recognized and called
TEST_F(CliCommandHandlerTest, TestResetLastResult) {
    EXPECT_CALL(calc, resetLastResult()).Times(1);
    CliCommandHandler handler(calc, "resetlastresult");
}
// Check incorrect command throws correct exception
TEST_F(CliCommandHandlerTest, TestBadCommandError) {
    EXPECT_THROW(CliCommandHandler handler(calc, "error"), IncorrectCommandException);
}
// Check correct command with incorrect params count throws correct exception
TEST_F(CliCommandHandlerTest, TestBadCommandFormatError) {
    EXPECT_THROW(CliCommandHandler handler(calc, "add 2"), IncorrectCommandFormatException);
}