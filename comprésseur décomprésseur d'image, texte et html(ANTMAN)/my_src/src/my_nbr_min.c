/*
** EPITECH PROJECT, 2022
** my_free_array.c
** File description:
** returns minimal between a and b;
*/

#include "../include/my.h"

int my_nbr_min(int a, int b)
{
    if (a < b) {
        return (a);
    } else {
        return (b);
    }
}
