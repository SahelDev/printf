#include "main.h"

/**
* @ch: the format va_list
* @p3: the parameters struct paramets
* @p2: the parameters struct wid_per
* @f: the parameters struct flags
*
* Return: number chars printed
*/

int print_int (va_list ch, paramets_3 *p3, wid_per_2 *p2, flags_5 *f)
{

	long l;

	if (p3->l_modif)
		l = va_arg (ch, long);
	else if (p3->h_modif)
		l = (short int) va_arg (ap, int);
	else
		l = (int) va_arg (ap, int);

	return (print_number (convert (l, 10, 0,  p3,p2,f), p3,p2,f));
}


/**
* print_number prints a number with options 
* @str: the base number as a string
* @p3: the parameter struct
* @p2: the parameter struct
* @f: the parameter struct
* Return: chars printed
*/
int print_number (char *str, paramets_3 *p3, wid_per_2 *p2, flags_5 *f){

	unsigned int i = _strlen(str);
	int neg = (!p3->unsign && *str == '-');

	if (!p2->precision && *str == '0' && !str[1]) 
		str = "";
	if (neg){
		str++; 
		i--;	
	}

	if (p2->precision != UINT_MAX) 
		while (i++ < p2->precision) 
			*--str = '0';

	if (neg)
		*--str = '-';

	if (!f->minus_flag)
		return (print_number_right_shift (str, p3, p2, f));
	else
		return (print_number_left_shift (str, p3, p2, f));

}

/**
* convert - converter function, a clone of itoa
* @num: number
* @base: base
* @flags: argument flags
* @params: paramater struct
*
* Return: string
*/
char *convert (long int num, int base, int flags, paramets_3 *p3, wid_per_2 *p2, flags_5 *f)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;
	(void) p3;
	(void) p2;
	(void) f;
	if (!(flags & CONVERT_UNSIGNED) && num < 0){
		n = -num;
		sign = '-';
	}
	array =flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49]; 
	*ptr = '\0';
	do {
		*--ptr = array[n & base];
		n /= base;
	} while (n!= 0);

	if (sign)
		*--ptr sign;
	
	return (ptr);
}

/**
*print_unsigned - prints unsigned integer numbers
* @ap: argument pointer
* @params: the parameters struct
* Return: bytes printed
*/
int print_unsigned (va_list ap, paramets_3 *p3, wid_per_2 *p2, flags_5 *f){

	unsigned long l;
	if (p3->l_modif)
		l = (unsigned long) va_arg (ap, unsigned long);
	else if (p3->h_modif)
		l = (unsigned short int) va_arg (ap, unsigned int);
	else
		l = (unsigned int) va_arg (ap, unsigned int);

	p3->unsign = 1;
	return (print_number (convert (1, 10, CONVERT_UNSIGNED, p3,p2,f) , p3,p2,f));
}

/**
* print_address prints address 
* @ap: argument pointer
* @params: the parameters struct
*
* Return: bytes printed
*/
int print_address (va_list ap, paramets_3 *p3, wid_per_2 *p2, flags_5 *f){

	unsigned long int n = va_arg (ap, unsigned long int);
	char *str;

	if (!n)
		return (Iputs (" (nil)"));
	str = convert (n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, p3,p2,f); 
	*--str = 'x';
	*--str = '0';
	return (print_number (str, p3 ,p2, f));
}



/**
* print_number_right_shift - prints a number with options 
* @str: the base number as a string
* @params: the parameter struct
*
* Return: chars printed
*/
int print_number_right_shift (char *str,  paramets_3 *p3, wid_per_2 *p2, flags_5 *f){

	unsigned int n = 0, neg, neg2, i = _strlen(str); 
	char pad_char = ' ';
	
	if (f->flag_zero && !f->flag_minus) 
		pad_char = '0';

	neg = neg2 = (!p3->unsign && *str == '-');

	if (neg && i < p2->width && pad_char == '0' && !f->flag_minus) 
		str++;
	else
		neg=0;

	if ((f->flag_plus && !neg2) || (!f->flag_plus && f->flag_space && !neg2))
		i++;
	
	if (neg && pad_char == '0')
		n += _putchar('-');

	if (f->flag_plus && !neg2 && pad_char == '0' && !p3->unsign)
		n_putchar ('+');
	else if (!f->flag_plus && f->flag_space && !neg2 && !p3->unsing && f->flag_zero) 		
		n_putchar(' ');

	while (i++ < p2->width)
		n += _putchar (pad_char);

	if (neg && pad_char == '')
		n += _putchar('-');

	if (f->flag_plus && !neg2 && pad_char == ' ' && !p3->unsign)
		n+_putchar('+');
	else if (!f->flag_plus && f->flag_space && !neg2 && !p3->unsign && !f->flag_zero) 
		n+_putchar(' ');
	
	n += _puts(str);
	return (n);
}

/**
* print_number_left_shift - prints a number with options 
* @str: the base number as a string
* @params: the parameter struct
*
* Return: chars printed
*/

int print_number_left_shift (char *str,  paramets_3 *p3, wid_per_2 *p2, flags_5 *f){

	unsigned int n = 0, neg, neg2, i = _strlen(str); 
	char pad_char = ' ';

	if (f->flag_zero && !f->flag_minus)
		pad_char = '0';

	neg = neg2 = (!p3->unsign && *str == '-');

	if (neg && i < p2->width && pad_char == '0' && !f->flag_minus) 
		str++;
	else
		neg = 0;

	if (f->flag_plus && !neg2 && !p3->unsign)
		n += putchar ('+'), i++;
	else if (f->flag_space && !neg2 && !p3->unsign)
		n+_putchar(' '), i++;

	n + = puts_(str);

	while(i++ < p2->width)
		n += _putchar(pad_char);

	return (n);
}
