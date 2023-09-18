#include "main.h"
/**
 * print_str - prints string to the stdout
 * @str: string
 * Return: returns the length of the string excluding null terminator
 */
int print_str(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
/**
 * print_char - prints one character
 * @c: character
 * Return: returns 1 (size of character)
 */
int print_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * function_selector - matches format specifier with the handler function
 * @args: va_list object with the variable arguments
 * @f_selector: format specifier character after '%' in format string
 * Return: length of the variable.
 */
int function_selector(va_list args, char f_selector)
{
	int count = 0;
	char *s;

	switch (f_selector)
	{
		case 'c':
			print_char(va_arg(args, int));
			break;
		case 's':
			s = va_arg(args, char *);
			if (s != NULL)
				count = print_str(s);
			else
				count = print_str("(nil)");
			break;
		default:
			count = print_char('%');
			count += print_char(f_selector);
			break;
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
	while (*format)
	{
		if (*format != '%')
		{
			count += print_char(*format);
		}
		else
		{
			/* move to the next char after % */
			++format;
			/* call function selector */
			count += function_selector(vargs, *format);
		}

	format++;
	}
	va_end(vargs);
	return (count);
}

