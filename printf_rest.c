#include "main.h"

/**
 * print_binary - prints binary number
 * @ap: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_binary(va_list ch, paramets_3 *p3, wid_per_2 *p2, flags_5 *f)
{
	unsigned int n = va_arg(ch, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGNED, p3,p2,f);
	int c = 0;

	if (f->flag_hashtag && n)
		*--str = '0';
	p3->unsing = 1;
	return (c += print_number(str, p3,p2,f));
}
