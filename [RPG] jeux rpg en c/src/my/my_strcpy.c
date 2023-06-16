/*
** EPITECH PROJECT, 2022
** my_strcpy.c
** File description:
** copy src content to dest
*/

#include "../../include/my.h"

/////////////////////////////////////////
// Copy src content to dest
///\param dest String to modify
///\param src String to copy in dest
/////////////////////////////////////////
void my_strcpy(char *dest , char const *src)
{
    int len = 0;
    for (int i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
        len += 1;
    }
    dest[len] = '\0';
}
