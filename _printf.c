#include <stdlib.h>
#include "main.h"
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
				write(1, format - 1, 2), count += 2;
		}
		format++;
	}
	va_end(args);
	return (count);
}
