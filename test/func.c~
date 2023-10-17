#include "main.h"
/**
 * print_unsigned - entry point
 * @num: variable of type unsigned int
 * @count: number of count
 */

void print_unsigned(unsigned int num, size_t *count)
{
	char num_str[12];
	int len = 0;
	int i;

	if (num == 0)
		num_str[len++] = '0';
	while (num > 0)
	{
		num_str[len++] = num % 10 + '0';
		num = num / 10;
	}

	for (i = len - 1; i >= 0; i--)
	{
		write(1, &num_str[i], 1);
		(*count)++;
	}
}
/**
 * print_octal - entry point
 * @num: variable of type unsigned int
 * @count: number count
 */

void print_octal(unsigned int num, size_t *count)
{
	char octal_str[12];
	int len = 0;
	int i;

	while (num > 0)
	{
		octal_str[len++] = num % 8 + '0';
		num = num / 8;
	}

	if (len == 0)
		octal_str[len++] = '0';

	for (i = len - 1; i >= 0; i--)
	{
		write(1, &octal_str[i], 1);
		(*count)++;
	}
}

/**
 * print_hex - entry point
 * @num: variable of type unsigned int
 * @uppercase: flag to print uppercase hex
 * @count: number count
 */
void print_hex(unsigned int num, int uppercase, size_t *count)
{
	char hex_str[12];
	int len = 0;
	int i, remainder;

	while (num > 0)
	{
		remainder = num % 16;
		if (remainder < 10)
			hex_str[len++] = remainder + '0';
		else
			hex_str[len++] = (uppercase ? 'A' : 'a') + remainder - 10;
		num = num / 16;
	}

	if (len == 0)
		hex_str[len++] = '0';

	for (i = len - 1; i >= 0; i--)
	{
		write(1, &hex_str[i], 1);
		(*count)++;
	}
}
