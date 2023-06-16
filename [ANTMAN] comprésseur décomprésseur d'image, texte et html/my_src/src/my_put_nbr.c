/*
** EPITECH PROJECT, 2022
** my_put_char
** File description:
** writes a int on the terminal
*/

#include "../include/my.h"

void my_put_nbr(int n)
{
    if (n < 0 && n >= -2147483647) {
        my_put_char('-');
        n = -n;
    }
    if (n <= 9) {
        my_put_char(n + 48);
    }
    if (n >= 10 && n <= 2147483647) {
        my_put_nbr(n / 10);
        my_put_char((n % 10) + 48);
    }
}
