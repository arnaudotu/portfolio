/*
** EPITECH PROJECT, 2022
** my_is_str_in_array.c
** File description:
** Checks an array to see if there is a specific string
*/

#include "../../include/my.h"

/////////////////////////////////////////
// Checks an array to see if there is a specific string
///\param tab Array to check
///\param str String to compare
///\return 1 if true, 0 if false
/////////////////////////////////////////
int my_is_str_in_array(char **tab, char *str)
{
    for (int i = 0; tab[i] != NULL; i++) {
        if (!my_strcmp(tab[i], str)) {
            return (1);
        }
    }
    return (0);
}
