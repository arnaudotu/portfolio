/*
** EPITECH PROJECT, 2022
** my_put_str.c
** File description:
** writes a str on the terminal
*/

#include "../include/my.h"

void my_put_str(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        my_put_char(str[i]);
    }
}
