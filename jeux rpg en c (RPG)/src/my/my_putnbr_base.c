/*
** EPITECH PROJECT, 2022
** my_putnbr_base.c
** File description:
** writes a int of a certain base on the terminal
*/

#include "../../include/my.h"

/////////////////////////////////////////
// Writes a float on the terminal
///\param f Float to write
///\param dec Number of decimals to write
/////////////////////////////////////////
void my_putnbr_base(int nbr, char *base)
{
    if (nbr < 0) {
        my_putchar('-');
        nbr = -nbr;
    }
    if (nbr < my_strlen(base)) {
        my_putchar(base[nbr]);
    }
    if (nbr >= my_strlen(base)) {
        my_putnbr_base(nbr / (my_strlen(base)), base);
        my_putchar(base[nbr % (my_strlen(base))]);
    }
}
