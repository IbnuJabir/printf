#include "main.h"
/**
 * print_rev - prints string in reverse
 * @s: string
 * Return: length of string printed
 */
int print_rev(char *s)
{
	int i, len, count = 0;

	/* get length of string */
	for (len = 0; s[len] != '\0'; len++)
		;
	/* reverse string */
	for (i = len - 1; i >= 0; i--)
	{
		count += _putchar(s[i]);
	}
	return (count);
}
