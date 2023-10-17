#ifndef _PRINTf_H
#define _PRINTf_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

#define PARAMS_INIT_f {0,0,0,0,0}
#define PARAMS_INIT_p2 {0,0}
#define PARAMS_INIT_p3 {0,0,0}

/**
* struct parameters --> flags { '+'  ' '  '#'  '0'  '-' }
* @plus_flag: on if plus_falg specified
* @space_flag: on if space_flag specified
* @hashtag_flag: on if hashtag_flag specified
* @zero_flag: on if zero_flag specified
* @minus_flag: on if minus_flag specified
* 
* struct
*/
typedef struct flags{
    int flag_plus;
	int flag_space;
	int flag_hashtag;
	int flag_zero;
	int flag_minus;	
} flags_5;

/**
* struct parameters --> width and precision
* @width: field width specified
* @precision: field percision specified
*
*/
typedef struct wid_per{
    int width;
	int precision;
} wid_per_2;

/**
* struct parameters --> unsigned and length(l, h)
*
* @unsing: flag if unsigned value
* 
* @h_modif: on if h_modifier is specified
* @l_modif: on if l_modifier is specified
*
*/
typedef struct paramets{
	int unsing 			:1;
    int h_modif 	    :1;
	int l_modif 	    :1;
} paramets_3;

/**
* struct specifier --> struct token
*
* @specifier: format token
* @f: the function associated
*/
typedef struct specifier{
	char *specifier;
	int (*f)(va_list, flags_5 *, wid_per_2 *, paramets_3 *);
} specifier_15;

/* init_struct.c module */
void flags_init(flags_5 *par);
void wid_per_2_init(wid_per_2 *par);
void paramet_3_init(paramets_3 *par);

/* vr_format.c*/
int flag_get(char *s, flags_5 *f);
char *width_get(char *s,  wid_per_2*p2, va_list ch);
char *precision_get(char *p, wid_per_2 *p2, va_list ch);
int modif_get(char *s, paramets_3 *p3);

/* print_simple.c*/
int _strlen(char *s);
int to_print_from(char *start, char *stop, char *except);
int _putchar(char c);
int _puts(char *str);

/* _printf.c module */
int _printf(const char *format, ...);



#endif
