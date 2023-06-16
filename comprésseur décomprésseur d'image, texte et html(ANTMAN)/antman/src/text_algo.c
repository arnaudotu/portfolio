/*
** EPITECH PROJECT, 2022
** text_algo.c
** File description:
** algorithm of text compression
*/

#include "../include/antman.h"

void text_algo(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == ' ' && (str[i + 1] != '\0' && str[i + 1] != ' ')) {
            my_put_char(str[i + 1] - 94);
            i += 2;
        } else {
            my_put_char(str[i]);
            i++;
        }
    }
}
