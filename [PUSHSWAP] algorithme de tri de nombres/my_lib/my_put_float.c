/*
** EPITECH PROJECT, 2022
** my_put_float.c
** File description:
** jsjojdozsqkz
*/

#include <unistd.h>
int my_compute_power_it ( int nb , int p );
void my_putchar(char c);
int my_put_long(long int nbr);

int my_put_float(double nb)
{
    long nbr = nb;
    my_put_long(nbr);
    my_putchar('.');
    if (nb < 0)
        nb = -nb;
    long dec = ((nb - (long)nb + 1) * 1000000) - 1000000;
    for (int i = 1; (long)(nb * my_compute_power_it(10, i)) % 10 == 0; i++) {
        my_putchar ('0');
    }
    my_put_long(dec);
}
