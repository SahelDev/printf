#include "main.h"
#include<stdarg.h>

/**
 * Fmt_put- prints characters
 * @str:P1
 * @len:P2
 * Return: void
 */
void Fmt_put(char *str, int len)
{
	int i;

	for (i = 0; i < len; i++)
		_putchar((unsigned char) *str++);

}
/**
 * cvt_s - format string according format specifier s
 * @app:P1
 * Return: void
 */
void convers_s(va_list app)
{
	char *str = va_arg(app, char *);

	Fmt_put(str, _strlen(str));
}
/**
 * cvt_c- prints characters according format specifier c
 * @app:P1
 * Return: void
 */
void convers_c(va_list app)
{
	_putchar((unsigned char)va_arg(app, int));
}
/**
 * cvt_d - prints characters according specifier d
 * @app:P1
 * Return: void
 */
void convers_d(va_list app)
{
	int val = va_arg(app, int);
	unsigned int m;
	char buf[43];
	char *p = buf + sizeof(buf);

	if (val == INT_MIN)
		m = INT_MAX + 1U;
	else if (val < 0)
		m = -val;
	else
		m = val;
	do
		* --p = m % 10 + '0';
	while ((m /= 10) > 0);
	if (val < 0)
		*--p = '-';
	Fmt_put(p, (buf + sizeof(buf)) - p);
}
