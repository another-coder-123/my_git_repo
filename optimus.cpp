#include <iostream>
#include <string>
#include <string_view>

class NegativeNumberException : public std::exception
{
private:
	std::string m_error;
public:
	NegativeNumberException(const std::string& error) : m_error(error) {}
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

//Returns true if the given number is prime, false if not
bool is_prime(int num)
{
	if (num < 0) {
		throw NegativeNumberException("Negative number cannot be prime!");
	}
	for (int i = 2; i < num; ++i)
	{
		if ((num % i) == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int div_result;
	int number;
	int prime_flag;
	
	std::cout << "Enter a number: ";
	if (std::cin >> number) {
		std::cout << "Checking if " << number << " is prime..." << std::endl;
		prime_flag = is_prime(number);
		if (prime_flag)
		{
			std::cout << "It is Prime!" << std::endl;
		}
		else {
			std::cout << "This number is not Prime!" << std::endl;
		}
	}
	else {
		throw InvalidInputException("Invalid Input! input should be a whole positive number");
	}
	return 0;
}