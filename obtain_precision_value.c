#include "main.h"

/**
 * get_precision - Retrieves the precision from the format string
 * @pr_str: the format string
 * @pars: the parameters struct
 * @ap: the argument pointer
 *
 * Return: new pointer
 */
char *get_precision(char *pr_str, type_pars *pars, va_list ap)
{
	int d = 0;

	if (*pr_str != '.')
	{
		return (pr_str);
		pr_str++;
	}
	if (*pr_str == '*')
	{
		d = va_arg(ap, int);
		pr_str++;
	}
	else
	{
		while (_isdigit(*pr_str))
		{
			d = d * 10 + (*pr_str - '0');
			pr_str++;
		}
	}

	pars->precision = d;
	return (pr_str);
}
