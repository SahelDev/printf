#include "main.h"


/**
 * _printf - function that produces output according to a format
 * @fmt: format string
 * Return: the number of characters printed
 */

int _printf(char *fmt, ...)
{
	int n;
	va_list ap;

	va_start(ap, fmt);
	n = Format_f(fmt, ap);
	return (n);
	va_end(ap);
}
