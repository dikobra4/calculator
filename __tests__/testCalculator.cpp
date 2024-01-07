#include <gtest/gtest.h>
#include "src/Calculator.hpp"
#include "src/exceptions.hpp"


// Max value calculation error when comparing floating point numbers
double MAX_DELTA = 0.000001;

/**
 * Test suite for add Calculator::add
*/
class CalculatorAddTest
    : public testing::TestWithParam<std::tuple<long double, long double, long double>> {};
INSTANTIATE_TEST_SUITE_P(
    Default, CalculatorAddTest,
    testing::Values(
        std::make_tuple(1, 2, 3),
        std::make_tuple(3, 4, 7),
        std::make_tuple(5, -5, 0),
        std::make_tuple(-1, -2, -3),
        std::make_tuple(0, 0, 0),
        std::make_tuple(0, 5, 5),
        std::make_tuple(0, -5, -5),
        std::make_tuple(-5, 0, -5),
        std::make_tuple(5, 0, 5),
        std::make_tuple(5, 5, 10),
        std::make_tuple(-5.5, -5.6, -11.1),
        std::make_tuple(5.5, 5.6, 11.1),
        std::make_tuple(5.5, 5.5, 11)
    )
);
TEST_P(CalculatorAddTest, CalculatorAddsNumbers) {
    Calculator calc;
    long double a, b, expected;
    std::tie(a, b, expected) = GetParam();
    EXPECT_NEAR(calc.add(a, b), expected, MAX_DELTA);
}

/**
 * Test suite for substract Calculator::sub
*/ 
class CalculatorSubTest 
    : public testing::TestWithParam<std::tuple<long double, long double, long double>> {};
INSTANTIATE_TEST_SUITE_P(Default, CalculatorSubTest, testing::Values(
    std::make_tuple(3, 2, 1),
    std::make_tuple(-3, -2, -1),
    std::make_tuple(5, 0, 5),
    std::make_tuple(-5, 0, -5),
    std::make_tuple(5, -1, 6),
    std::make_tuple(-5, 1, -6),
    std::make_tuple(5, 5, 0),
    std::make_tuple(0, 5, -5),
    std::make_tuple(0, -5, 5),
    std::make_tuple(0, 0, 0),
    std::make_tuple(-5.5, -5.6, 0.1),
    std::make_tuple(5.5, 5.6, -0.1),
    std::make_tuple(5.5, 5.5, 0)
));
TEST_P(CalculatorSubTest, SubtractsNumbers) {
    Calculator calc;
    long double a, b, expected;
    std::tie(a, b, expected) = GetParam();
    EXPECT_NEAR(calc.sub(a, b), expected, MAX_DELTA);
}


/**
 * Test suite for multiply Calculator::mul
*/
class CalculatorMulTest 
    : public testing::TestWithParam<std::tuple<long double, long double, long double>> {};
INSTANTIATE_TEST_SUITE_P(Default, CalculatorMulTest, testing::Values(
    std::make_tuple(3, 2, 6),
    std::make_tuple(-3, -2, 6),
    std::make_tuple(5, 1, 5),
    std::make_tuple(-5, 1, -5),
    std::make_tuple(5, -1, -5),
    std::make_tuple(5, 0, 0),
    std::make_tuple(0, 5, 0),
    std::make_tuple(0, 0, 0),
    std::make_tuple(0, -5, 0),
    std::make_tuple(5.5, -5.6, -30.8),
    std::make_tuple(5.5, 5.6, 30.8),
    std::make_tuple(5.5, 5.5, 30.25)
));
TEST_P(CalculatorMulTest, MultipliesNumbers) {
    Calculator calc;
    long double a, b, expected;
    std::tie(a, b, expected) = GetParam();
    EXPECT_NEAR(calc.mul(a, b), expected, MAX_DELTA);
}

/**
 * Test suite for divide Calculator::div
*/
class CalculatorDivTest 
    : public testing::TestWithParam<std::tuple<long double, long double, long double>> {};
INSTANTIATE_TEST_SUITE_P(Default, CalculatorDivTest, testing::Values(
    std::make_tuple(4, 2, 2),
    std::make_tuple(-6, -3, 2),
    std::make_tuple(5, 0, 0),
    std::make_tuple(0, 5, 0),
    std::make_tuple(0, 0, 0),
    std::make_tuple(1.5, 0.5, 3),
    std::make_tuple(-1.5, 0.5, -3),
    std::make_tuple(1.5, -0.6, -2.5),
    std::make_tuple(-1.5, -0.6, 2.5)
));
TEST_P(CalculatorDivTest, DividesNumbers) {
    Calculator calc;
    long double a, b, expected;
    std::tie(a, b, expected) = GetParam();
    if (b == 0) {
        EXPECT_THROW(calc.div(a, b), DivizionByZeroException);
    } else{
        EXPECT_NEAR(calc.div(a, b), expected, MAX_DELTA);
    }
}


/**
 * Test suite for working with last result (save, get, reset)
*/
class CalculatorLastResultTest: public testing::Test {
protected:
    Calculator calc;

    void SetUp() override {
        calc.resetLastResult();
    }

    void TearDown() override {
        calc.resetLastResult();
    }
};
TEST_F(CalculatorLastResultTest, TestLastResultIsSavedSum) {
    calc.add(1, 2);
    calc.add(5, 6);
    EXPECT_EQ(calc.getLastResult(), 11);
}
TEST_F(CalculatorLastResultTest, TestLastResultIsSavedSub) {
    calc.sub(1, 2);
    calc.sub(5, 6);
    EXPECT_EQ(calc.getLastResult(), -1);
}
TEST_F(CalculatorLastResultTest, TestLastResultIsSavedMul) {
    calc.mul(1, 2);
    calc.mul(5, 6);
    EXPECT_EQ(calc.getLastResult(), 30);
}
TEST_F(CalculatorLastResultTest, TestLastResultIsSavedDiv) {
    calc.div(2, 1);
    calc.div(4, 2);
    EXPECT_EQ(calc.getLastResult(), 2);
}
TEST_F(CalculatorLastResultTest, TestSavedDoubleLastResult) {
    calc.add(1, 2);
    calc.add(5.5, 6);
    EXPECT_EQ(calc.getLastResult(), 11.5);
}
TEST_F(CalculatorLastResultTest, TestLastResultIsCleared) {
    calc.mul(1, 2);
    calc.resetLastResult();
    EXPECT_THROW(calc.getLastResult(), NoLastResultException);
}
