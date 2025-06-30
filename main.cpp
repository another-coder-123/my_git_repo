#include "calculator.h"
#include <iostream>

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
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    result = my_calc.calculate(10, '*', 6);
    std::cout << "10*6 - Result is: " << result << std::endl;

    result = my_calc.calculate(10, '/', 5);
    std::cout << "10/5 - Result is: " << result << std::endl;

    try
    {
        result = my_calc.calculate(2, '/', 0);
        std::cout << "2/0 - Result is: " << result << std::endl;
    }
    catch (const ZeroDivisionException& e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    try
    {
        result = my_calc.calculate(2, '^', 3);
        std::cout << "2^3 - Result is: " << result << std::endl;
    }
    catch (const UnknowmOperatorException& e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    return 0;
}