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

	write(1, &character, 1);
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
	        write(1, string, 1);
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
				write(1, "%", 1);
				break;
			case 'c':
				handle_character(args);
				break;
			case 's':
				handle_string(args);
				break;
			default:
			        write(1, "%", 1);
				if (format[i])
					write(1, &format[i], 1);
				else
				{
					va_end(args);
					return (-1);
				}
				break;
			}
		}
		else
		        write(1, &format[i], 1);
		count++;
	}
	va_end(args);
	return (count);
}
