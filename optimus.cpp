#include <iostream>

int is_prime(int num)
/**
* Returnes 1 (True) if the given number is prime
* 0 if it's not prime
*/
{
	for (int i{ 2 }; i < num; ++i)
	{
		if ((num % i) == 0)
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int number;
	int prime_flag;
	std::cout << "Enter a number: ";
	std::cin >> number;
	std::cout << "Checking if " << number << " is prime...\n";
	prime_flag = is_prime(number);
	if (prime_flag == 1)
		std::cout << "It is Prime!\n";
	else 
		std::cout << "This number is not Prime!\n";
}