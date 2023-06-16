/*
** EPITECH PROJECT, 2022
** my_putfloat.c
** File description:
** writes a float on the terminal
*/

#include "../../include/my.h"

/////////////////////////////////////////
// Writes a float on the terminal
///\param f Float to write
///\param dec Number of decimals to write
/////////////////////////////////////////
void my_putfloat(float f, int dec)
{
    if (f < 0) {
        my_putchar('-');
        f = f * -1;
    }
    my_putnbr((int)f);
    if (dec >= 1) {
        my_putchar('.');
        my_putnbr((int)((f - (float)((int)f)) * my_nbr_power(10, dec)));
    }
}
