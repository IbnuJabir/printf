#include "main.h"
/**
 * function_selector - matches format specifier with the handler function
 * @args: va_list object with the variable arguments
 * @f_selector: format specifier character after '%' in format string
 * Return: length of the variable.
 */
int function_selector(va_list args, const char f_selector)
{
	int count = 0;
	unsigned int num;
	char *s;

	if (f_selector == 'c')
		count += print_char(va_arg(args, int));
	else if (f_selector == 's')
	{
		s = va_arg(args, char *);
		if (s != NULL)
			count += print_str(s);
		else
			count += print_str("(nil)");
	}
	else if (f_selector == 'd' || f_selector == 'i')
		count += print_number(va_arg(args, int));
	else if (f_selector == 'u')
		count += print_unsign(va_arg(args, unsigned int));
	else if (f_selector == 'o')
		count += print_octal(va_arg(args, unsigned int));
	else if (f_selector == 'x' || f_selector == 'X')
	{
		num = va_arg(args, unsigned int);
		count += print_hex(num, (f_selector == 'X') ? 1 : 0);
	}
	else if (f_selector == '%')
		count += _putchar('%');
	else if (f_selector == 'R')
		count += rot_13(va_arg(args, char *));
	else if (f_selector == 'b')
		count += print_binary(va_arg(args, unsigned int));
	else
	{
		count += _putchar('%');
		count += _putchar(f_selector);
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
			/* call function selector */
			count += function_selector(vargs, *format);
		}

	format++;
	}
	va_end(vargs);
	return (count);
}

