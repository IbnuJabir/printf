#include "main.h"
/**
 * print_rev - prints string in reverse
 * @s: string
 * Return: length of string printed
 */
int print_rev(char *s)
{
	int i = 0, len, count = 0;
	char c;

	if (s == NULL)
		s = ")LLUN(";
	/* get length of string */
	for (len = 0; s[len] != '\0'; len++)
		;

	/* reverse string */
	for (i = len - 1; i >= 0; i--)
	{
		c = s[i];
		count += _putchar(c);
	}
	return (count);
}
