#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
/**
 * struct func - stores format specifier along with a pointer
 * to its function handler.
 * @specifier: format specifier character
 * @func: pointer to function handler
 */
typedef struct func
{
	char specifier;
	int (*func)();
} f_select;

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(char c);
int rot_13(char *str);
int print_number(int n);
int print_str(char *str);
int print_rev(char *str);
int print_binary(unsigned int num);
int print_unsign(unsigned int num);
int print_octal(unsigned int num);
int print_hex_l(unsigned int num);
int print_hex_u(unsigned int num);

int handle_char(va_list args);
int handle_string(va_list args);
int handle_rot13(va_list args);
int handle_number(va_list args);
int handle_octal(va_list args);
int handle_unsign(va_list args);
int handle_hex_l(va_list args);
int handle_hex_u(va_list args);
int handle_rev(va_list args);
int handle_bin(va_list args);
#endif
