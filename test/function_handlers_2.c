

/**
 * Handle '0' flag for non-custom conversion specifiers.
 * @args: va_list object with variable arguments.
 * @specifier: Conversion specifier character.
 * Return: Total count of characters printed.
 */
int handle_zero_flag(va_list args, const char specifier)
{
	int value;
	int count;

	value = 0;
	if (specifier == 'd' || specifier == 'i') {
		value = va_arg(args, int);
	}

	count = 0;
	if (value >= 0) {
		count += _putchar('0');
		print_zero_padded(value, 8);
	}
	else {
		count += _putchar('-');
		print_zero_padded(-value, 8);
	}

	return (count);
}
