#include "main.h"

/**
 * print_unsigned - Print an unsigned integer
 * @num: The unsigned integer to be printed
 *
 * Return: The number of characters printed
 */
int print_unsign(unsigned int num)
{
	unsigned int divisor = 1;
	int count = 0;

	while (num / divisor >= 10)
		divisor *= 10;

	while (divisor != 0)
	{
		count += putchar('0' + (num / divisor));
		num %= divisor;
		divisor /= 10;
	}

	return (count);
}

/**
 * print_octal - Print an octal number
 * @num: The unsigned integer to be printed as an octal number
 *
 * Return: The number of characters printed
 */
int print_octal(unsigned int num)
{
	unsigned int octal_digits[32];
	int i = 0;
	int count = 0;
	int j;

	while (num != 0)
	{
		octal_digits[i++] = num % 8;
		num /= 8;
	}

	for (j = i - 1; j >= 0; j--)
		count += putchar('0' + octal_digits[j]);

	return (count);
}

/**
 * print_hex - Print a hexadecimal number
 * @num: The unsigned integer to be printed as a hexadecimal number
 * @uppercase: Flag indicating whether uppercase (1) or lowercase (0)
 *
 * Return: The number of characters printed
 */
int print_hex(unsigned int num, int uppercase)
{
	int j;
	int i = 0;
	int count = 0;
	char hex_digits[] = "0123456789abcdef";
	char hex_representation[32];

	if (uppercase)
	{
		hex_digits[10] = 'A';
		hex_digits[11] = 'B';
		hex_digits[12] = 'C';
		hex_digits[13] = 'D';
		hex_digits[14] = 'E';
		hex_digits[15] = 'F';
	}


	while (num != 0)
	{
		hex_representation[i++] = hex_digits[num % 16];
		num /= 16;
	}

	for (j = i - 1; j >= 0; j--)
		count += putchar(hex_representation[j]);

	return (count);
}
