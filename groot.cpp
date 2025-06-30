#include <cmath>
#include <iostream>

int main()
{
    int num;
    double result;
    std::cout << "Enter a number: ";
    std::cin >> num;
    result = std::sqrt(num);
    std::cout << "The square root of: " << num << " is: " << result << "\n";
    return 0;
}