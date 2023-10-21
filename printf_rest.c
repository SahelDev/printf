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

/**
 * print_hex - prints unsigned hex numbers in lowercase
 * @ap: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_hex(va_list ch, paramets_3 *p3, wid_per_2 *p2, flags_5 *f)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (p3->l_modif)
		l = (unsigned long)va_arg(ch, unsigned long);
	else if (p3->h_modif)
		l = (unsigned short int)va_arg(ch, unsigned int);
	else
		l = (unsigned int)va_arg(ch, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, p3,p2,f);
	if (f->flag_hashtag && l)
	{
		*--str = 'x';
		*--str = '0';
	}
	p3->unsing = 1;
	return (c += print_number(str, p3,p2,f));
}

/**
 * print_HEX - prints unsigned hex numbers in uppercase
 * @ap: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_HEX(va_list ch, paramets_3 *p3, wid_per_2 *p2, flags_5 *f)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (p3->l_modif)
		l = (unsigned long)va_arg(ch, unsigned long);
	else if (p3->h_modif)
		l = (unsigned short int)va_arg(ch, unsigned int);
	else
		l = (unsigned int)va_arg(ch, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED, p3,p2,f);
	if (f->flag_hashtag && l)
	{
		*--str = 'X';
		*--str = '0';
	}
	p3->unsing = 1;
	return (c += print_number(str, p3,p2,f));
}

/**
 * print_octal - prints unsigned octal numbers
 * @ap: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_octal(va_list ch, paramets_3 *p3, wid_per_2 *p2, flags_5 *f)
{
	unsigned long l;
	char *str;
	int c = 0;

	if (p3->l_modif)
		l = (unsigned long)va_arg(ch, unsigned long);
	else if (p3->h_modif)
		l = (unsigned short int)va_arg(ch, unsigned int);
	else
		l = (unsigned int)va_arg(ch, unsigned int);
	str = convert(l, 8, CONVERT_UNSIGNED, p3,p2,f);

	if (f->flag_hashtag && l)
		*--str = '0';
	p3->unsing = 1;
	return (c += print_number(str, p3,p2,f));
}

/**
 * print_S - custom format specifier
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_SS(va_list ch, paramets_3 *p3, wid_per_2 *p2, flags_5 *f)
{
	char *str = va_arg(ch, char *);
	char *hex;
	int sum = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = convert(*str, 16, 0, p3,p2,f);
			if (!hex[1])
				sum += _putchar('0');
			sum += _puts(hex);
		}
		else
		{
			sum += _putchar(*str);
		}
	}
	return (sum);
}

/**
 * print_rev - prints string in reverse
 * @ap: string
 * @params: the parameters struct
 *
 * Return: number bytes printed
 */
int print_rev(va_list ch, paramets_3 *p3, wid_per_2 *p2, flags_5 *f)
{
	int len, sum = 0;
	char *str = va_arg(ch, char *);
	(void)p3;
    (void)p2;
    (void)f;

	if (str)
	{
		/*for (len = 0; *str; str++)
			len++;*/
        len = _strlen(str);
		str--;
		for (; len > 0; len--, str--)
			sum += _putchar(*str);
	}
	return (sum);
}

/**
 * print_rot13 - prints string in rot13
 * @ap: string
 * @params: the parameters struct
 *
 * Return: number bytes printed
 */
int print_rot13(va_list ch, paramets_3 *p3, wid_per_2 *p2, flags_5 *f)
{
	int i, index;
	int count = 0;
	char arr[] = "NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(ch, char *);
	(void)p3;
    (void)p2;
    (void)f;

	i = 0;
	index = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
		    || (a[i] >= 'a' && a[i] <= 'z'))
		{
			index = a[i] - 65;
			count += _putchar(arr[index]);
		}
		else
			count += _putchar(a[i]);
		i++;
	}
	return (count);
}
