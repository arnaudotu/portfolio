/*
** EPITECH PROJECT, 2022
** my_put_char
** File description:
** writes an array on the terminal using sep as separator and end at the end
*/

#include "../include/my.h"

void my_put_array(char **tab, char *sep, char *end)
{
    for (int i = 0; tab[i] != NULL; i++){
        my_put_str(tab[i]);
        if (tab[i + 1] != NULL)
            my_put_str(sep);
    }
    my_put_str(end);
}
