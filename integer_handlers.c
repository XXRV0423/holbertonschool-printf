#include "main.h"
#include <limits.h>

/**
 * print_integer_helper - prints an integer recursively
 * @n: integer to print
 *
 * Return: number of characters printed
 */
int print_integer_helper(int n)
{
	int count;

	count = 0;
	if (n / 10)
		count += print_integer_helper(n / 10);

	write(1, &"0123456789"[n % 10], 1);
	return (count + 1);
}

/**
 * print_integer - prints an integer from va_list
 * @args: va_list with integer argument
 *
 * Return: number of characters printed
 */
int print_integer(va_list args)
{
	int n;
	int count;

	n = va_arg(args, int);
	count = 0;

	if (n == INT_MIN)
	{
		write(1, "-2147483648", 11);
		return (11);
	}

	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		n = -n;
	}

	count += print_integer_helper(n);
	return (count);
}
