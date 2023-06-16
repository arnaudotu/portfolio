/*
** EPITECH PROJECT, 2022
** my_put_char
** File description:
** writes a float on the terminal
*/

#include "../include/my.h"

void my_put_float(float f, int dec)
{
    if (f < 0) {
        my_put_char('-');
        f = f * -1;
    }
    my_put_nbr((int)f);
    if (dec >= 1) {
        my_put_char('.');
        my_put_nbr((int)((f - (float)((int)f)) * my_nbr_power(10, dec)));
    }
}
