#include "main.h"
/**
 * print_zero_padded - prints number with a zero padding
 * @value: Value to be printed.
 * @width: Padding width.
 */
void print_zero_padded(int value, int width)
{
	int padding, divisor;

	padding = width;

	if (value < 0)
	{
		_putchar('-');
		value = -value;
		padding--;
	}

	divisor = 1;
	while (padding > 1)
	{
		divisor *= 10;
		padding--;
	}

	while (divisor != 0)
	{
		int digit = value / divisor;

		_putchar('0' + digit);
		value %= divisor;
		divisor /= 10;
	}
}
