/*
** EPITECH PROJECT, 2022
** my_nbr_min.c
** File description:
** returns minimal between a and b;
*/

#include "../../include/my.h"

/////////////////////////////////////////
// Returns minimal between a and b;
///\param a First number to compare
///\param b Second number to compare
///\return 1 if true, 0 if false
/////////////////////////////////////////
int my_nbr_min(int a, int b)
{
    if (a < b) {
        return (a);
    } else {
        return (b);
    }
}
