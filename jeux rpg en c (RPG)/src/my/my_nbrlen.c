/*
** EPITECH PROJECT, 2022
** my_arraylen.c
** File description:
** returns number length
*/

#include "../../include/my.h"

/////////////////////////////////////////
// Returns a number's length;
///\param n Number to check
///\return Number of numbers in n
/////////////////////////////////////////
int my_nbrlen(int n)
{
    if (n < 0) {
        n = -n;
    }
    if (n <= 9) {
        return (1);
    }
    int len = 0;
    int verif = 1;
    while (verif <= n) {
        verif = verif * 10;
        len++;
    }
    return (len);
}
