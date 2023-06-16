/*
** EPITECH PROJECT, 2022
** my_putnbr_base.c
** File description:
** idzuàjàfcj
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
void my_putchar(char c);
int my_put_nbr(int nb);

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0'){
        i = i + 1;
    }
    return (i);
}

int my_putnbr_base (int nbr, char const *base)
{
    int tmp = nbr;
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
        my_putnbr_base(tmp, base);
        my_putchar(base[nbr % (my_strlen(base))]);
    }
}
