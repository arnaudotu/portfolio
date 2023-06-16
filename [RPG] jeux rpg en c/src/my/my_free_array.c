/*
** EPITECH PROJECT, 2022
** my_free_array.c
** File description:
** free an array
*/

#include "../../include/my.h"

/////////////////////////////////////////
// Free an array created with my_str_to_array from memory
///\param tab Array to free
/////////////////////////////////////////
void my_free_array(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        free(tab[i]);
    }
    free(tab);
}
