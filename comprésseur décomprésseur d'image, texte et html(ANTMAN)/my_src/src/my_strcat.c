/*
** EPITECH PROJECT, 2022
** my_put_str.c
** File description:
** adds src after dest on the same str
*/

#include "../include/my.h"

void my_strcat(char *dest, char const *src)
{
    if (src != NULL) {
        my_strcpy(dest + my_strlen(dest), src);
    }
}
