#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int _putchar(char c);
int _printf(const char format, ...);
void print_unknown_specifier(char specifier, size_tcount);
void print_null_or_str(char s, size_tcount);
#endif
