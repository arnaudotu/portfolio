/*
** EPITECH PROJECT, 2022
** my_binary_to_nbr.c
** File description:
** returns the decimal of a binary n
*/

#include "../../include/my.h"

/////////////////////////////////////////
// Returns the decimal of a binary
///\param n Binary number
///\return Decimal equivalent of the binary
/////////////////////////////////////////
int my_binary_to_nbr(int n)
{
    if (n == 0) {
        return (0);
    }
    if (n == 1) {
        return (1);
    }
    return (n % 10 + 2 * my_binary_to_nbr(n / 10));
}
