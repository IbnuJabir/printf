#include "main.h"
/**
 * print_binary - Prints the binary representation of an unsigned integer.
 * @num: The unsigned integer to be printed.
 *
 * Return: The number of characters printed.
 */
int print_binary(unsigned int num)
{
	int count = 0;
	int i = 0;
	int num_bits = sizeof(num) * 8;
	unsigned int bit = 1U << (num_bits - 1);
	int has_zeros = 1;

	for ( ; i < num_bits; i++)
	{
		if ((num & bit) != 0)
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

		bit >>= 1;
	}

	return (count);
}
