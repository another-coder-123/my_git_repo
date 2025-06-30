#include <string>
#ifndef CALCULATOR_H_FILE
#define CALCULATOR_H_FILE
#endif

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