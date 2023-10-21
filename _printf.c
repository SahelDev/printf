#include "main.h"

/**
 * _printf - prints and input into the standard output
 * @format: the format string
 * Return: number of bytes printed
 */
int _printf(const char *format, ...)
{
	int len = 0;
	char *p, *start;
	flags_5 f;
	wid_per_2 p2;
	paramets_3 p3;
	va_list ch;
	va_start(ch, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);

	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	for (p = (char *)format; *p; p++)
	{
		flags_init(&f);
		wid_per_2_init(&p2);
		paramet_3_init(&p3);

		if (*p != '%')
		{
		  len += _putchar(*p);
		  continue;
		}
		start = p;
		p++;

		while (flag_get(p, &f))
		{
			p++;
		}

		p = width_get(p, &p2, ch);

		p = precision_get(p, &p2, ch);

		if (modif_get(p, &p3))
			p++;

	switch (*p)
	{
		case 'c':
			len += print_char(ch, &p2, &f);
			break;
		case 's':
			len += print_string(ch, &p3, &p2, &f);
			break;
		case '%':
			len += print_percent(ch, &p3, &p2, &f);
			break;
		case 'd':
			len += print_int(ch, &p3, &p2, &f);
			break;
		case 'i':
			len += print_int(ch, &p3, &p2, &f);
			break;
	case 'd':
	  len+= int print_unsigned(ch, &p3, &p2, &f);
	  break;
		default:
			len += to_print_from(start, p, p3.l_modif || p3.h_modif ? p - 1 : 0);
			break;
	}

    }

	/*_putchar(-1);*/
	va_end(ch);

	return (len);
}
