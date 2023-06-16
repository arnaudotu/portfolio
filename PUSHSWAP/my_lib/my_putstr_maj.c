/*
** EPITECH PROJECT, 2022
** my_putstr_MAJ.c
** File description:
** uzyuqpçudça
*/

#include <unistd.h>
int my_putnbr_base (int nbr, char const *base);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);

int val(char const *str, int i)
{
    if (str[i] >= 0)
    if (str[i] < 7)
        my_putstr("00");
    if (str[i] >= 8 && str[i] < 64){
        my_putchar('0');
    }
}

int my_putstr_maj(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] > 32 && str[i] <= 127){
            my_putchar(str[i]);
        } else {
            my_putchar('\\');
            val(str, i);
            my_putnbr_base(str[i], "01234567");
        }
    }
}
