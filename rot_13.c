#include "main.h"
/**
 * rot_13 - encrypts text using ROT13 cipher
 * @str: string to encode
 * Return: string length
 */
int rot_13(char *str)
{
	int j, i = 0, count = 0;
	char *alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *rot13 = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	if (str == NULL)
		return (-1);

	{
		while (str[i] != '\0')
		{
			for (j = 0; alpha[j] != '\0'; j++)
			{
				if (str[i] == alpha[j])
				{
					count += _putchar(rot13[j]);
					break;
				}
			}
			i++;
		}
	}

	return (count);
}
