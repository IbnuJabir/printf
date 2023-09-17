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


