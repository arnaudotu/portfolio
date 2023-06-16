/*
** EPITECH PROJECT, 2022
** my_str_to_int.c
** File description:
** turns char numbers into int
*/

#include "../include/my.h"

int my_str_to_int(char *str)
{
    int i = 0;
    int signe = 1;
    int res = 0;
    if (str[0] == '-') {
        signe = -1;
        i += 1;
    }
    while (str[i] != '\0' && (str[i] >= 48 && str[i] <= 57)) {
        res = res * 10 + (str[i] - 48);
        i++;
    }
    return (res * signe);
}
