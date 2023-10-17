#ifndef _PRINTf_H
#define _PRINTf_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

#define UNUSED(x) (void)(x)
#define NULL_STRING "(null)"

/**
* struct flags - struct for { '+'  ' '  '#'  '0'  '-' }
* @flag_plus: on if plus_falg specified
* @flag_space: on if space_flag specified
* @flag_hashtag: on if hashtag_flag specified
* @flag_zero: on if zero_flag specified
* @flag_minus: on if minus_flag specified
*/
typedef struct flags
{
	int flag_plus;
	int flag_space;
	int flag_hashtag;
	int flag_zero;
	int flag_minus;
} flags_5;

/**
* struct wid_per - parameters --> width and precision
* @width: field width specified
* @precision: field percision specified
*
*/
typedef struct wid_per
{
	int width;
	int precision;
} wid_per_2;

/**
* struct paramets - parameters --> unsigned and length(l, h)
*
* @unsing: flag if unsigned value
*
* @h_modif: on if h_modifier is specified
* @l_modif: on if l_modifier is specified
*
*/
typedef struct paramets
{
	int unsing;
	int h_modif;
	int l_modif;
} paramets_3;

/* init_struct.c module */
void flags_init(flags_5 *par);
void wid_per_2_init(wid_per_2 *par);
void paramet_3_init(paramets_3 *par);

/* vr_format.c*/
int flag_get(char *s, flags_5 *f);
char *width_get(char *s,  wid_per_2 *p2, va_list ch);
char *precision_get(char *p, wid_per_2 *p2, va_list ch);
int modif_get(char *s, paramets_3 *p3);

/* print_simple.c*/
int _strlen(char *s);
int to_print_from(char *start, char *stop, char *except);
int _putchar(char c);
int _puts(char *str);

/* _printf.c module */
int _printf(const char *format, ...);

/* print_simple.c */
int print_char(va_list ch, wid_per_2 *p2, flags_5 *f);
int print_percent(va_list ch, paramets_3 *p3, wid_per_2 *p2, flags_5 *f);
int print_string(va_list ch, paramets_3 *p3, wid_per_2 *p2, flags_5 *f);

#endif
