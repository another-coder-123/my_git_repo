#include "calculator.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

const char* ResultOutOfLimitException::what() const noexcept
{
    return error_msg.c_str();
}

const char* ZeroDivisionException::what() const noexcept
{
    return error_msg.c_str();
}

const char* UnknowmOperatorException::what() const noexcept
{
    return error_msg.c_str();
}

double Calculator::add(double num1, double num2)
{
    if (num1 > (std::numeric_limits<double>::max() - num2))
    {
        throw ResultOutOfLimitException("The result is bigger than double max limit");
    }
    return num1 + num2;
}

double Calculator::subtract(double num1, double num2)
{
    if (num1 < (std::numeric_limits<double>::min() + num2))
    {
        throw ResultOutOfLimitException("The result is smaller than double min limit");
    }
    return num1 - num2;
}

double Calculator::multiply(double num1, double num2)
{
    if (num1 > (std::numeric_limits<double>::max() / num2))
    {
        throw ResultOutOfLimitException("The result is bigger than double max limit");
    }
    return num1 * num2;
}

double Calculator::divide(double num1, double num2)
{
    if (num2 == 0)
    {
        throw ZeroDivisionException("Zero devision is not allowed");
    }
    if (num1 < (std::numeric_limits<double>::min() * num2))
    {
        throw ResultOutOfLimitException("The result is smaller than double min limit");
    }
    return num1 / num2;
}

double Calculator::calculate(double num1, char exp_operator, double num2)
{
    switch (exp_operator)
    {
    case '+':
        return add(num1, num2);
        break;
    case '-':
        return subtract(num1, num2);
        break;
    case '*':
        return multiply(num1, num2);
        break;
    case '/':
        return divide(num1, num2);
        break;
    default:
        throw UnknowmOperatorException("The used operator is not defined!");
    }
}
