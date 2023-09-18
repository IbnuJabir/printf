#include "main.h"
/**
 * rot13 - encrypts text using ROT13 cipher
 * @s: string to encode
 * Return: string length
 */
int rot13(char *s)
{
	char *alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i, temp = 0, count = 0;

	while (*s != '\0')
	{
		for (i = 0; i < 26; i++)
		{
			if (*s == alpha[i])
			{
				temp = i;
				temp += 13;
				if (temp > 25)
				{
					temp -= 26;
				}
				count += _putchar(alpha[temp]);
			}
		}
		s++;
	}
	_putchar('\n');
	return (count);
}
/**
 * print_number - prints signed and usigned numbers
 * @n: number
 * Return: number of characters in a number
 */
int print_number(int n)
{
	unsigned int count = 0;
	unsigned int temp;

	if (n < 0)
	{
		n = -n;
		temp = n;
		count += _putchar('-');
	}

	temp = n;
	temp /= 10;

	if (temp != 0)
		count += print_number(temp);

	count += _putchar((unsigned int) n % 10 + '0');
	return (count);
}
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
		_putchar(str[i]);
		i++;
	}
	return (i);
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
	char *s = NULL;

	switch (f_selector)
	{
		case 'c':
			count += _putchar(va_arg(args, int));
			break;
		case 's':
			s = va_arg(args, char *);
			if (s != NULL)
				count += print_str(s);
			else
				count += print_str("(nil)");
			break;
		case 'd':
		case 'i':
			count += print_number(va_arg(args, int));
			break;
		case '%':
			count += _putchar('%');
			break;
		case 'R':
			s = va_arg(args, char *);
			count += rot13(s);
		case 'u':
			count += print_number(va_arg(args, unsigned int));
			break;
		default:
			count += _putchar('%');
			count += _putchar(f_selector);
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
			count += _putchar(*format);
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

