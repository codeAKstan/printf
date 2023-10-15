#include <stdlib.h>
#include "main.h"
#include <stdarg.h>

/**
 * handle_character - entry point
 * Function to handle %c specifier
 * @args: the argument it takes
*/
void handle_character(va_list args)
{
	int character = va_arg(args, int);

	_putchar(character);
}

/**
 * handle_string - entry point
 * Function to handle %s specifier
 * @args: the argument it takes
*/
void handle_string(va_list args)
{
	char *string = va_arg(args, char *);

	while (string && *string)
	{
		_putchar(*string);
		string++;
	}
}
/**
 * _printf - entry point. custom print
 * @format: a character string
 * Return: return type is a string
 * _putchar: a function that prints characters
 */
int _printf(const char *format, ...)
{
	size_t i, count = 0;
	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
			case '%':
				_putchar('%');
				break;
			case 'c':
				handle_character(args);
				break;
			case 's':
				handle_string(args);
				break;
			default:
				_putchar('%');
				if (format[i])
					_putchar(format[i]);
				else
				{
					va_end(args);
					return (-1);
				}
				break;
			}
		}
		else
			_putchar(format[i]);
		count++;
	}
	va_end(args);
	return (count);
}
