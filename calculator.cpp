#include "calculator.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

class ResultOutOfLimitException : public std::exception
{
  private:
    std::string m_error;

  public:
    ResultOutOfLimitException(const std::string& error) : m_error(error)
    {
    }
    const std::string& getError() const
    {
        return m_error;
    }
};

class ZeroDivisionException : public std::exception
{
  private:
    std::string m_error;

  public:
    ZeroDivisionException(const std::string& error) : m_error(error)
    {
    }
    const std::string& getError() const
    {
        return m_error;
    }
};

class UnknowmOperatorException : public std::exception
{
  private:
    std::string m_error;

  public:
    UnknowmOperatorException(const std::string& error) : m_error(error)
    {
    }
    const std::string& getError() const
    {
        return m_error;
    }
};

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

int main()
{
    double result;

    Calculator my_calc;
    result = my_calc.calculate(3, '+', 5);
    std::cout << "3+5 - Result is: " << result << std::endl;

    try
    {
        result = my_calc.calculate(std::numeric_limits<double>::min(), '-', 1);
        std::cout << "min-1 - Result is: " << result << std::endl;
    }
    catch (const ResultOutOfLimitException& e)
    {
        std::cerr << "Caught exception: " << e.getError() << std::endl;
    }

    result = my_calc.calculate(10, '*', 6);
    std::cout << "10*6  -Result is: " << result << std::endl;

    result = my_calc.calculate(10, '/', 5);
    std::cout << "10/5 - Result is: " << result << std::endl;

    try
    {
        result = my_calc.calculate(2, '/', 0);
        std::cout << "2/0 - Result is: " << result << std::endl;
    }
    catch (const ZeroDivisionException& e)
    {
        std::cerr << "Caught exception: " << e.getError() << std::endl;
    }

    try
    {
        result = my_calc.calculate(2, '^', 3);
        std::cout << "2^3 - Result is: " << result << std::endl;
    }
    catch (const UnknowmOperatorException& e)
    {
        std::cerr << "Caught exception: " << e.getError() << std::endl;
    }
}