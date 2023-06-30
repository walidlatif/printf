#include "main.h"

/**
 * print_from_to - prints a range of char addresses
 * @start: starting address
 * @stop: stopping address
 * @except: except address
 *
 * Return: number of bytes printed
 */
int print_from_to(char *start, char *stop, char *except)
{
	int sum = 0;

	while (start <= stop)
	{
		if (start != except)
			sum += _putchar(*start);
		start++;
	}
	return (sum);
}

/**
 * print_rev - prints string in reverse
 * @ap: string
 * @pars: the parameters struct
 *
 * Return: number of bytes printed
 */
int print_rev(va_list ap, type_pars *pars)
{
	int len, sum = 0;
	char *str = va_arg(ap, char *);
	(void)pars;

	if (str)
	{
		for (len = 0; str[len] != '\0'; len++)
			;
		str--;
		for (; len > 0; len--, str--)
			;
			sum += _putchar(*str);
	}
	return (sum);
}

/**
 * print_rot13 - prints string in rot13
 * @ap: string
 * @pars: the parameters struct
 *
 * Return: number of bytes printed
 */
int print_rot13(va_list ap, type_pars *pars)
{
	int i, index;
	int count = 0;
	char arr[] = "NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(ap, char *);
	(void)pars;

	i = 0;
	index = 0;
	while (a[i] != '\0')
	{
		if ((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z'))
		{
			index = a[i] - 'A';
			if (a[i] >= 'a' && a[i] <= 'z')
				index = index + 26;
			count += _putchar(arr[index]);
		}
		else
		{
			count += _putchar(a[i]);
		}
		i++;
	}
	return (count);
}

