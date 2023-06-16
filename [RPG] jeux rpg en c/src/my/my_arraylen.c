/*
** EPITECH PROJECT, 2022
** my_arraylen.c
** File description:
** returns array length
*/

#include "../../include/my.h"

/////////////////////////////////////////
// Returns the number of elements in an array
///\param tab Array to check
///\return Number of elements
/////////////////////////////////////////
int my_arraylen(char **tab)
{
    int n = 0;
    while (tab[n] != NULL) {
        n++;
    }
    return (n);
}
