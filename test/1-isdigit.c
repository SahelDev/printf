#include "main.h"
#include<stdio.h>

/**
 * _isdigit - checks for a digit
 * @c: parameter 1
 * Return: 1 if c is a digit otherwise
 *
 */
int _isdigit(int c)
{
	int j;

	for (j = 48; j <= 57; j++)
		if (j == c)
			return (1);
	return (0);
}
