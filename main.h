#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024
#define BUFFER_FLUSH -1


#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define CONVERT_LOWERCASE       1
#define CONVERT_UNSIGNED        2

/**
 * struct parameters - parameters struct
 *
 * @unsign: flag if unsigned value
 *
 * @fl_plus: on if plus_flag specified
 * @fl_space: on if hashtag_flag specified
 * @fl_hash: on if _flag specified
 * @fl_zero: on if _flag specified
 * @fl_minus: on if _flag specified
 *
 * @w_width: field width specified
 * @precision: field precision specified
 *
 * @h: on if h_modifier is specified
 * @l: on if l_modifier is specified
 *
 */
typedef struct parameters
{
	unsigned int unsign	: 1;
	unsigned int fl_plus	: 1;
	unsigned int fl_space	: 1;
	unsigned int fl_hash	: 1;
	unsigned int fl_zero	: 1;
	unsigned int fl_minus	: 1;

	unsigned int w_width;
	unsigned int precision;

	unsigned int h	: 1;
	unsigned int l	: 1;
} type_pars;

/**
 * struct specifier - Struct token
 *
 * @specifier: format token
 * @f: The function associated
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, type_pars *);
} type_spfr;

int _puts(char *str);
int _putchar(int c);
int print_char(va_list ap, type_pars *pars);
int print_int(va_list ap, type_pars *pars);
int print_string(va_list ap, type_pars *pars);
int print_percent(va_list ap, type_pars *pars);
int print_S(va_list ap, type_pars *pars);
char *convert(long int num, int base, int flags, type_pars *pars);
int print_unsigned(va_list ap, type_pars *pars);
int print_address(va_list ap, type_pars *pars);
int (*get_specifier(char *s))(va_list ap, type_pars *pars);
int get_print_func(char *s, va_list ap, type_pars *pars);
int get_flag(char *s, type_pars *pars);
int get_modifier(char *s, type_pars *pars);
char *get_width(char *s, type_pars *pars, va_list ap);
int print_hex(va_list ap, type_pars *pars);
int print_HEX(va_list ap, type_pars *pars);
int print_binary(va_list ap, type_pars *pars);
int print_octal(va_list ap, type_pars *pars);
int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list ap, type_pars *pars);
int print_rot13(va_list ap, type_pars *pars);
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, type_pars *pars);
int print_number_right_shift(char *str, type_pars *pars);
int print_number_left_shift(char *str, type_pars *pars);
void init_params(type_pars *pars, va_list ap);
char *get_precision(char *p, type_pars *pars, va_list ap);
int _printf(const char *format, ...);

#endif
