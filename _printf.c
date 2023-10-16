#include <stdlib.h>
#include "main.h"
void print_unknown_specifier(char specifier, size_t *count);
void print_null_or_str(char *s, size_t *count);
/**
 * print_null_or_str - entry point
 * @s: a string of characters
 * @count: characrter count
 */
void print_null_or_str(char *s, size_t *count)
{
	size_t len = 0;

	if (s == NULL)
	{
		write(1, "(null)", 6);
		(*count) += 6;
	}
	else
	{
		while (s[len] != '\0')
			len++;
		write(1, s, len);
		(*count) += len;
	}
}
/**
 * print_unknown_specifier - entry point
 * @specifier: the unknown specifier
 * @count: character count
 */
void print_unknown_specifier(char specifier, size_t *count)
{
	write(1, "%", 1);
	write(1, &specifier, 1);
	(*count) += 2;
}
/**
 * _printf - entry point. custom printf
 * @format: a charcter string
 * Return: return type is a string
 */
int _printf(const char *format, ...)
{
	size_t c, count = 0;
	char *s;
	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
			write(1, format, 1), count++;
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
				write(1, format, 1), count++;
			else if (*format == 'c')
			{
				c = va_arg(args, int);
				write(1, &c, 1), count++;
			}
			else if (*format == 's')
			{
				s = va_arg(args, char *);
				print_null_or_str(s, &count);
			}
			else
			{
				print_unknown_specifier(*format, &count);
			}
		}
		format++;
	}
	va_end(args);
	return (count);
}
