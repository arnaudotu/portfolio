/*
** EPITECH PROJECT, 2022
** my_put_nbrbase
** File description:
** writes a int of a certain base on the terminal
*/

#include "../include/my.h"

void my_put_nbr_base(int nbr, char *base)
{
    if (nbr < 0) {
        my_put_char('-');
        nbr = -nbr;
    }
    if (nbr < my_strlen(base)) {
        my_put_char(base[nbr]);
    }
    if (nbr >= my_strlen(base)) {
        my_put_nbr_base(nbr / (my_strlen(base)), base);
        my_put_char(base[nbr % (my_strlen(base))]);
    }
}
