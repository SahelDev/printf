#include "main.h"
/*
int print_char(va_list ch, paramets_3 *p3, wid_per_2 *p2, flags_5 *f) {

    char c = va_arg(ch, int);
    int pad_width = p2->width - 1;
    int pad_char = ' ';
    int sum = 0;
    (void)p3;

    if (f->flag_minus) {
        sum += _putchar(c);
        while (pad_width--) {
        sum += _putchar(pad_char);
        }
    } else {
        while (pad_width--) {
        sum += _putchar(pad_char);
        }
        sum += _putchar(c);
    }

    return sum;
}



int print_string(va_list ch, paramets_3 *p3, wid_per_2 *p2, flags_5 *f) {
  
    char *str = va_arg(ch, char *);
    char pad_char = ' ';
    int pad = 0;
    int sum = 0;
    
    if (p2->width > _strlen(str)) {
        pad = p2->width - _strlen(str);
    }

    if (!f->flag_minus) {
        while (pad--) {
        sum += _putchar(pad_char);
        }
    }

    if (p2->precision != UINT_MAX) {
        for (int i = 0; i < p2->precision; i++) {
            sum += _putchar(*str++);
        }
    } else {
        sum += _puts(str);
    }

    if (f->flag_minus) {
        while (pad--) {
        sum += _putchar(pad_char);
        }
    }

    return sum;
}


int print_percent(va_list ch, paramets_3 *p3, wid_per_2 *p2, flags_5 *f){

    return (_putchar('%'));
}

*/