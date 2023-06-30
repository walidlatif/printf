#include "main.h"

/**
 *init_params - Initializes parameters
 *@pars: parameter structure
 *@ap: argument pointer
 *
 *Return: void
 */
void init_params(type_pars *pars, va_list ap)
{
	pars->unsign = 0;
	pars->fl_minus = 0;
	pars->fl_plus = 0;
	pars->fl_space = 0;
	pars->fl_hash = 0;
	pars->fl_zero = 0;
	pars->w_width = 0;
	pars->precision = UINT_MAX;
	pars->h = 0;
	pars->l = 0;
	(void)ap;
}
