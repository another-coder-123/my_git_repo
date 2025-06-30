#include <iostream>

int main()
{
    const int rows = 11;
    const int columns = 11;

    for (int j=1; j <= rows; ++j)
    {
        for (int i=1; i <= columns; ++i)
            std::cout << i * j << ' ';
        std::cout << std::endl;
    }

    std::cout << "End";

    return 0;
}