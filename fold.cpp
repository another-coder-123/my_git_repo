#include <iostream>

const int ROWS = 11;
const int COLUMNS = 11;

int main()
{
    for (int j=1; j <= ROWS; ++j)
    {
        for (int i=1; i <= COLUMNS; ++i)
            std::cout << i * j << ' ';
        std::cout << std::endl;
    }

    std::cout << "End";

    return 0;
}