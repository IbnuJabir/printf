#include "main.h"
/**
 * print_binary - Prints the binary representation of an unsigned integer.
 * @num: The unsigned integer to be printed.
 * Return: The number of characters printed.
 */
unsigned int print_binary(unsigned int num)
{
	int i = 0, j;
	int bit[32];
	unsigned int count = 0;

	if (num == 0)
	{
		count += _putchar('0' + num);
		return (count);
	}
	while (num > 0)
	{
		bit[i] = num % 2;
		num = num / 2;
		i++;
	}

	for (j = i - 1; j >= 0; j--)
	{
		count += _putchar('0' + bit[j]);
	}
	return (count);
}
