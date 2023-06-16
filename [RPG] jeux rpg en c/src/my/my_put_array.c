/*
** EPITECH PROJECT, 2022
** my_put_array.c
** File description:
** writes an array on the terminal using sep as separator and end at the end
*/

#include "../../include/my.h"

/////////////////////////////////////////
// Writes an array on the terminal
///\param tab Array to write
///\param sep String to write between the array's elements
///\param end String to write after the last element of the array
/////////////////////////////////////////
void my_put_array(char **tab, char *sep, char *end)
{
    for (int i = 0; tab[i] != NULL; i++){
        my_putstr(tab[i]);
        if (tab[i + 1] != NULL)
            my_putstr(sep);
    }
    my_putstr(end);
}
