/*
** EPITECH PROJECT, 2022
** my_nbr_max.c
** File description:
** returns maximal between a and b;
*/

#include "../../include/my.h"

/////////////////////////////////////////
// Returns maximal between a and b;
///\param a First number to compare
///\param b Second number to compare
///\return 1 if true, 0 if false
/////////////////////////////////////////
int my_nbr_max(int a, int b)
{
    if (a > b) {
        return (a);
    } else {
        return (b);
    }
}
