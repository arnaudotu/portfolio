/*
** EPITECH PROJECT, 2022
** my_putnbr.c
** File description:
** writes a int on the terminal
*/

#include "../../include/my.h"

/////////////////////////////////////////
// Writes a number on the terminal
///\param n Number to write
/////////////////////////////////////////
void my_putnbr(int n)
{
    if (n < 0 && n >= -2147483647) {
        my_putchar('-');
        n = -n;
    }
    if (n <= 9) {
        my_putchar(n + 48);
    }
    if (n >= 10 && n <= 2147483647) {
        my_putnbr(n / 10);
        my_putchar((n % 10) + 48);
    }
}
