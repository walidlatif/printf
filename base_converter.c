#include "main.h"

/**
 * convert - convert - a conversion function similar to itoa
 * @num:the number to be converted
 * @base: the base for the conversion
 * @flags: flags for the function arguments
 * @pars: a structure containing the parameters
 *
 * Return: a string
 */
char *convert(long int num, int base, int flags, type_pars *pars)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;
	(void)pars;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}

	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';
	do {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);
	if (sign)
		*--ptr = sign;

	return (ptr);
}

/**
 * print_unsigned - This function prints unsigned integer numbers.
 * @ap: Pointer to the argument.
 * @pars: Pointer to the parameters struct.
 *
 * Return: The number of bytes printed.
 */
int print_unsigned(va_list ap, type_pars *pars)
{
	unsigned long l;

	if (pars->l)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (pars->h)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	pars->unsign = 1;
	return (print_number(convert(l, 10, CONVERT_UNSIGNED, pars), pars));
}

/**
 * print_address - This function prints an address.
 * @ap: Pointer to the argument.
 * @pars: Pointer to the parameters struct.
 *
 * Return: The number of bytes printed.
 */
int print_address(va_list ap, type_pars *pars)
{
	unsigned long int n = va_arg(ap, unsigned long int);
	char *str;

	if (!n)
		return (_puts("(nil)"));

	str = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, pars);
	*--str = 'x';
	*--str = '0';
	return (print_number(str, pars));
}

