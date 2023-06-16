/*
** EPITECH PROJECT, 2022
** my_is_file.c
** File description:
** Checks if a number is between min and max
*/

#include "../../include/my.h"

/////////////////////////////////////////
// Checks if a number is between two numbers
///\param n Decimal number
///\param min Minimum value
///\param max Maximum value
///\return 1 if true, 0 if false
/////////////////////////////////////////
int my_is_between(int n, int min, int max)
{
    if (min <= n && n <= max) {
        return (1);
    }
    return (0);
}
