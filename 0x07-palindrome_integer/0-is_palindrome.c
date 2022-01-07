#include "palindrome.h"

/**
 * is_palindrome - checks if an integer is a palindrome
 *
 * @n: integer to check
 * Return: 1 if palindrome, else 0
*/
int is_palindrome(unsigned long n)
{
	unsigned long i = n, r = 0;

	
	for (i = n; i != 0; i /= 10)
		r = (r * 10) + (i % 10);
	return (n == r ? 1 : 0);
}

