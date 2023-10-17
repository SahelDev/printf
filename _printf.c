#include "main.h"


/**
 * _printf - prints and input into the standard output
 * @format: the format string
 * Return: number of bytes printed
 */
int _printf(const char *format, ...){

    int len = 0; /* la longeur de chaine saiser */
    char *p, *start;
    flags_5 f = PARAMS_INIT_f;
    wid_per_2 p2 = PARAMS_INIT_p2;
    paramets_3 p3 = PARAMS_INIT_p3;

    va_list ch; /* notre format*/
    va_start(ch, format); /* Start the variable argument list.*/

    /* Check if the format string is empty or NULL.*/
    if(!format || (format[0] == '%' && !format[1]))
        return (-1);
    /* Check if the format string starts with two percent signs.*/
    if(format[0] == '%' && format[1] == ' ' && !format[2])
        return (-1);

    for(p = (char *)format; *p; p++){

        flags_init(&f);
        wid_per_2_init(&p2);
        paramet_3_init(&p3);

        /* on afficher les caracter*/
        if(*p != '%'){
            len += _putchar(*p);
            continue;
        }

        start = p;
        p++;

        while(flag_get(p, &f)) /*tandis que char at p est l’indicateur char*/
        {
           p++;  /* next caracter */
        }

        p = width_get(p, &p2, ch);

        p = precision_get(p, &p2, ch);

        if(modif_get(p, &p3))
            p++;

        switch (*p) {
            case 'c':
                len += _putchar(va_arg(ch, int));
                break;
            case 's':
                len += _puts(va_arg(ch, char *));
                 break;
            case '%':
                len += _putchar('%');
                break;
/*          case 'd':
                return print_int;
            case 'i':
                return print_int;
            case 'b':
                return print_binary;
            case 'u':
                return print_unsigned;
            case 'o':
                return print_octal;
            case 'x':
                return print_hex;
            case 'X':
                return print_HEX;
            case 'S':
                return print_S;
            case 'p':
                return print_address;
            case 'r':
                return print_rev;
            case 'R':
                return print_rot13;
*/
            default:
                len += to_print_from(start, p, p3.l_modif || p3.h_modif ? p - 1 : 0);
                break;
        }


    }
    _putchar(-1);
    va_end(ch);
    return (len);
}
