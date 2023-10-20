#include "main.h"
#include<stdarg.h>
#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<unistd.h>
#include<ctype.h>


/**
 * Fmt_vfmt- formats arguments pointed to by ap\
 * according to fmt
 * @fmt:format string
 * @ap:argument list
 * Return: the number of characters printed
 */

int Format_f(char *fmt, va_list ap)
{
	int n = 0;

	while (*fmt)
	{
		if (*fmt != '%' || *++fmt == '%')
			_putchar((unsigned char) *fmt++);
		else
		{
			unsigned char c;

			if (*fmt == '*' || _isdigit(*fmt))
				function1(fmt, ap);
			if (*fmt == '.' && (*++fmt == '*' || _isdigit(*fmt)))
				function2(fmt, ap);
			c = *fmt++;
			if (c == 'c')
				convers_c(ap);
			if (c == 'd')
				convers_d(ap);
			if (c == 'i')
				convers_d(ap);
			if (c == 's')
				convers_s(ap);
		}
		n++;
	}
	return (n);
}
