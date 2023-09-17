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
 * _printf - this is a custom printf function that writes characters on
 * the standard output
 * @format: format specifier string
 * Return: number of characters printed to the stdout
 */
int _printf(const char *format, ...)
{
	int count = 0;
	char *str = NULL;
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

			/* check if character after % is c or s */
			if (*format == 'c')
			{
				count += print_char(va_arg(vargs, int));
			}
			else if (*format == 's')
			{
				str = va_arg(vargs, char *);
				printf("(%s)", str);
				count += print_str(str);
			}
		}

	format++;
	}
	va_end(vargs);
	return (count);
}

