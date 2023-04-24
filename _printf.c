#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf: handle %c and the s and the %
 * @format: variadic parametr
 * Return: the number of characters printed
 * excluding the null byte used to end output to strings
 * On error, -1 is returned, and errno is set appropriately.
 */

int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;
    char c;
    char *s;
    
    va_start(args, format);
    
    while (*format != '\0') {
        if (*format == '%') {
            format++; // move past the '%'
            switch (*format) {
                case 'c':
                    c = (char)va_arg(args, int);
                    putchar(c);
                    printed_chars++;
                    break;
                case 's':
                    s = va_arg(args, char *);
                    while (*s != '\0') {
                        putchar(*s);
                        s++;
                        printed_chars++;
                    }
                    break;
                case '%':
                    putchar('%');
                    printed_chars++;
                    break;
            }
        } else {
            putchar(*format);
            printed_chars++;
        }
        format++;
    }
    
    va_end(args);
    
    return printed_chars;
}
