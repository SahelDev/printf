#include"main.h"


/**
 * function1 - helper1
 * @fmt:P1
 * @ap:P2
 * Return: void
 */

void function1(char *fmt, va_list ap)
{
				int n;

				if (*fmt == '*')
				{
					n = va_arg(ap, int);
					fmt++;
				}
				else
					for (n = 0; _isdigit(*fmt); fmt++)
					{
						int d = *fmt - '0';

						n = 10 * n + d;
					}
}
/**
 * function2 - helper2
 * @fmt:P1
 * @ap:P2
 * Return: void
 */
void function2(char *fmt, va_list ap)

{
				int n;

				if (*fmt == '*')
				{
					n = va_arg(ap, int);
					fmt++;
				}
				else
					for (n = 0; _isdigit(*fmt); fmt++)
					{
						int d = *fmt - '0';

						n = 10 * n + d;
					}
}

