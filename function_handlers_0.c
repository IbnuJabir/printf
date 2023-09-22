#include "main.h"
/**
 * handle_char - Handles the 'c' format specifier.
 * @args: va_list object with the variable arguments.
 * Return: The number of characters printed.
 */

int handle_char(va_list args)
{
	char c = va_arg(args, int);

	return (print_char(c));
}

/**
 * handle_string - Handles the 's' format specifier.
 * @args: va_list object with the variable arguments.
 * Return: The number of characters printed.
 */

int handle_string(va_list args)
{
	char *s = va_arg(args, char *);

	if (s != NULL)
		return (print_str(s));
	else
		return (print_str("(null)"));
}

/**
 * handle_number - Handles the 'i' and 'd' format specifiers
 * @args: va_list object with variable arguments
 * Return: number of chars printed
 */

int handle_number(va_list args)
{
	int num = va_arg(args, int);

	return (print_number(num));
}

/**
 * handle_octal - Handles the 'o'format specifier
 * @args: va_list object with variable arguments
 * Return: num of chars printed
 */

int handle_octal(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);

	return (print_octal(n));
}

/**
 * handle_bin - handles the 'b' format specifier
 * @args: arguments in variable list
 * Return: number of characters printed
 */

int handle_bin(va_list args)
{
	unsigned int decimal = va_arg(args, unsigned int);

	return (print_binary(decimal));
}
