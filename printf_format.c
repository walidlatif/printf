#include "main.h"

/**
 *get_specifier - Retrieves the format function
 *@s: the format string
 *
 *Return: A pointer to the format function
 */

int (*get_specifier(char *s))(va_list ap, type_pars * pars)
{
	type_spfr specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}


/**
 *get_print_func - Locates the format function
 *@s: The format string
 *@ap: Argument pointer
 *@pars: The parameters struct
 *
 *Return: The number of bytes printed
 */
int get_print_func(char *s, va_list ap, type_pars *pars)
{
	int (*f)(va_list, type_pars *) = get_specifier(s);

	if (f)
		return (f(ap, pars));
	return (0);
}

/**
 *get_flag - Locates the flag function
 *@s: The format string
 *@pars: The parameters struct
 *Return: Whether the flag was valid
 */

int get_flag(char *s, type_pars *pars)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = pars->fl_plus = 1;
			break;
		case ' ':
			i = pars->fl_space = 1;
			break;
		case '#':
			i = pars->fl_hash = 1;
			break;
		case '-':
			i = pars->fl_minus = 1;
			break;
		case '0':
			i = pars->fl_zero = 1;
			break;
	}
	return (i);
}

/**
 *get_modifier - Locates the modifier function
 *@s: the format string
 *@pars: the parameters struct
 *
 *Return: Whether the modifier was valid
 */
int get_modifier(char *s, type_pars *pars)
{
	int i = 0;

	switch (*s)
	{
		case 'h':
			i = pars->h = 1;
			break;
		case 'l':
			i = pars->l = 1;
			break;
	}
	return (i);
}


/**
 *get_width - retrieves the width from the format string
 *@s: The format string
 *@pars: The parameters struct
 *@ap: The argument pointer
 *
 *Return: new pointer
 */

char *get_width(char *s, type_pars *pars, va_list ap)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	pars->w_width = d;
	return (s);
}

