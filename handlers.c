#include "main.h"

/**
 * _putchar - writes characters to stdout
 * @c: character to write
 *
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_char - prints a single character from va_list
 * @args: va_list with character argument
 *
 * Return: number of characters printed
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (_putchar(c));
}

/**
 * print_string - print a string form va_list
 * @args: va_list with a string argument
 *
 * Return: number of characters printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;

	if (!str)
		str = "(null)";

	while (*str)
	{
		count += _putchar(*str);
		str++;
	}
	return (count);
}

/**
 * print_percent - print a literal percent sign
 *
 * Return: 1
 */
int print_percent(void)
{
	return (_putchar('%'));
}

/**
 * handle_specifier - dispatches to the correct print function
 * @spec: the conversion specifier character
 * @args: va_list of arguments
 *
 * Return: number of characters printed
 */
int handle_specifier(char spec, va_list args)
{
	if (spec == 'c')
		return (print_char(args));
	if (spec == 's')
		return (print_string(args));
	if (spec == '%')
		return (print_percent());
	if (spec == 'd' || spec == 'i')
		return (print_integer(args));

	_putchar('%');
	_putchar(spec);
	return (2);
}
