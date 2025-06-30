#ifndef CALCULATOR_H_FILE
#define CALCULATOR_H_FILE
#endif
#include <string>

class ResultOutOfLimitException : public std::exception
{
  private:
    std::string error_msg;

  public:
    ResultOutOfLimitException(const std::string& error) : error_msg(error)
    {
    }

    const char* what() const noexcept;
};

class ZeroDivisionException : public std::exception
{
  private:
    std::string error_msg;

  public:
    ZeroDivisionException(const std::string& error) : error_msg(error)
    {
    }

    const char* what() const noexcept;
};

class UnknowmOperatorException : public std::exception
{
  private:
    std::string error_msg;

  public:
    UnknowmOperatorException(const std::string& error) : error_msg(error)
    {
    }

    const char* what() const noexcept;
};

class Calculator
{
  public:
    // Calculates the result of the given expression
    double calculate(double num1, char exp_operator, double num2);

  private:
    // Adds up two double values
    double add(double num1, double num2);

    // Subtracts second value from first value
    double subtract(double num1, double num2);

    // Multiplies two double values
    double multiply(double num1, double num2);

    // Divides first value by second value
    double divide(double num1, double num2);
};