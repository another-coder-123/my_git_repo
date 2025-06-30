#include <iostream>

int main()
{
    int rows = 11;
    int columns = 11;

    for (int j{1}; j <= rows; ++j)
    {
        std::cout << '\n';
        for (int i{1}; i <= columns; ++i)
            std::cout << i * j << ' ';
    }

    std::cout << "\nEnd";

    return 0;
}