File Edit Options Buffers Tools C Help                                                                                                              
#include <stdlib.h>
#include "main.h"
/**                                                                                                                                                 
 * _printf - entry point. custom print                                                                                                              
 * @format: a character string                                                                                                                      
 * Return: return type is a string                                                                                                                  
 */
int _printf(const char *format, ...)
{
        size_t c, count = 0, len = 0;
        char *s;
        va_list args;

        if (format == NULL)
                return (-1);

        va_start(args, format);
        while (*format)
        {
                if (*format != '%')
                {
                        write(1, format, 1);
                        count++;
                }
                else
                {
                        format++;
                        if (*format == '\0')
                                break;
                        if (*format == '%')
                        {
                                write(1, format, 1);
                                count++;
                        }
                        else if (*format == 'c')
                        {
                                c = va_arg(args, int);
                                write(1, &c, 1);
                                count++;
                        }
                        else if (*format == 's')
                        {
                                s = va_arg(args, char *);
                                while (s[len] != '\0')
                                        len++;
                                write(1, s, len);
                                count += len;
                        }
                }
                format++;
        }
        va_end(args);
        return (count);
}
