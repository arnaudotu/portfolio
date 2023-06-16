/*
** EPITECH PROJECT, 2022
** my_strcat.c
** File description:
** adds src after dest on the same str
*/

#include "../../include/my.h"

/////////////////////////////////////////
// Adds a string after another on the same string
///\param dest String to modify
///\param src String to add after dest
/////////////////////////////////////////
void my_strcat(char *dest, char const *src)
{
    my_strcpy(dest + my_strlen(dest), src);
}
