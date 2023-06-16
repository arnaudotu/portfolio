/*
** EPITECH PROJECT, 2022
** my_free_array.c
** File description:
** returns int power n
*/

#include "../include/my.h"

int my_nbr_power(int n, int p)
{
    if (p == 0)
        return (1);
    if (p == 1)
        return (n);
    return (n * my_nbr_power(n, p - 1));
}
