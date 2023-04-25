#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * _putchar_ - A function that prints the character c to a standard output
 * @c: the character to print
 *
 * Return: 1 on succes
 * -1 on error, and sets errno appropriately
 */

int _putchar_(char c)
{
	return (write(1, &c, 1));
}
