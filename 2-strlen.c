#include "main.h"
/**
 *_strlen - returns the length of a string
 *@s: parameter
 *Return: length of a string
 */

int _strlen(char *s)
{
	char *p = s;

	while (*p != '\0')
		p++;

	return (p - s);
}
