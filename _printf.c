#include "main.h"
/**
 * function_selector - matches format specifier with the handler function
 * @args: va_list object with the variable arguments
 * @f_specifier: format specifier character after '%' in format string
 * Return: length of the variable.
 */
int function_selector(va_list args, const char f_specifier)
{
f_select f[] = {
		{'c', handle_char}, {'s', handle_string},
		{'i', handle_number}, {'d', handle_number},
		{'o', handle_octal}, {'b', handle_bin},
		{'R', handle_rot13}, {'x', handle_hex_l},
		{'X', handle_hex_u}, {'u', handle_unsign},
		{'r', handle_rev}, {0, NULL}
	};
unsigned int i = 0;
int count = 0;
unsigned int size = sizeof(f) / sizeof(f_select) - 1;

while (i < size)
{
	if (f_specifier == f[i].specifier)
	{
		count += f[i].func(args);
		break;
	}
	i++;
}
	/* print default if format specifier is unknown */
	if (i == size)
	{
		count += print_char('%');
		count += print_char(f_specifier);
	}
	return (count);
}
/**
 * _printf - this is a custom printf function that writes characters on
 * the standard output
 * @format: format specifier string
 * Return: number of characters printed to the stdout
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list vargs;

	va_start(vargs, format);

	/* iterate format string up to the last non-null character */
	if (format == NULL)
		return (-1);
	while (*format)
	{
		if (*format != '%')
		{
			count += _putchar(*format);
		}
		else
		{
			/* move to the next char after % */
			++format;
			if (*format == '\0')
				return (-1);
			if (*format == '%')
				count += _putchar('%');
			else
				/* call function selector */
				count += function_selector(vargs, *format);
		}
	format++;
	}

	va_end(vargs);
	return (count);
}

