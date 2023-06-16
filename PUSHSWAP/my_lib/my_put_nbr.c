/*
** EPITECH PROJECT, 2022
** my_put_nbr.c
** File description:
** 3
*/

#include <unistd.h>
void *my_putchar(char c);

int my_putnbr(int nb)
{
    int n;

    if (nb < 0){
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 0){
        if (nb >= 10){
            n = (nb % 10);
            nb = (nb - n) / 10;
            my_putnbr(nb);
            my_putchar(48 + n);
        } else {
            my_putchar(48 + nb % 10);
        }
    }
    return (0);
}
