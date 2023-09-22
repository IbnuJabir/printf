#include "main.h"
/**
 * handle_rot13 - Handles the 'R' format specifier.
 * @args: va_list object with the variable arguments.
 * Return: The number of characters printed.
 */

int handle_rot13(va_list args)
{
	char *s = va_arg(args, char *);

	return (rot_13(s));
}

/**
 * handle_rev - Handles the 'r' format specifier
 * @args: va_list object
 * Return: number of characters printed in reverse
 */
int handle_rev(va_list args)
{
	char *s = va_arg(args, char *);

	return (print_rev(s));
}

/**
 * handle_unsign - Handles the 'u' format specifier
 * @args: va_list object
 * Return: number of digits printed
 */
int handle_unsign(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);

	return (print_unsign(num));
}

/**
 * handle_hex_l - handles 'x'
 * @args: va_list object
 * Return: number of characters printed
 */
int handle_hex_l(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);

	return (print_hex_l(num));
}

/**
 * handle_hex_u - handles 'X'
 * @args: va_list object
 * Return: number of hexadecimal digits printed
 */
int handle_hex_u(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);

	return (print_hex_u(num));
}
/**
 * Handle '0' flag for non-custom conversion specifiers.
 *
 * @args: va_list object with variable arguments.
 * @specifier: Conversion specifier character.
 *
 * Return: Total count of characters printed.
 */
int handle_zero_flag(va_list args, const char specifier)
{
	int value;
	int count;

	value = 0;
	if (specifier == 'd' || specifier == 'i') {
		value = va_arg(args, int);
	}

	count = 0;
	if (value >= 0) {
		count += _putchar('0');
		print_zero_padded(value, 8);
	}
	else {
		count += _putchar('-');
		print_zero_padded(-value, 8);
	}

	return (count);
}
