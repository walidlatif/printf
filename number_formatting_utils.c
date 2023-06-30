#include "main.h"

/**
 * print_char - prints character
 * @ap: argument pointer
 * @pars: the parameters struct
 *
 * Return: number of characters printed
 */
int print_char(va_list ap, type_pars *pars)
{
	char pad_char = ' ';
	unsigned int pad = 1, sum = 0, ch = va_arg(ap, int);

	if (pars->fl_minus)
		sum += _putchar(ch);
	while (pad++ < pars->w_width)
		sum += _putchar(pad_char);
	if (!pars->fl_minus)
		sum += _putchar(ch);
	return (sum);
}

/**
 * print_int - prints integer
 * @ap: argument pointer
 * @pars: the parameters struct
 *
 * Return: number of characters printed
 */
int print_int(va_list ap, type_pars *pars)
{
	long l;

	if (pars->l)
		l = va_arg(ap, long);
	else if (pars->h)
		l = (short int) va_arg(ap, int);
	else
		l = (int) va_arg(ap, int);
	return (print_number(convert(l, 10, 0, pars), pars));
}

/**
 * print_string - prints string
 * @ap: argument pointer
 * @pars: the parameters struct
 *
 * Return: number of characters printed
 */
int print_string(va_list ap, type_pars *pars)
{
	char *str = va_arg(ap, char *), pad_char = ' ';
	unsigned int pad = 0, sum = 0, i = 0, j;

	(void) pars;
	switch ((int) (!str))
	{
		case 1:
			str = NULL_STRING;
			break;
}
	j = pad = _strlen(str);
	if (pars->precision < pad)
		j = pad = pars->precision;

	if (pars->fl_minus)
{
		if (pars->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	while (j++ < pars->w_width)
		sum += _putchar(pad_char);
	if (!pars->fl_minus)
{
		if (pars->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	return (sum);
}

/**
 * print_percent - prints string
 * @ap: argument pointer
 * @pars: the parameters struct
 *
 * Return: number of characters printed
 */
int print_percent(va_list ap, type_pars *pars)
{
	(void) ap;
	(void) pars;
	return (_putchar('%'));
}

/**
 * print_S - custom format specifier
 * @ap: argument pointer
 * @pars: the parameters struct
 *
 * Return: number of characters printed
 */
int print_S(va_list ap, type_pars *pars)
{
	char *str = va_arg(ap, char *);
	char *hex;
	int sum = 0;

	if ((int) (!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = convert(*str, 16, 0, pars);
			if (!hex[1])
				sum += _putchar('0');
			sum += _puts(hex);
		}
		else
		{
			sum += _putchar(*str);
		}
	}
	return (sum);
}

