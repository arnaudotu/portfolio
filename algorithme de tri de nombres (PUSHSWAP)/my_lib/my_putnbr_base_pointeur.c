/*
** EPITECH PROJECT, 2022
** my_putnbr_base_pointeur.c
** File description:
** oceiuoicdze
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
void my_putchar(char c);
int my_put_nbr(int nb);
int my_strlen(char const *str);

int my_putnbr_base_pointeur (long long nbr, char const *base)
{
    long long tmp = nbr;
    if (nbr < 0){
        my_putchar('-');
        nbr = nbr * (-1);
    }
    if (nbr < my_strlen(base)) {
        my_putchar(base[nbr]);
        return (0);
    }
    if (nbr >= my_strlen(base)){
        tmp = nbr / my_strlen(base);
        my_putnbr_base_pointeur(tmp, base);
        my_putchar(base[nbr % (my_strlen(base))]);
    }
}
