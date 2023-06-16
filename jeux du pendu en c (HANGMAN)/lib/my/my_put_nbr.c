/*
** EPITECH PROJECT, 2022
** task01
** File description:
** my_strncpy.c
*/

void my_putchar(char c);
int my_put_nbr(int nb)
{
    if (nb == -2147483648) {
            my_putchar('-');
            my_putchar('2');
            nb = 147483648;
    }
    if (nb < 0 && nb >= -2147483648) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb <= 9) {
        my_putchar(nb + 48);
    }
    if (nb >= 10 && nb <= 2147583648) {
        my_put_nbr(nb / 10);
        my_putchar((nb % 10) + 48);
    }
}
