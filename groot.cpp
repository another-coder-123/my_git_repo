#include <cmath>
#include <iostream>

int main()
{
    int num;
    double result;

    std::cout << "Enter a number: ";
    if (std::cin >> num)
    {
        result = std::sqrt(num);
        std::cout << "The square root of: " << num << " is: " << result << std::endl;
        return 0;
    } else {
        std::cin.clear();
        std::cout << "Number is invalid" << std::endl;
    
    }
}