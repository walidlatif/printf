#include "main.h"

/**
 * _puts - Prints a string and appends a newline character
 * @str: The string to be printed
 *
 * Return: The number of characters in the string (excluding the newline)
 */

int _puts(char *str)
{
	int count = 0;

	while (*str)
	{
		_putchar(*str++);
		count++;
	}

	return (count);
}

/**
 * _putchar - Writes the specified character to the standard output
 * @c: The character to be printed
 *
 * Return: 1 on success
 *         -1 on error with the appropriate error number set in errno
 */

int _putchar(int c)
{
	static int index;
	static char buffer[BUFFER_SIZE];

	if (c == BUFFER_FLUSH || index >= BUFFER_SIZE)
	{
		write(1, buffer, index);
		index = 0;
	}

	if (c != BUFFER_FLUSH)
		buffer[index++] = c;

	return (1);
}

