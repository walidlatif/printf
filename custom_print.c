#include "main.h"

/**
*print_hex - Prints unsigned hexadecimal numbers in lowercase.
*@ap: The argument pointer.
*@pars: The parameters struct.
*Return: The number of bytes printed.
*/

int print_hex(va_list ap, type_pars *pars)
{
	unsigned long le;
	int c = 0;
	char *str;

	le = (pars->l) ? (unsigned long)va_arg(ap, unsigned long) :
		(pars->h) ? (unsigned short int)va_arg(ap, unsigned int) :
		(unsigned int)va_arg(ap, unsigned int);

	str = convert(le, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, pars);

	if (pars->fl_hash && le)
	{
		str--;
		*str = 'x';
		str--;
		*str = '0';
	}

	pars->unsign = 1;
	return (c += print_number(str, pars));
}

/**
*print_HEX - Prints unsigned hexadecimal numbers in uppercase.
*@ap: The argument pointer.
*@pars: The parameters struct.
*Return: The number of bytes printed.
*/

int print_HEX(va_list ap, type_pars *pars)
{
	unsigned long le;
	int c = 0;
	char *str;

	le = (pars->l) ? (unsigned long)va_arg(ap, unsigned long) :
		(pars->h) ? (unsigned short int)va_arg(ap, unsigned int) :
		(unsigned int)va_arg(ap, unsigned int);

	str = convert(le, 16, CONVERT_UNSIGNED, pars);

	if (pars->fl_hash && le)
	{
		str--;
		*str = 'X';
		str--;
		*str = '0';
	}
	pars->unsign = 1;
	return (c += print_number(str, pars));
}

/**
*print_binary - Prints unsigned binary number.
*@ap: The argument pointer.
*@pars: The parameters struct.
*Return: The number of bytes printed.
*/

int print_binary(va_list ap, type_pars *pars)
{
	unsigned int n = va_arg(ap, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGNED, pars);
	int c = 0;

	if (pars->fl_hash && n)
	{
		str--;
		*str = '0';
	}

	pars->unsign = 1;
	return (c += print_number(str, pars));
}
/**
*print_octal - Prints unsigned octal numbers.
*@ap: The argument pointer.
*@pars: The parameters struct.
*Return: The number of bytes printed.
*/

int print_octal(va_list ap, type_pars *pars)
{
	unsigned long le;
	char *str;
	int c = 0;

	le = (pars->l) ? (unsigned long)va_arg(ap, unsigned long) :
		(pars->h) ? (unsigned short int)va_arg(ap, unsigned int) :
		(unsigned int)va_arg(ap, unsigned int);

	str = convert(le, 8, CONVERT_UNSIGNED, pars);

	if (pars->fl_hash && le)
	{
		str--;
		*str = '0';
	}

	pars->unsign = 1;
	return (c += print_number(str, pars));
}

