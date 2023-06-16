/*
** EPITECH PROJECT, 2022
** my_int_to_binary.c
** File description:
** returns the binary of a decimal n
*/

#include "../../include/my.h"

/////////////////////////////////////////
// Returns the binary of a decimal n
///\param n Decimal number
///\return Binary number
/////////////////////////////////////////
int my_int_to_binary(int n)
{
    if (n == 0) {
        return (0);
    }
    return ((n % 2) + (10 * my_int_to_binary(n / 2)));
}
