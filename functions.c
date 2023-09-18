#include "main.h"

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
		return (print_str("(nil)"));
}

/**
 * handle_rot13 - Handles the 'R' format specifier.
 * @args: va_list object with the variable arguments.
 * Return: The number of characters printed.
 */
int handle_rot13(va_list args)
{
	char *r = va_arg(args, char *);

	return (rot_13(r));
}

/**
 * handle_default - Handles the default case for unknown format specifiers.
 * @f_selector: The unknown format specifier character.
 * Return: The number of characters printed.
 */
int handle_default(char f_selector)
{
	int count = 0;

	count += _putchar('%');
	count += _putchar(f_selector);
	return (count);
}
