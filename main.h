#ifndef FORMAT_H
#define FORMAT_H

#include<stdarg.h>
#include<limits.h>



int Format_f(char *fmt, va_list ap);
int _printf(char *fmt, ...);
void Fmt_put(char *str, int len);
int _isdigit(int c);
int _strlen(char *c);
int _putchar(char c);
void convers_d(va_list app);
void convers_s(va_list app);
void convers_c(va_list app);
void function1(char *fmt, va_list ap);
void function2(char *fmt, va_list ap);



#endif
