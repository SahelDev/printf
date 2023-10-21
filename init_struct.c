#include "main.h"
/**
* flags_init - clears struct fields and reset buf
* @par: the parameters struct
*
* Return: void
*/
void flags_init(flags_5 *par)
{
	par->flag_plus = 0;
	par->flag_space = 0;
	par->flag_hashtag = 0;
	par->flag_zero = 0;
	par->flag_minus = 0;
}
/**
* wid_per_2_init - clears struct fields and reset buf
* @par: the parameters struct
*
* Return: void
*/
void wid_per_2_init(wid_per_2 *par)
{
	par->width = 0;
	par->precision = UINT_MAX;/*UINT_MAX;*/
}
/**
* paramet_3_init - clears struct fields and reset buf
* @par: the parameters struct
*
* Return: void
*/
void paramet_3_init(paramets_3 *par)
{
	par->unsing = 0;
	par->h_modif = 0;
	par->l_modif = 0;
}
