#include <iostream>
#include "bumblebee.h"

const int FIRST_PRIME_NUMBER = 2;

class ArrayLengthTooShortException : public std::exception
{
private:
	std::string m_error;
public:
	ArrayLengthTooShortException(const std::string& error) : m_error(error) {}
	const std::string& getError() const {
		return m_error;
	}
};

class InvalidInputException : public std::exception
{
private:
	std::string m_error;
public:
	InvalidInputException(const std::string& error) : m_error(error) {}
	const std::string& getError() const {
		return m_error;
	}
};

bool is_prime(int num)
{
	for (int i = FIRST_PRIME_NUMBER; i < num; ++i)
	{
		if ((num % i) == 0)
		{
			return false;
		}
	}
	return true;
}

void get_multiple_prime_numbers(int *arrp, int prime_count)
{
	int primes_found = 0;
	int current_number = FIRST_PRIME_NUMBER;

	while (primes_found < prime_count) {
		if (is_prime(current_number)) {
			arrp[primes_found] = current_number;
			std::cout << current_number << " is Prime!" << std::endl;
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
	if (std::cin >> prime_count) {

		if (prime_count < 1) {
			throw ArrayLengthTooShortException("Array size shuold be bigger than zero");
		}

		arr = new int[prime_count];

		get_multiple_prime_numbers(arr, (int)prime_count);
		for (int i = 0; i < prime_count; i++)
			std::cout << arr[i] << " , ";

		delete[] arr;
	} 
	else {
		throw InvalidInputException("Invalid Input! input should be a whole positive number");
	}
	return 0;
}