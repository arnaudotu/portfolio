/*
** EPITECH PROJECT, 2022
** my_put_long.c
** File description:
** euytryeuizok
*/

#include "../include/my.h"

int my_put_long(long int nbr)
{
    long int e;

    if (nbr < 0){
        nbr = -nbr;
        my_putchar('-');
    }

    if (nbr > 9) {
        my_putnbr(nbr / 10);
    }
    e = nbr % 10 + 48;
    my_putchar(e);
    return 0;
}
