#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _putchar(char c);
int _printf(const char *format, ...);
void handle_character(va_list args);
void handle_string(va_list args);


#endif
