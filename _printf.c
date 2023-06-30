#include "main.h"

/**
 * _printf - prints anything
 * @format: the format string
 *
 * Return: number of bytes printed
 */
int _printf(const char *format, ...)
{
	int sum = 0;
	va_list ap;
	char *p, *start;
	type_pars pars = PARAMS_INIT;

	va_start(ap, format);

	if (format == NULL || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_params(&pars, ap);
		if (*p != '%')
		{
			sum += _putchar(*p);
			continue;
	}
	start = p;
	p++;
	while (get_flag(p, &pars))
	{
		p++;
	}
	p = get_width(p, &pars, ap);
	p = get_precision(p, &pars, ap);
	if (get_modifier(p, &pars))
		p++;
	if (!get_specifier(p))
		sum += print_from_to(start, p,
				pars.l || pars.h ? p - 1 : 0);
	else
		sum += get_print_func(p, ap, &pars);
}
_putchar(BUFFER_FLUSH);
va_end(ap);
return (sum);
}
