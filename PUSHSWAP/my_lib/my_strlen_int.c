/*
** EPITECH PROJECT, 2022
** my_strlen_int.c
** File description:
** hreiuhrd
*/


#include "../include/my.h"

int my_strlen_int(int *nbr)
{
    int i = 0;
    while (nbr[i] != '\0') {
        i++;
    }
    return (i);
}
