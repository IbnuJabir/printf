#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

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
int print_hex(unsigned int num, int uppercase);

int handle_string(va_list args);
int handle_rot13(va_list args);
int handle_default(char f_selector);

#endif
