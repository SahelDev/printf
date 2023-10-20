#include "main.h"

/**
<<<<<<< HEAD
* get_flag - finds the flag func
* @s: the format string
* @params: the parameters struct
=======
* flag_get - finds the flag func
* @s: the format string
* @f: the parameters struct
>>>>>>> e52428ea93381160201d14c858a9df0db84860a9
*
* Return: if flag was valid
*/
int flag_get(char *s, flags_5 *f)
{
<<<<<<< HEAD
	/* Check if the current character is a flag character.*/
	switch (*s)
	{
	case '+':
		f->flag_plus = 1;
		return (1);
	case ' ':
		f->flag_space = 1;
		return (1);
	case '#':
		f->flag_hashtag = 1;
		return (1);
	case '0':
		f->flag_zero = 1;
		return (1);
	case '-':
		f->flag_minus = 1;
		return (1);

	default:
	return (0);
	}
}
=======
	switch (*s)
	{
		case '+':
			f->flag_plus = 1;
			return (1);
		case ' ':
			f->flag_space = 1;
			return (1);
		case '#':
			f->flag_hashtag = 1;
			return (1);
		case '0':
			f->flag_zero = 1;
			return (1);
		case '-':
			f->flag_minus = 1;
			return (1);

	default:

	return (0);
	}
}

>>>>>>> e52428ea93381160201d14c858a9df0db84860a9
/**
* width_get - gets the width
* @s: the format string
* @p2: the parameters struct
* @ch: the argument pointer
*
* Return: new pointer
*/
char *width_get(char *s,  wid_per_2 *p2, va_list ch)
{
<<<<<<< HEAD
	/* Vérifiez si le caractère actuel est un spécificateur de largeur.*/
	if (*s == '*')
	{/*La largeur est un argument variable.*/
=======
	if (*s == '*')
	{
>>>>>>> e52428ea93381160201d14c858a9df0db84860a9
		p2->width = va_arg(ch, int);
		s++;
	} else
	{
<<<<<<< HEAD
		/*La largeur est une valeur littérale.*/
=======
>>>>>>> e52428ea93381160201d14c858a9df0db84860a9
		int d = 0;

		while ((*s) >= '0' && (*s) <= '9')
			d = d * 10 + (*s++ - '0');
<<<<<<< HEAD
		p2->width = d;
	}
	return (s);
}
/**
* precision_get - gets the precision from the format string
* @p: the format string
* @p3: the parameters struct
* @ap: the argument pointer
=======

		p2->width = d;
	}
return (s);
}


/**
* precision_get - gets the precision from the format string
* @p: the format string
* @ap: the argument pointer
*
>>>>>>> e52428ea93381160201d14c858a9df0db84860a9
* Return: new pointer
*/
char *precision_get(char *p, wid_per_2 *p2, va_list ap)
{
	int d = 0;

	if (*p != '.')
		return (p);
<<<<<<< HEAD
	p++;
=======

	p++;

>>>>>>> e52428ea93381160201d14c858a9df0db84860a9
	if (*p == '*')
	{
		p2->precision = va_arg(ap, int);
		p++;
	}
	else
	{
		while ((*p) >= '0' && (*p) <= '9')
			d = d * 10 + (*p++ - '0');
<<<<<<< HEAD
		p2->precision = d;
	}
	return (p);
}
=======

		p2->precision = d;
	}

	return (p);
}

>>>>>>> e52428ea93381160201d14c858a9df0db84860a9
/**
* modif_get - finds the modifier func
* @s: the format string
* @p3: the parameters struct
*
* Return: if modifier was valid
*/
int modif_get(char *s, paramets_3 *p3)
{
	switch (*s)
	{
<<<<<<< HEAD
	case 'h':
		p3->h_modif = -1;
		return (1);
	case 'l':
		p3->l_modif = -1;
		return (1);
	default:
		return (0);
=======
		case 'h':
			p3->h_modif = -1;
			return (1);
		case 'l':
			p3->l_modif = -1;
			return (1);

		default:
			return (0);
>>>>>>> e52428ea93381160201d14c858a9df0db84860a9
	}
}
