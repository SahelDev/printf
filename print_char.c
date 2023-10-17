#include "main.h"

/**
* print_char - print_char func
* @ch: the format va_list
* @p2: the parameters struct wid_per
* @f: the parameters struct flags
*
* Return: sum
*/
int print_char(va_list ch, wid_per_2 *p2, flags_5 *f)
{
	char c = va_arg(ch, int);
	int sum = 0;
	int pad = 1;

	if (f->flag_minus)
		sum += _putchar(c);

	while (pad++ < p2->width)
		sum += _putchar(' ');

	if (!f->flag_minus)
		sum += _putchar(c);

	return (sum);
}

/**
* print_string - print_string func
* @ch: the format va_list
* @p3: the parameters struct paramets
* @p2: the parameters struct wid_per
* @f: the parameters struct flags
*
* Return: sum
*/
int print_string(va_list ch, paramets_3 *p3, wid_per_2 *p2, flags_5 *f)
{
	char *str = va_arg(ch, char *), pad_char = ' ';
	int pad = 0, sum = 0, i = 0, j;

	UNUSED(p3);
	switch ((int)(!str))
		case 1:
			str = NULL_STRING;

	j = pad = _strlen(str);
	if (p2->precision < pad)
		j = pad = p2->precision;

	if (f->flag_minus)
	{
		if ((unsigned int)p2->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}

	while (j++ < p2->width)
		sum += _putchar(pad_char);

	if (!f->flag_minus)
	{
		if ((unsigned int)p2->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}

	return (sum);
}

/**
* print_percent - print_percent func
* @ch: the format va_list
* @p3: the parameters struct paramets
* @p2: the parameters struct wid_per
* @f: the parameters struct flags
*
* Return: 0 / 1
*/
int print_percent(va_list ch, paramets_3 *p3, wid_per_2 *p2, flags_5 *f)
{
	UNUSED(ch);
	UNUSED(p3);
	UNUSED(p2);
	UNUSED(f);

	return (write(1, "%%", 1));
}
