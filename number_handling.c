#include "main.h"

/**
 * _isdigit - checks if character is digit
 * @c: the character to check
 *
 * Return: 1 if digit, 0 otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
 * print_number - prints a number with options
 * @str: the base number as a string
 * @pars: the parameter struct
 *
 * Return: chars printed
 */
int print_number(char *str, type_pars *pars)
{
	unsigned int i = _strlen(str);
	int neg = (!pars->unsign && *str == '-');

	if (!pars->precision && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		i--;
	}
	if (pars->precision != UINT_MAX)
		while (i++ < pars->precision)
			*--str = '0';
	if (neg)
		*--str = '-';

	if (!pars->fl_minus)
		return (print_number_right_shift(str, pars));
	else
		return (print_number_left_shift(str, pars));
}

/**
 * print_number_right_shift - prints a number with options
 * @str: the base number as a string
 * @pars: the parameter struct
 *
 * Return: chars printed
 */
int print_number_right_shift(char *str, type_pars *pars)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (pars->fl_zero && !pars->fl_minus)
	{
		pad_char = '0';
		neg = neg2 = (!pars->unsign && *str == '-');
	}
	if (neg && i < pars->w_width && pad_char == '0' && !pars->fl_minus)
		str++;
	else
			neg = 0;
	if ((pars->fl_plus && !neg2) ||
			(!pars->fl_plus && pars->fl_space && !neg2))
		i++;
	if (neg && pad_char == '0')
		n += _putchar('-');
	if (pars->fl_plus && !neg2 && pad_char == '0' && !pars->unsign)
		n += _putchar('+');
	else if (!pars->fl_plus && pars->fl_space && !neg2 &&
			!pars->unsign && pars->fl_zero)
		n += _putchar(' ');
	while (i++ < pars->w_width)
		n += _putchar(pad_char);
	if (neg && pad_char == ' ')
		n += _putchar('-');
	if (pars->fl_plus && !neg2 && pad_char == ' ' && !pars->unsign)
		n += _putchar('+');
	else if (!pars->fl_plus && pars->fl_space && !neg2 &&
			!pars->unsign && !pars->fl_zero)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}

/**
 * print_number_left_shift - prints a number with options
 * @str: the base number as a string
 * @pars: the parameter struct
 *
 * Return: chars printed
 */
int print_number_left_shift(char *str, type_pars *pars)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (pars->fl_zero && !pars->fl_minus)
		pad_char = '0';
	neg = neg2 = (!pars->unsign && *str == '-');
	if (neg && i < pars->w_width && pad_char == '0' && !pars->fl_minus)
		str++;
	else
		neg = 0;

	if (pars->fl_plus && !neg2 && !pars->unsign)
		n += _putchar('+'), i++;
	else if (pars->fl_space && !neg2 && !pars->unsign)
		n += _putchar(' '), i++;
	n += _puts(str);
	while (i++ < pars->w_width)
		n += _putchar(pad_char);
	return (n);
}

