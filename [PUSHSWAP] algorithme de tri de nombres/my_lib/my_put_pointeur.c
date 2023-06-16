/*
** EPITECH PROJECT, 2022
** my_put_pointeur.c
** File description:
** hfjftiuyuidugd
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
void my_putchar(char c);
int my_put_nbr(int nb);
int my_strlen(char const *str);
int my_putnbr_base_pointeur (long long nbr, char const *base);
int my_putstr(char const *str);

int my_put_pointeur(long long p)
{
    my_putstr("0x");
    my_putnbr_base_pointeur(p, "0123456789abcdef");
}
