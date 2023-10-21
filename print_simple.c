#include "main.h"

/**
 * _puts - prints a string to stdout
 * @str: pointer to the string to print
 *
 */
int _puts(char *str)
{
	char *a = str;

	while (*str)
		_putchar(*str++);
	return (str - a);
}

/**
* _strlen - returns the length of a string
* @s: the string whose length to check
*
* Return: integer length of string
*/
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
* to_print_from prints a range of char addresses
* @start: starting address
* @stop: stopping address
* @except: except address
*
*Return: number bytes printed
*/
int to_print_from(char *start, char *stop, char *except)
{
	int sum = 0;

	while (start <= stop)
	{
		if (start != except)
			sum += _putchar(*start);
		start++;
	}
	return (sum);
}
