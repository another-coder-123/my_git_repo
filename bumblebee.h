#ifndef BUMBLEBEE_H_FILE
#define BUMBLEBEE_H_FILE
#endif

/**
* Checks if number is prime.
* 
* Returnes 1 (True) if the given number is prime
* 0 if it's not prime
* 
* @param num is the int type number to check
* @return 1 if 'num' is prime, 0 if not
*/
bool is_prime(int num);


/**
* Fills array with prime numbers
*
* fills array at '*arrp' with prime numbers by the amount specified in 'prime_count'
* 
* @param arrp is an array pointer to the array the function fills
* @param prime_count is the number of prime numbers to fill the array with
*/
void get_multiple_prime_numbers(int* arrp, int prime_count);