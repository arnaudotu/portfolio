/*
** EPITECH PROJECT, 2022
** text_algo.c
** File description:
** algorithm of text compression
*/

#include "../include/giantman.h"

void text_algo(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] < 29 && str[i + 1] != '\0') {
            my_put_char(' ');
            my_put_char(str[i] + 94);
            i += 1;
        } else {
            my_put_char(str[i]);
            i++;
        }
    }
}
