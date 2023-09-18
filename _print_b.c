#include "main.h"
/**
 * print_binary - Prints the binary representation of an unsigned integer.
 * @num: The unsigned integer to be printed.
 *
 * Returns: The number of characters printed.
 */
unsigned int print_binary(unsigned int num)
{
	unsigned int count = 0;
	unsigned int bit = 1 << (sizeof(num) * 8 - 1);
	int has_zeros = 1;

	for (; bit > 0; bit >>= 1)
	{
		if (num & bit)
		{
			has_zeros = 0;
			putchar('1');
			count++;
		}
		else if (!has_zeros || bit == 1)
		{
			putchar('0');
			count++;
		}
	}

	return (count);
}
