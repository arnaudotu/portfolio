/*
** EPITECH PROJECT, 2022
** my_putnbr_u.c
** File description:
** pzedpijcfr
*/

#include <unistd.h>
void my_putchar(char c);

int my_putnbr_u(unsigned int nb)
{
    unsigned int n;
    if (nb >= 0){
        if (nb >= 10){
            n = (nb % 10);
            nb = (nb - n) / 10;
            my_putnbr_u(nb);
            my_putchar(48 + n);
        } else {
            my_putchar(48 + nb % 10);
        }
    }
    return (0);
}
