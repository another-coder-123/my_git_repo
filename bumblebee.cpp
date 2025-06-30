#include <iostream>
#include "bumblebee.h"

int is_prime(int num)
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

void get_multiple_prime_numbers(int *arrp, int prime_count)
{
	int primes_found = 0;
	int current_number = 2;
	while (primes_found < prime_count) {
		if (is_prime(current_number) == 1) {
			arrp[primes_found] = current_number;
			std::cout << current_number << " is Prime!\n";
			++primes_found;
		}
		++current_number;
	}
}


int main()
{
	int* arr = NULL;
	int prime_count;
	
	std::cout << "How many prime numbers? ";
	std::cin >> prime_count;
	
	arr = new int[prime_count];

	get_multiple_prime_numbers(arr, (int)prime_count);
	for (int i = 0; i < prime_count; i++)
		std::cout << arr[i] << " , ";
}