#include "main.h"
#include <stdarg.h>

/**
 * _putchar - writes the character c to stdout
 * in this function we gonna handle the option %c
 *
 * Return: the number of characters printed (excluding the null byte used to end output to strings)
 * On error, -1 is returned, and errno is set appropriately.
 */

int _printf(const char *format, ...)
{
	int i;
	int count = 0;
	va_list st;
	
	va_start(st, format);
	if (!format)
	{
		return (-1);
	}
	
	while (*format != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				char c = (char)va_arg(st, int);
				putchar(c);
				count++;
			}
			if (format[i + 1] == 's')
			{
				char *str = va_arg(st, char *);
				while (*str != '\0')
				{
					putchar(*str);
					str++;
					count++;
				}
			}
			if (format[i + 1] == '%')
			{
				putchar('%');
				count++;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(st);
	return (count);
}
