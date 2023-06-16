/*
** EPITECH PROJECT, 2022
** my_put_str.c
** File description:
** returns the length of a str
*/

#include "../include/my.h"

int my_strlen(char *str)
{
    int n = 0;
    while (str[n] != '\0') {
        n++;
    }
    return (n);
}
